#include <stdint.h>
#include <stdio.h>

#define DRV_PFX ""
#define BLKIF_RSP_OKAY 0
#define BLKIF_RSP_EOPNOTSUPP (-1)
#define BLKIF_RSP_ERROR (-2)
#define BLKIF_DISCARD_SECURE (1 << 0)
#define BLKDEV_DISCARD_SECURE (1 << 0)
#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define WRITE 1

typedef uint64_t sector_t;
typedef unsigned int gfp_t;

struct block_device;

struct phys_req {
    sector_t sector_number;
    unsigned long nr_sects;
};

struct vbd {
    struct block_device *bdev;
    unsigned int pdevice;
    int discard_secure;
};

struct xen_blkif {
    struct vbd vbd;
    unsigned int st_ds_req;
};

struct blkif_request_discard {
    uint64_t sector_number;
    uint64_t nr_sectors;
    uint8_t flag;
    uint64_t id;
};

struct blkif_request {
    union {
        struct blkif_request_discard discard;
    } u;
    uint8_t operation;
};

int xen_vbd_translate(struct phys_req *preq, struct xen_blkif *blkif, int write);
void xen_blkif_get(struct xen_blkif *blkif);
void xen_blkif_put(struct xen_blkif *blkif);
int blkdev_issue_discard(struct block_device *bdev, sector_t sector, sector_t nr_sects, gfp_t gfp_mask, unsigned long flags);
void make_response(struct xen_blkif *blkif, uint64_t id, uint8_t operation, int status);