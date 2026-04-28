#include <stdint.h>
#include <sys/types.h>

typedef uint32_t u32;

struct path {
    struct dentry *dentry;
};

struct dentry;
struct inode;

struct v9fs_session_info {
    int cache;
};

struct kstat {
    unsigned long blksize;
};

struct p9_stat_dotl {
    unsigned long st_blksize;
};

struct p9_fid;

#define P9_DEBUG_VFS 0
#define CACHE_LOOSE 0
#define CACHE_FSCACHE 0
#define P9_STATS_ALL 0

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

void p9_debug(int level, const char *fmt, ...);
struct v9fs_session_info *v9fs_dentry2v9ses(struct dentry *dentry);
void generic_fillattr(struct inode *inode, struct kstat *stat);
struct p9_fid *v9fs_fid_lookup(struct dentry *dentry);
struct p9_stat_dotl *p9_client_getattr_dotl(struct p9_fid *fid, int mask);
void v9fs_stat2inode_dotl(struct p9_stat_dotl *stat, struct inode *inode, ...);
void kfree(void *ptr);
struct inode *d_inode(struct dentry *dentry);