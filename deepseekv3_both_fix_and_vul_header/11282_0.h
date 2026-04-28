#include <stdint.h>

#define MAX_NBD_REQUESTS 16

typedef struct BlockDriverState BlockDriverState;
typedef struct NBDClientSession NBDClientSession;
typedef struct Coroutine Coroutine;

struct NBDClientSession {
    Coroutine *recv_coroutine[MAX_NBD_REQUESTS];
    int read_reply_co;
};

#define BDRV_POLL_WHILE(bs, cond) do { } while (cond)

static NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
void qemu_coroutine_enter(Coroutine *coroutine);