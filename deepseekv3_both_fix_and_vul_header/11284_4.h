#include <stdbool.h>
#include <stddef.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct AioContext AioContext;
typedef struct QIOChannel {
    int fd;
} QIOChannel;
typedef struct NBDClientSession NBDClientSession;
typedef void (*IOHandler)(void *opaque);

struct NBDClientSession {
    QIOChannel *sioc;
    void *read_reply_co;
};

NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
void qio_channel_attach_aio_context(QIOChannel *ioc, AioContext *ctx);
void aio_co_schedule(AioContext *ctx, void *co);
void aio_set_fd_handler(AioContext *ctx, int fd, bool is_external,
                       IOHandler io_read, IOHandler io_write,
                       void *opaque, void *bs);
void nbd_reply_ready(void *opaque);

#define QIO_CHANNEL(x) (x)