#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_NBD_REQUESTS 16
#define INDEX_TO_HANDLE(s, i) ((uint64_t)((s)->client_id) << 32 | (i))
#define EPIPE 32
#define EIO 5

typedef struct NBDClientSession {
    void *ioc;
    struct {
        int fd;
    } *sioc;
    struct {
        void *lock;
    } send_mutex;
    void *send_coroutine;
    void *recv_coroutine[MAX_NBD_REQUESTS];
    uint32_t client_id;
} NBDClientSession;

typedef struct NBDRequest {
    uint64_t handle;
    uint32_t len;
} NBDRequest;

typedef struct QEMUIOVector {
    void *iov;
    int niov;
} QEMUIOVector;

typedef struct BlockDriverState {
    // minimal definition
} BlockDriverState;

typedef struct AioContext {
    // minimal definition
} AioContext;

static void nbd_reply_ready(void *opaque) {}
static void nbd_restart_write(void *opaque) {}

static void qemu_co_mutex_lock(void *mutex) {}
static void qemu_co_mutex_unlock(void *mutex) {}
static void *qemu_coroutine_self(void) { return NULL; }
static int qemu_in_coroutine(void) { return 1; }
static void aio_set_fd_handler(void *ctx, int fd, bool b, 
                             void *ready, void *write, void *ex, void *opaque) {}
static void qio_channel_set_cork(void *ioc, bool cork) {}
static int nbd_send_request(void *ioc, NBDRequest *req) { return 0; }
static int nbd_wr_syncv(void *ioc, void *iov, int niov, uint32_t len, bool b) { return 0; }
static NBDClientSession *nbd_get_client_session(BlockDriverState *bs) { return NULL; }
static void *bdrv_get_aio_context(BlockDriverState *bs) { return NULL; }

#define g_assert(expr) assert(expr)