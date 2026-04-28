#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

#define coroutine_fn
#define TRACE(fmt, ...)
#define LOG(fmt, ...)

typedef struct NBDRequest NBDRequest;
typedef struct NBDReply NBDReply;
typedef struct NBDClient NBDClient;
typedef struct NBDExport NBDExport;
typedef struct NBDRequestData NBDRequestData;
typedef struct BlockBackend BlockBackend;

struct NBDRequest {
    uint32_t type;
    uint32_t flags;
    uint64_t handle;
    uint64_t from;
    uint32_t len;
};

struct NBDReply {
    uint64_t handle;
    uint32_t error;
};

struct NBDClient {
    struct NBDExport *exp;
    bool closing;
};

struct NBDExport {
    struct BlockBackend *blk;
    uint32_t nbdflags;
    uint64_t dev_offset;
};

struct NBDRequestData {
    void *data;
    bool complete;
};

#define NBD_CMD_READ 0
#define NBD_CMD_WRITE 1
#define NBD_CMD_DISC 2
#define NBD_CMD_FLUSH 3
#define NBD_CMD_TRIM 4
#define NBD_CMD_WRITE 5
#define NBD_CMD_WRITE_ZEROES 6

#define NBD_CMD_FLAG_FUA (1 << 0)
#define NBD_CMD_FLAG_NO_HOLE (1 << 1)

#define NBD_FLAG_READ_ONLY (1 << 0)

#define BDRV_REQ_FUA (1 << 0)
#define BDRV_REQ_MAY_UNMAP (1 << 1)

#define EROFS 30
#define EINVAL 22
#define EAGAIN 11
#define EIO 5

static void nbd_client_put(struct NBDClient *client);
static void nbd_request_put(struct NBDRequestData *req);
static void client_close(struct NBDClient *client);
static struct NBDRequestData *nbd_request_get(struct NBDClient *client);
static ssize_t nbd_co_receive_request(struct NBDRequestData *req, struct NBDRequest *request);
static int nbd_co_send_reply(struct NBDRequestData *req, struct NBDReply *reply, uint32_t len);
static int blk_co_flush(struct BlockBackend *blk);
static ssize_t blk_pread(struct BlockBackend *blk, uint64_t offset, void *buf, uint32_t len);
static ssize_t blk_pwrite(struct BlockBackend *blk, uint64_t offset, const void *buf, uint32_t len, int flags);
static ssize_t blk_pwrite_zeroes(struct BlockBackend *blk, uint64_t offset, uint32_t len, int flags);
static ssize_t blk_co_pdiscard(struct BlockBackend *blk, uint64_t offset, uint32_t len);