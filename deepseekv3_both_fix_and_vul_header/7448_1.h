#include <stddef.h>

struct fuse_inode;
struct fuse_backing;

extern struct fuse_backing *fuse_inode_backing(struct fuse_inode *fi);
extern struct fuse_backing *fuse_inode_backing_set(struct fuse_inode *fi, struct fuse_backing *fb);
extern void fuse_backing_put(struct fuse_backing *fb);

struct fuse_inode {
    int lock;
    int iocachectr;
};

#define EBUSY 16
#define ETXTBSY 26
#define WARN_ON_ONCE(cond) ((void)0)

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }