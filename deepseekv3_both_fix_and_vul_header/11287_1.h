#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct BlockDriverState BlockDriverState;

typedef struct NBDClientSession {
    int nbdflags;
} NBDClientSession;

typedef struct NBDRequest {
    int type;
    int64_t from;
    int len;
} NBDRequest;

typedef struct NBDReply {
    int error;
} NBDReply;

#define NBD_CMD_TRIM 1
#define NBD_FLAG_SEND_TRIM (1 << 0)

NBDClientSession* nbd_get_client_session(BlockDriverState* bs);
void nbd_coroutine_start(NBDClientSession* client, NBDRequest* request);
ssize_t nbd_co_send_request(BlockDriverState* bs, NBDRequest* request, void* opaque);
void nbd_co_receive_reply(NBDClientSession* client, NBDRequest* request, NBDReply* reply, void* opaque);
void nbd_coroutine_end(NBDClientSession* client, NBDRequest* request);