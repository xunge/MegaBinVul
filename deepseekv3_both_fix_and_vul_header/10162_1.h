#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <syslog.h>

#define HEADER_LOCATION 0
#define HEADER_NT 1
#define HEADER_USN 2

struct reqelem {
    int socket;
};

struct device {
    time_t t;
    struct {
        const unsigned char *p;
        unsigned int l;
    } headers[3];
    struct device *next;
};

struct service {
    char *st;
    char *usn;
    char *server;
    char *location;
    struct {
        struct service *le_next;
    } entries;
};

#define LIST_INSERT_HEAD(head, elm, field) do { \
    (elm)->field.le_next = (head)->lh_first; \
    (head)->lh_first = (elm); \
} while (0)

extern struct device *devlist;
extern struct {
    struct service *lh_first;
} servicelisthead;

#define DECODELENGTH_CHECKLIMIT(l, p, limit) \
    do { \
        (l) = *(p)++; \
        if((l) & 0x80) { \
            (l) = ((l) & 0x7f) << 8; \
            (l) |= *(p)++; \
        } \
    } while(0)

#define CODELENGTH(l, p) \
    do { \
        if((l) < 0x80) { \
            *(p)++ = (l); \
        } else { \
            *(p)++ = (((l) >> 8) | 0x80); \
            *(p)++ = (l) & 0xff; \
        } \
    } while(0)

int containsForbiddenChars(const unsigned char *p, unsigned int l);