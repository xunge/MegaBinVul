#include <stddef.h>
#include <sys/types.h>

typedef struct BlockDriverState BlockDriverState;

struct NBDClientSession {
    unsigned int nbdflags;
};

struct NBDRequest {
    int type;
    unsigned long from;
    unsigned long len;
};

struct NBDReply {
    int error;
};

#define NBD_CMD_FLUSH 3
#define NBD_FLAG_SEND_FLUSH (1 << 0)

struct NBDClientSession *nbd_get_client_session(struct BlockDriverState *bs);
void nbd_coroutine_start(struct NBDClientSession *client, struct NBDRequest *request);
ssize_t nbd_co_send_request(struct BlockDriverState *bs, struct NBDRequest *request, void *arg);
void nbd_co_receive_reply(struct NBDClientSession *client, struct NBDRequest *request, struct NBDReply *reply, void *arg);
void nbd_coroutine_end(struct NBDClientSession *client, struct NBDRequest *request);

typedef struct NBDClientSession NBDClientSession;
typedef struct NBDRequest NBDRequest;
typedef struct NBDReply NBDReply;