#include <stdlib.h>

typedef struct NBDClient NBDClient;
typedef struct NBDExport NBDExport;
typedef struct NBDClientNewData NBDClientNewData;

struct NBDClientNewData {
    NBDClient *client;
};

struct NBDClient {
    NBDExport *exp;
    struct {
        int lock;
    } send_lock;
    struct NBDClient *next;
};

struct NBDExport {
    struct NBDClient *clients;
};

#define coroutine_fn
#define QTAILQ_INSERT_TAIL(head, elm, field) \
    do { \
        (elm)->next = NULL; \
        if (*(head) == NULL) { \
            *(head) = (elm); \
        } else { \
            struct NBDClient *last = *(head); \
            while (last->next != NULL) { \
                last = last->next; \
            } \
            last->next = (elm); \
        } \
    } while (0)

#define qemu_co_mutex_init(mutex) ((mutex)->lock = 0)
#define g_free free

static inline void nbd_export_get(NBDExport *exp) {}
static int nbd_negotiate(NBDClientNewData *data) { return 0; }
static void client_close(NBDClient *client) {}
static void nbd_set_handlers(NBDClient *client) {}