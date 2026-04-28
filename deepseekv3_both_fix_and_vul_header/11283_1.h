#include <stddef.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct NBDClientSession NBDClientSession;
typedef struct QIOChannel QIOChannel;

struct NBDClientSession {
    QIOChannel *ioc;
    QIOChannel *sioc;
};

#define OBJECT(obj) ((void*)(obj))
#define QIO_CHANNEL_SHUTDOWN_BOTH 2

static NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
static void nbd_recv_coroutines_enter_all(NBDClientSession *client);
static void nbd_client_detach_aio_context(BlockDriverState *bs);
static void qio_channel_shutdown(QIOChannel *ioc, int how, void *errp);
static void object_unref(void *obj);