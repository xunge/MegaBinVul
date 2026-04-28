#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BLK_MAX_CDB 16
#define BLK_DEFAULT_SG_TIMEOUT (60 * 1000)
#define BLK_MIN_SG_TIMEOUT (5 * 1000)
#define HZ 1000

#define GFP_KERNEL 0
#define ENOMEM 12
#define EFAULT 14
#define EPERM 1
#define CAP_SYS_RAWIO 0

#define REQ_TYPE_BLOCK_PC 0
#define BSG_SUB_PROTOCOL_SCSI_CMD 0

struct request_queue {
    int sg_timeout;
    void *cmd_filter;
};

struct request {
    void *cmd;
    int cmd_len;
    int cmd_type;
    int timeout;
};

struct sg_io_v4 {
    unsigned long request;
    int request_len;
    int subprotocol;
    int timeout;
};

struct bsg_device {
};

typedef int fmode_t;

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static int blk_verify_command(void *filter, void *cmd, fmode_t perm) {
    return 0;
}

static int capable(int cap) {
    return 1;
}