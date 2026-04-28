#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct QIOChannelSocket QIOChannelSocket;
typedef struct QCryptoTLSCreds QCryptoTLSCreds;
typedef struct Error Error;
typedef struct NBDClientSession NBDClientSession;
typedef struct QIOChannel QIOChannel;
typedef struct Object Object;

#define NBD_FLAG_SEND_FUA (1 << 0)
#define NBD_FLAG_SEND_WRITE_ZEROES (1 << 1)
#define BDRV_REQ_FUA (1 << 0)
#define BDRV_REQ_MAY_UNMAP (1 << 1)

struct NBDClientSession {
    unsigned int nbdflags;
    QIOChannel *ioc;
    uint64_t size;
    QIOChannelSocket *sioc;
    void *read_reply_co;
    void *send_mutex;
    void *free_sema;
};

struct BlockDriverState {
    unsigned int supported_write_flags;
    unsigned int supported_zero_flags;
};

#define QIO_CHANNEL(obj) ((QIOChannel *)(obj))
#define OBJECT(obj) ((Object *)(obj))

void logout(const char *fmt, ...);
int nbd_receive_negotiate(QIOChannel *ioc, const char *export, unsigned int *nbdflags,
                         QCryptoTLSCreds *tlscreds, const char *hostname,
                         QIOChannel **outioc, uint64_t *size, Error **errp);
NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
void qio_channel_set_blocking(QIOChannel *ioc, bool blocking, Error **errp);
void qemu_co_mutex_init(void *mutex);
void qemu_co_queue_init(void *queue);
void *qemu_coroutine_create(void (*entry)(void *), void *opaque);
void nbd_client_attach_aio_context(BlockDriverState *bs, void *aio_context);
void *bdrv_get_aio_context(BlockDriverState *bs);
void object_ref(Object *obj);
void nbd_read_reply_entry(void *opaque);