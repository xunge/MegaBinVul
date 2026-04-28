#include <stdint.h>
#include <stddef.h>

typedef uint64_t sector_t;
typedef uint64_t u64;
typedef uint64_t __be64;

struct buffer_head {
    void *b_data;
    unsigned long b_size;
    unsigned long b_state;
};

struct inode {
    struct super_block *i_sb;
    unsigned long i_blkbits;
};

struct super_block {
    void *s_fs_info;
};

struct gfs2_inode {
    struct inode i_inode;
    void *i_gl;
    unsigned int i_height;
};

struct gfs2_sbd {
    struct super_block *sd_vfs;
    unsigned int sd_inptrs;
    unsigned int sd_diptrs;
};

struct metapath {
    struct buffer_head *mp_bh[16];
    unsigned int mp_list[16];
};

struct gfs2_dinode {
    char dummy[256];
};

struct gfs2_meta_header {
    char dummy[64];
};

enum alloc_state {
    ALLOC_DATA,
    ALLOC_GROW_DEPTH,
    ALLOC_GROW_HEIGHT
};

#define GFS2_I(inode) ((struct gfs2_inode *)(inode))
#define GFS2_SB(inode) ((struct gfs2_sbd *)((inode)->i_sb->s_fs_info))
#define NULL ((void *)0)
#define BUG_ON(cond) do { if (cond) {} } while (0)
#define GFP_NOFS 0
#define min(a, b) ((a) < (b) ? (a) : (b))

static inline __be64 cpu_to_be64(u64 x) { return x; }

static void gfs2_trans_add_bh(void *gl, struct buffer_head *bh, int flag) {}
static void gfs2_trans_add_unrevoke(struct gfs2_sbd *sdp, u64 bn, unsigned n) {}
static int gfs2_is_jdata(struct gfs2_inode *ip) { return 0; }
static int gfs2_alloc_block(struct gfs2_inode *ip, u64 *bn, unsigned *n) { return 0; }
static void gfs2_indirect_init(struct metapath *mp, void *gl, unsigned i, unsigned pos, u64 bn) {}
static void gfs2_buffer_copy_tail(struct buffer_head *bh1, unsigned offset1, 
                                struct buffer_head *bh2, unsigned offset2) {}
static void gfs2_buffer_clear_tail(struct buffer_head *bh, unsigned offset) {}
static void brelse(struct buffer_head *bh) {}
static int metapath_branch_start(struct metapath *mp) { return 0; }
static __be64 *metapointer(unsigned height, struct metapath *mp) { return NULL; }
static unsigned gfs2_extent_length(void *data, unsigned size, __be64 *ptr, 
                                 unsigned maxlen, int *eob) { return 0; }
static void gfs2_add_inode_blocks(struct inode *inode, unsigned n) {}
static void gfs2_dinode_out(struct gfs2_inode *ip, void *data) {}
static void map_bh(struct buffer_head *bh, struct super_block *sb, sector_t block) {}
static void set_buffer_new(struct buffer_head *bh) {}
static int buffer_zeronew(struct buffer_head *bh) { return 0; }
static void clear_buffer_zeronew(struct buffer_head *bh) {}
static int sb_issue_zeroout(struct super_block *sb, sector_t block, 
                          sector_t nr_blocks, int flags) { return 0; }
static void fs_err(struct gfs2_sbd *sdp, const char *fmt, ...) {}