#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct QEMUIOVector QEMUIOVector;

#define NBD_MAX_BUFFER_SIZE (32 * 1024 * 1024)
#define BDRV_REQ_FUA (1 << 0)

typedef enum {
    NBD_CMD_WRITE = 1,
} NBDCmdType;

typedef enum {
    NBD_FLAG_SEND_FUA = (1 << 3),
    NBD_CMD_FLAG_FUA = (1 << 0),
} NBDFlags;

typedef struct NBDRequest {
    NBDCmdType type;
    uint64_t from;
    uint64_t len;
    uint32_t flags;
} NBDRequest;

typedef struct NBDReply {
    int error;
} NBDReply;

typedef struct NBDClientSession {
    uint32_t nbdflags;
} NBDClientSession;

NBDClientSession *nbd_get_client_session(BlockDriverState *bs);
void nbd_coroutine_start(NBDClientSession *client, NBDRequest *request);
ssize_t nbd_co_send_request(BlockDriverState *bs, NBDRequest *request, QEMUIOVector *qiov);
void nbd_co_receive_reply(NBDClientSession *client, NBDRequest *request, NBDReply *reply, void *opaque);
void nbd_coroutine_end(NBDClientSession *client, NBDRequest *request);