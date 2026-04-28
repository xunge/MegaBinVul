#include <stddef.h>
#include <limits.h>
#include <linux/types.h>

typedef __kernel_loff_t loff_t;

#define FALLOC_FL_KEEP_SIZE 0x01
#define EOPNOTSUPP 95
#define ENOMEM 12  
#define ENOSPC 28
#define PAGE_CACHE_SIZE 4096
#define RES_DINODE 0
#define RES_STATFS 0  
#define RES_QUOTA 0
#define RES_RG_HDR 0
#define LM_ST_EXCLUSIVE 0

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
};

struct dentry {
    struct inode *d_inode;
};

struct inode;

struct gfs2_sbd {
    struct {
        unsigned int sb_bsize_shift;
        unsigned int sb_bsize;
    } sd_sb;
    unsigned int sd_max_rg_data;
};

struct gfs2_holder {
    int dummy;
};

struct gfs2_inode {
    void *i_gl;
    struct gfs2_holder i_gh;
};

struct gfs2_alloc {
    unsigned int al_requested;
};

#define GFS2_SB(inode) ((struct gfs2_sbd *)0)
#define GFS2_I(inode) ((struct gfs2_inode *)0)

static inline int unlikely(int x) { return x; }

static inline void gfs2_holder_init(void *gl, int state, int flags, struct gfs2_holder *gh) {}
static inline int gfs2_glock_nq(struct gfs2_holder *gh) { return 0; }
static inline void gfs2_glock_dq(struct gfs2_holder *gh) {}
static inline void gfs2_holder_uninit(struct gfs2_holder *gh) {}
static inline int gfs2_write_alloc_required(struct gfs2_inode *ip, loff_t offset, loff_t len) { return 0; }
static inline struct gfs2_alloc *gfs2_alloc_get(struct gfs2_inode *ip) { return (struct gfs2_alloc *)ip; }
static inline void gfs2_alloc_put(struct gfs2_alloc *al) {}
static inline int gfs2_quota_lock_check(struct gfs2_inode *ip) { return 0; }
static inline void gfs2_quota_unlock(struct gfs2_inode *ip) {}
static inline void gfs2_write_calc_reserv(struct gfs2_inode *ip, loff_t bytes, unsigned int *data_blocks, unsigned int *ind_blocks) {}
static inline int gfs2_inplace_reserve(struct gfs2_inode *ip) { return 0; }
static inline void gfs2_inplace_release(struct gfs2_inode *ip) {}
static inline void calc_max_reserv(struct gfs2_inode *ip, loff_t len, loff_t *max_bytes, unsigned int *data_blocks, unsigned int *ind_blocks) {}
static inline unsigned int gfs2_rg_blocks(struct gfs2_alloc *al) { return 0; }
static inline int gfs2_is_jdata(struct gfs2_inode *ip) { return 0; }
static inline int gfs2_trans_begin(struct gfs2_sbd *sdp, unsigned int blocks, unsigned int revokes) { return 0; }
static inline void gfs2_trans_end(struct gfs2_sbd *sdp) {}
static inline int fallocate_chunk(struct inode *inode, loff_t offset, loff_t len, int mode) { return 0; }