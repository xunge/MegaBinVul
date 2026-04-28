#include <stdint.h>
#include <stddef.h>

#define FALLOC_FL_KEEP_SIZE 0x01
#define EOPNOTSUPP 95
#define ENOMEM 12
#define ENOSPC 28

#define LM_ST_EXCLUSIVE 1

#define RES_DINODE 1
#define RES_STATFS 1
#define RES_QUOTA 1
#define RES_RG_HDR 1

#define PAGE_CACHE_SIZE 4096
#define UINT_MAX (~0U)

typedef int64_t loff_t;

struct file {
    struct {
        struct dentry {
            struct inode *d_inode;
        } *dentry;
    } f_path;
};

struct inode {
    void *i_sb;
};

struct gfs2_sbd {
    struct {
        unsigned int sb_bsize;
        unsigned int sb_bsize_shift;
    } sd_sb;
    unsigned int sd_max_rg_data;
};

struct gfs2_inode {
    struct gfs2_glock *i_gl;
    struct {
        int dummy;
    } i_gh;
};

struct gfs2_alloc {
    unsigned int al_requested;
};

struct gfs2_glock {
    int dummy;
};

#define GFS2_SB(inode) ((struct gfs2_sbd *)(inode)->i_sb)
#define GFS2_I(inode) ((struct gfs2_inode *)(inode))

#define unlikely(x) (x)

static void gfs2_holder_init(struct gfs2_glock *gl, int state, int flags, struct gfs2_holder *gh) {}
static int gfs2_glock_nq(struct gfs2_holder *gh) { return 0; }
static void gfs2_glock_dq(struct gfs2_holder *gh) {}
static void gfs2_holder_uninit(struct gfs2_holder *gh) {}
static int gfs2_write_alloc_required(struct gfs2_inode *ip, loff_t offset, loff_t len) { return 0; }
static struct gfs2_alloc *gfs2_alloc_get(struct gfs2_inode *ip) { return NULL; }
static void gfs2_alloc_put(struct gfs2_inode *ip) {}
static int gfs2_quota_lock_check(struct gfs2_inode *ip) { return 0; }
static void gfs2_write_calc_reserv(struct gfs2_inode *ip, loff_t bytes, unsigned int *data_blocks, unsigned int *ind_blocks) {}
static int gfs2_inplace_reserve(struct gfs2_inode *ip) { return 0; }
static void calc_max_reserv(struct gfs2_inode *ip, loff_t len, loff_t *max_bytes, unsigned int *data_blocks, unsigned int *ind_blocks) {}
static unsigned int gfs2_rg_blocks(struct gfs2_inode *ip) { return 0; }
static int gfs2_is_jdata(struct gfs2_inode *ip) { return 0; }
static int gfs2_trans_begin(struct gfs2_sbd *sdp, unsigned int blocks, unsigned int revokes) { return 0; }
static void gfs2_trans_end(struct gfs2_sbd *sdp) {}
static int fallocate_chunk(struct inode *inode, loff_t offset, loff_t len, int mode) { return 0; }
static void gfs2_inplace_release(struct gfs2_inode *ip) {}
static void gfs2_quota_unlock(struct gfs2_inode *ip) {}