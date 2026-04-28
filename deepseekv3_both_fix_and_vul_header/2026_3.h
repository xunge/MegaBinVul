#include <stddef.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

struct dm_target {
    void *private;
    unsigned long len;
};

struct dm_dev {
    struct block_device *bdev;
    mode_t mode;
};

struct block_device {
    struct inode *bd_inode;
};

struct inode;

struct flakey_c {
    struct dm_dev *dev;
    unsigned long start;
};

#define SECTOR_SHIFT 9

int scsi_verify_blk_ioctl(void *null, unsigned int cmd);
int __blkdev_driver_ioctl(struct block_device *bdev, mode_t mode, unsigned int cmd, unsigned long arg);
unsigned long i_size_read(struct inode *inode);