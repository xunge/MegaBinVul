#include <stddef.h>
#include <stdint.h>

typedef int64_t loff_t;

struct p9_fid;
struct inode {
    unsigned int i_mode;
    loff_t i_size;
    void *i_lock;
};
struct v9fs_session_info {
    unsigned int cache;
};
struct p9_stat_dotl {
    unsigned int st_mode;
};

#define S_IFMT  00170000
#define CACHE_LOOSE 0
#define CACHE_FSCACHE 1
#define P9_STATS_ALL 0x7ff
#define V9FS_STAT2INODE_KEEP_ISIZE 0x01

static inline struct v9fs_session_info *v9fs_inode2v9ses(struct inode *inode) { return NULL; }
static inline struct p9_stat_dotl *p9_client_getattr_dotl(struct p9_fid *fid, int mask) { return NULL; }
static inline void v9fs_stat2inode_dotl(struct p9_stat_dotl *st, struct inode *inode, ...) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void kfree(void *ptr) {}
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)