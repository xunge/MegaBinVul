#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <syslog.h>

#define RESPONSE_BUFFER_SIZE 2048
#define MINISSDPD_SEARCH_ALL 0
#define MINISSDPD_GET_VERSION 1
#define MINISSDPD_NOTIF 2
#define MINISSDPD_SEARCH_TYPE 3
#define MINISSDPD_SEARCH_USN 4
#define MINISSDPD_SUBMIT 5
#define NOTIF_NEW 0
#define MINISSDPD_VERSION "MiniSSDPD/1.0"

#define HEADER_LOCATION 0
#define HEADER_NT 1
#define HEADER_USN 2

enum request_type {
    MINISSDPD_REQ_UNKNOWN,
    MINISSDPD_REQ_SEARCH,
    MINISSDPD_REQ_NOTIFY
};

struct reqelem {
    int socket;
    int is_notify;
};

struct device {
    time_t t;
    struct {
        unsigned char *p;
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
        struct service *le_prev;
    } entries;
};

#define LIST_INSERT_HEAD(head, elm, field) do { \
    (elm)->field.le_next = (head)->lh_first; \
    if ((head)->lh_first != NULL) \
        (head)->lh_first->field.le_prev = (elm); \
    (head)->lh_first = (elm); \
    (elm)->field.le_prev = NULL; \
} while (0)

#define DECODELENGTH_CHECKLIMIT(len, p, limit) do { \
    (len) = *(p)++; \
    if ((len) & 0x80) { \
        (len) &= 0x7f; \
        (len) = (*(p)++ << 8) | (len); \
    } \
    if ((p) + (len) > (limit)) { \
        (len) = 0; \
    } \
} while (0)

#define CODELENGTH(len, p) do { \
    if ((len) < 0x80) { \
        *(p)++ = (len); \
    } else { \
        *(p)++ = 0x80 | ((len) & 0x7f); \
        *(p)++ = ((len) >> 8); \
    } \
} while (0)

extern struct device *devlist;
extern struct {
    struct service *lh_first;
} servicelisthead;

extern ssize_t write_or_buffer(struct reqelem *req, const void *buf, size_t n);
extern int containsForbiddenChars(const unsigned char *p, unsigned int l);
extern void sendNotifications(int type, struct device *d, struct service *serv);