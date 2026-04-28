#include <stdint.h>
#include <assert.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct BlockDriverState BlockDriverState;

typedef struct NBDClientSession {
    uint32_t nbdflags;
} NBDClientSession;

typedef struct NBDRequest {
    uint32_t type;
    uint64_t from;
    uint32_t len;
    uint32_t flags;
} NBDRequest;

typedef struct NBDReply {
    int error;
} NBDReply;

enum {
    NBD_CMD_WRITE_ZEROES,
    NBD_FLAG_SEND_WRITE_ZEROES,
    NBD_FLAG_SEND_FUA,
    NBD_CMD_FLAG_FUA,
    NBD_CMD_FLAG_NO_HOLE
};

typedef enum {
    BDRV_REQ_FUA = (1 << 0),
    BDRV_REQ_MAY_UNMAP = (1 << 1)
} BdrvRequestFlags;

#define ENOTSUP 95

NBDClientSession* nbd_get_client_session(BlockDriverState *bs);
void nbd_coroutine_start(NBDClientSession *client, NBDRequest *request);
ssize_t nbd_co_send_request(BlockDriverState *bs, NBDRequest *request, void *arg);
void nbd_co_receive_reply(NBDClientSession *client, NBDRequest *request, NBDReply *reply, void *arg);
void nbd_coroutine_end(NBDClientSession *client, NBDRequest *request);