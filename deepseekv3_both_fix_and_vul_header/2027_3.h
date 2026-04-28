#include <stddef.h>
#include <sys/types.h>

typedef unsigned int fmode_t;

struct dm_target {
    unsigned long len;
    void *private;
};

struct multipath;
struct block_device;
struct inode;
struct device;

struct multipath {
    unsigned long lock;
    struct pgpath *current_pgpath;
    int queue_io;
};

struct pgpath {
    struct path {
        struct device *dev;
        fmode_t mode;
    } path;
};

struct device {
    struct block_device *bdev;
    fmode_t mode;
};

struct block_device {
    struct inode *bd_inode;
};

#define SECTOR_SHIFT 9
#define EAGAIN 11
#define EIO 5

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void __choose_pgpath(struct multipath *m, int arg) {}
static inline loff_t i_size_read(struct inode *inode) { return 0; }
static inline int scsi_verify_blk_ioctl(void *arg1, unsigned int cmd) { return 0; }
static inline int __blkdev_driver_ioctl(struct block_device *bdev, fmode_t mode, unsigned int cmd, unsigned long arg) { return 0; }