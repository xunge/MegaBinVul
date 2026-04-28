#include <sys/types.h>
#include <stdint.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef uint32_t u32;

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
    struct super_block *d_sb;
};

struct inode;
struct super_block;
struct kstat;

struct v9fs_session_info {
    int cache;
};

struct p9_fid;
struct p9_wstat;

#define P9_DEBUG_VFS 0
#define CACHE_LOOSE 0
#define CACHE_FSCACHE 0
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline struct inode *d_inode(const struct dentry *dentry) {
    return dentry->d_inode;
}

void p9_debug(int level, const char *fmt, ...);
struct v9fs_session_info *v9fs_dentry2v9ses(struct dentry *dentry);
void generic_fillattr(struct inode *inode, struct kstat *stat);
struct p9_fid *v9fs_fid_lookup(struct dentry *dentry);
struct p9_wstat *p9_client_stat(struct p9_fid *fid);
void v9fs_stat2inode(struct p9_wstat *stat, struct inode *inode, struct super_block *sb, ...);
void p9stat_free(struct p9_wstat *st);