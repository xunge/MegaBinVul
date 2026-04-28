#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct NBDClientSession NBDClientSession;
typedef struct QIOChannelSocket QIOChannelSocket;

struct NBDClientSession {
    QIOChannelSocket *sioc;
};

struct QIOChannelSocket {
    int fd;
};

typedef struct AioContext AioContext;
typedef void (*IOHandler)(void *opaque);
typedef void (*AIOHandler)(void *opaque);

AioContext *bdrv_get_aio_context(BlockDriverState *bs);
NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
void aio_set_fd_handler(AioContext *ctx, int fd, bool is_external,
                        IOHandler io_read, IOHandler io_write,
                        AIOHandler io_poll, void *opaque);