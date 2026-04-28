#include <stddef.h>
#include <sys/types.h>
#include <sys/ioctl.h>

struct dm_target {
    void *private;
    unsigned long len;
};

struct linear_c {
    struct dm_dev *dev;
    unsigned long start;
};

struct dm_dev {
    struct block_device *bdev;
    int mode;
};

struct block_device {
    struct inode *bd_inode;
};

struct inode {
    unsigned long i_size;
};

#define SECTOR_SHIFT 9

static inline unsigned long i_size_read(struct inode *inode) {
    return inode->i_size;
}

static int scsi_verify_blk_ioctl(void *arg1, unsigned int cmd) {
    return 0;
}

static int __blkdev_driver_ioctl(struct block_device *bdev, int mode, 
                                unsigned int cmd, unsigned long arg) {
    return 0;
}