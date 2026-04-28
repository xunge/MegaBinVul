#include <stdint.h>
#include <stddef.h>

typedef struct VirtIOBlockReq VirtIOBlockReq;
typedef struct BlockDriverAIOCB BlockDriverAIOCB;

struct VirtIOBlockReq {
    struct {
        uint64_t sector;
    } *out;
    struct {
        size_t size;
    } qiov;
    struct {
        struct {
            unsigned int logical_block_size;
        } *conf;
        unsigned int sector_mask;
        void *bs;
    } *dev;
};

#define BDRV_SECTOR_SIZE 512
extern int EIO;
extern uint64_t ldq_p(const uint64_t *ptr);
extern BlockDriverAIOCB* bdrv_aio_readv(void *bs, uint64_t sector, void *qiov, int n, void (*cb)(VirtIOBlockReq*, int), VirtIOBlockReq *req);
extern void virtio_blk_rw_complete(VirtIOBlockReq *req, int status);