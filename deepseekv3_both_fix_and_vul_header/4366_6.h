#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#define EINVAL 22
#define ENOMEM 12
#define MS_MANDLOCK (1 << 0)
#define MS_NOSEC (1 << 1)
#define MS_I_VERSION (1 << 2)
#define MS_POSIXACL (1 << 3)
#define PAGE_CACHE_SIZE 4096
#define PAGE_CACHE_SHIFT 12
#define FUSE_SUPER_MAGIC 0x65735546
#define MAX_LFS_FILESIZE ((1UL << 63) - 1)
#define GFP_KERNEL 0
#define FR_BACKGROUND 0

struct super_block {
    void *s_bdev;
    unsigned long s_flags;
    unsigned long s_blocksize;
    unsigned long s_blocksize_bits;
    unsigned long s_magic;
    void *s_op;
    unsigned long s_maxbytes;
    int s_time_gran;
    void *s_export_op;
    void *s_bdi;
    void *s_fs_info;
    void *s_root;
    void *s_d_op;
    dev_t s_dev;
};

struct inode {
    // minimal inode structure
};

struct file {
    void *f_op;
    struct {
        void *user_ns;
    } *f_cred;
    void *private_data;
    int fd;
};

struct dentry {
    // minimal dentry structure
};

struct fuse_mount_data {
    int fd;
    unsigned rootmode;
    unsigned user_id;
    unsigned group_id;
    unsigned flags;
    unsigned max_read;
    unsigned blksize;
};

struct fuse_req {
    unsigned long flags;
};

struct fuse_conn {
    void *bdi;
    dev_t dev;
    struct super_block *sb;
    void (*release)(struct fuse_conn *);
    unsigned flags;
    unsigned user_id;
    unsigned group_id;
    unsigned max_read;
    int dont_mask;
    struct fuse_req *destroy_req;
    struct {
        void *next;
        void *prev;
    } entry;
};

struct fuse_super_operations {
    // dummy structure
} fuse_super_operations;

struct fuse_export_operations {
    // dummy structure
} fuse_export_operations;

struct fuse_dev_operations {
    // dummy structure
} fuse_dev_operations;

struct fuse_dentry_operations {
    // dummy structure
} fuse_dentry_operations;

struct user_namespace {
    // minimal structure
} init_user_ns;

static pthread_mutex_t fuse_mutex = PTHREAD_MUTEX_INITIALIZER;
static struct {
    void *next;
    void *prev;
} fuse_conn_list;

static inline unsigned max_t(unsigned a, unsigned b) {
    return (a > b) ? a : b;
}

static inline int parse_fuse_opt(void *data, struct fuse_mount_data *d, int is_bdev) {
    return 1;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void fuse_conn_init(struct fuse_conn *fc) {}
static inline int fuse_bdi_init(struct fuse_conn *fc, struct super_block *sb) { return 0; }
static inline void *fuse_get_root_inode(struct super_block *sb, unsigned rootmode) { return NULL; }
static inline void *d_make_root(void *root) { return NULL; }
static inline void *fuse_request_alloc(int flags) { return NULL; }
static inline void __set_bit(int nr, volatile void *addr) {}
static inline void mutex_lock(pthread_mutex_t *mutex) {}
static inline int fuse_ctl_add_conn(struct fuse_conn *fc) { return 0; }
static inline void list_add_tail(void *entry, void *head) {}
static inline void *fuse_conn_get(struct fuse_conn *fc) { return NULL; }
static inline void mutex_unlock(pthread_mutex_t *mutex) {}
static inline void fput(struct file *file) {}
static inline void fuse_send_init(struct fuse_conn *fc, struct fuse_req *req) {}
static inline void fuse_request_free(struct fuse_req *req) {}
static inline void dput(struct dentry *dentry) {}
static inline void fuse_bdi_destroy(struct fuse_conn *fc) {}
static inline void fuse_conn_put(struct fuse_conn *fc) {}
static inline struct file *fget(int fd) { return NULL; }
static inline void fuse_free_conn(struct fuse_conn *fc) {}

#define max_t(type, x, y) ((type)(x) > (type)(y) ? (type)(x) : (type)(y))