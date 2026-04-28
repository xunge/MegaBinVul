#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

struct pipe_inode_info;

struct file_operations {
    long (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
};

struct file {
    const struct file_operations *f_op;
    unsigned int f_mode;
    unsigned int f_flags;
};

#define FMODE_WRITE 0x2
#define WRITE 1
#define EINVAL 22
#define EBADF 9

#define unlikely(x) __builtin_expect(!!(x), 0)

typedef off_t loff_t;

long rw_verify_area(int type, struct file *file, loff_t *ppos, size_t count);