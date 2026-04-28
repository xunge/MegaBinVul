#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct QEMUIOVector QEMUIOVector;
typedef struct NBDClientSession NBDClientSession;
typedef struct NBDRequest NBDRequest;
typedef struct NBDReply NBDReply;

#define NBD_MAX_BUFFER_SIZE (4 * 1024 * 1024)

enum {
    NBD_CMD_READ = 0
};

struct NBDRequest {
    uint32_t type;
    uint64_t from;
    uint64_t len;
};

struct NBDReply {
    int error;
};

NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
void nbd_coroutine_start(NBDClientSession *client, NBDRequest *request);
ssize_t nbd_co_send_request(BlockDriverState *bs, NBDRequest *request, void *opaque);
void nbd_co_receive_reply(NBDClientSession *client, NBDRequest *request, NBDReply *reply, QEMUIOVector *qiov);
void nbd_coroutine_end(NBDClientSession *client, NBDRequest *request);