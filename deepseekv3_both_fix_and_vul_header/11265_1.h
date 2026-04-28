#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define NBD_MAX_BUFFER_SIZE (16 * 1024 * 1024)

#define NBD_CMD_READ 0
#define NBD_CMD_WRITE 1
#define NBD_CMD_DISC 2
#define NBD_CMD_WRITE_ZEROES 6

#define NBD_CMD_FLAG_FUA (1 << 0)
#define NBD_CMD_FLAG_NO_HOLE (1 << 1)

typedef struct NBDClient NBDClient;
typedef struct NBDRequestData NBDRequestData;
typedef struct NBDRequest NBDRequest;
typedef struct NBDExport NBDExport;

struct NBDRequest {
    uint32_t type;
    uint32_t flags;
    uint64_t from;
    uint32_t len;
};

struct NBDRequestData {
    NBDClient *client;
    bool complete;
    void *data;
};

struct NBDExport {
    uint64_t size;
    void *blk;
};

struct NBDClient {
    void *ioc;
    NBDExport *exp;
    void *recv_coroutine;
};

#define TRACE(fmt, ...)
#define LOG(fmt, ...)
#define g_assert(expr)
#define qemu_in_coroutine() (1)
#define qemu_coroutine_self() (NULL)
#define nbd_update_can_read(client)
#define nbd_receive_request(ioc, request) (0)
#define read_sync(ioc, buf, len) (0)
#define blk_try_blockalign(blk, len) (malloc(len))