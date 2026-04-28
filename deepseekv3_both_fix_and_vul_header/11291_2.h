#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef struct NBDClient NBDClient;
typedef struct NBDExport NBDExport;

struct NBDClient {
    void *ioc;
};

struct NBDExport {
    struct NBDExport *next;
};

#define NBD_REP_ERR_INVALID 0
#define NBD_REP_ACK 1
#define NBD_OPT_LIST 2
#define NBD_REP_SERVER 3

extern struct NBDExport *exports;

#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = *(head); (var) != NULL; (var) = (var)->field)

int nbd_negotiate_drop_sync(void *ioc, uint32_t length);
int nbd_negotiate_send_rep_err(void *ioc, int rep_err, int opt, const char *msg);
int nbd_negotiate_send_rep_list(void *ioc, NBDExport *exp);
int nbd_negotiate_send_rep(void *ioc, int rep, int opt);