#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>

struct file;
struct address_space;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct mutex {
    int dummy;
};

struct rw_semaphore {
    int dummy;
};

struct inode {
    unsigned int i_blkbits;
    struct mutex i_mutex;
    struct rw_semaphore i_alloc_sem;
};

struct file {
    struct address_space *f_mapping;
};

struct kiocb {
    struct file *ki_filp;
};

struct block_device {
    int dummy;
};

struct dio {
    int lock_type;
    int is_async;
};

typedef int (get_block_t)(struct inode *inode, long iblock, void *bh, int create);
typedef void (dio_iodone_t)(struct kiocb *iocb, long offset, ssize_t bytes, void *private);

#define WRITE 0
#define WRITE_SYNC 1
#define READ 2
#define DIO_NO_LOCKING 0
#define DIO_LOCKING 1
#define DIO_OWN_LOCKING 2

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void down_read_non_owner(struct rw_semaphore *sem);

extern ssize_t direct_io_worker(int rw, struct kiocb *iocb, struct inode *inode,
    const struct iovec *iov, long offset, unsigned long nr_segs,
    unsigned blkbits, get_block_t get_block, dio_iodone_t end_io,
    struct dio *dio);
extern int filemap_write_and_wait_range(struct address_space *mapping,
    long lstart, long lend);
extern long i_size_read(struct inode *inode);
extern int is_sync_kiocb(struct kiocb *iocb);
extern unsigned blksize_bits(unsigned size);
extern unsigned bdev_hardsect_size(struct block_device *bdev);
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);