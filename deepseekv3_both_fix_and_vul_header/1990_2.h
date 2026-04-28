#include <stdint.h>
#include <string.h>

#define BDRV_SECTOR_SIZE 512
#define EIO 5

typedef struct VirtIOBlockReq VirtIOBlockReq;
typedef struct MultiReqBuffer MultiReqBuffer;
typedef struct BlockRequest BlockRequest;
typedef struct QEMUIOVector QEMUIOVector;
typedef struct VirtIOBlockDev VirtIOBlockDev;
typedef struct VirtIOBlockConf VirtIOBlockConf;

struct QEMUIOVector {
    size_t size;
};

struct VirtIOBlockConf {
    uint32_t logical_block_size;
};

struct VirtIOBlockDev {
    void *bs;
    uint64_t sector_mask;
    VirtIOBlockConf *conf;
};

struct VirtIOBlockReq {
    struct {
        uint64_t sector;
    } *out;
    QEMUIOVector qiov;
    VirtIOBlockDev *dev;
};

struct BlockRequest {
    uint64_t sector;
    uint32_t nb_sectors;
    QEMUIOVector *qiov;
    void (*cb)(void *, int);
    void *opaque;
    int error;
};

struct MultiReqBuffer {
    BlockRequest blkreq[32];
    int num_writes;
};

static inline uint64_t ldq_p(const void *p) {
    uint64_t val;
    memcpy(&val, p, sizeof(val));
    return val;
}

static void virtio_blk_rw_complete(void *opaque, int ret) {}
static void virtio_submit_multiwrite(void *bs, MultiReqBuffer *mrb) {}
static void trace_virtio_blk_handle_write(VirtIOBlockReq *req, uint64_t sector, unsigned count) {}