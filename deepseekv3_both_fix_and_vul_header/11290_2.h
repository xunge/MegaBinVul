#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define NBD_MAX_NAME_SIZE 256
#define EINVAL 22

typedef struct NBDClient NBDClient;
typedef struct NBDExport NBDExport;

struct NBDClient {
    NBDExport *exp;
    void *ioc;
    NBDClient *next;
};

struct NBDExport {
    struct {
        NBDClient *tqh_first;
        NBDClient **tqh_last;
    } clients;
};

#define TRACE(fmt, ...)
#define LOG(fmt, ...)

static NBDExport *nbd_export_find(const char *name);
static int nbd_read(void *ioc, char *buf, uint32_t len, void *unused);
static void nbd_export_get(NBDExport *exp);

#define QTAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field = NULL; \
    *(head)->tqh_last = (elm); \
    (head)->tqh_last = &(elm)->field; \
} while (0)