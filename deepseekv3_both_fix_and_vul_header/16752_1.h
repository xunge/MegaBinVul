#include <pthread.h>

#define EIO 5
#define UNCACHED -1
#define FOPEN_CACHE_DIR 0x1

struct file {
    void *private_data;
    void *f_inode;
};

struct dir_context;
struct fuse_file {
    unsigned int open_flags;
    struct {
        pthread_mutex_t lock;
    } readdir;
};

struct inode;

static inline struct inode *file_inode(const struct file *f) { return (struct inode *)f->f_inode; }
static inline int is_bad_inode(struct inode *inode) { return 0; }
static inline void mutex_lock(pthread_mutex_t *lock) { pthread_mutex_lock(lock); }
static inline void mutex_unlock(pthread_mutex_t *lock) { pthread_mutex_unlock(lock); }

int fuse_readdir_cached(struct file *file, struct dir_context *ctx);
int fuse_readdir_uncached(struct file *file, struct dir_context *ctx);