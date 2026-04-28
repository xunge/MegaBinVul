#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

struct p9_fid;
struct p9_wstat;
struct v9fs_session_info {
    int cache;
};
struct inode {
    unsigned int i_mode;
    loff_t i_size;
    void *i_sb;
    int i_lock;
};
struct super_block;

#define CACHE_LOOSE 0
#define CACHE_FSCACHE 1
#define V9FS_STAT2INODE_KEEP_ISIZE 0
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}

extern struct v9fs_session_info *v9fs_inode2v9ses(struct inode *inode);
extern struct p9_wstat *p9_client_stat(struct p9_fid *fid);
extern int p9mode2unixmode(struct v9fs_session_info *v9ses, struct p9_wstat *st, dev_t *rdev);
extern void v9fs_stat2inode(struct p9_wstat *st, struct inode *inode, struct super_block *sb, ...);
extern void p9stat_free(struct p9_wstat *st);
extern void kfree(void *ptr);