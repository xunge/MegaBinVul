#include <stddef.h>

#define MAX_NBD_REQUESTS 16

typedef struct BlockDriverState BlockDriverState;

typedef struct NBDRequest {
    int handle;
} NBDRequest;

typedef struct CoQueue {
    // Minimal definition for compilation
    void *data;
} CoQueue;

typedef struct NBDClientSession {
    void *recv_coroutine[MAX_NBD_REQUESTS];
    int in_flight;
    CoQueue free_sema;
    void *read_reply_co;
} NBDClientSession;

#define HANDLE_TO_INDEX(s, handle) ((handle) % MAX_NBD_REQUESTS)

void qemu_co_queue_next(CoQueue *queue);
void aio_co_wake(void *co);
NBDClientSession *nbd_get_client_session(BlockDriverState *bs);