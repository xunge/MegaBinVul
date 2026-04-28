#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct inode;
struct file;

struct fuse_dev;
struct fuse_conn;

struct fuse_conn {
    struct {
        struct list_head io;
    } pq;
    struct {
        void *fasync;
    } iq;
};

struct fuse_dev {
    struct fuse_conn *fc;
};

#define WARN_ON(condition) ((void)(condition))

static inline struct fuse_dev *fuse_get_dev(struct file *file) { return NULL; }
static inline void fuse_abort_conn(struct fuse_conn *fc) {}
static inline void fuse_dev_free(struct fuse_dev *fud) {}