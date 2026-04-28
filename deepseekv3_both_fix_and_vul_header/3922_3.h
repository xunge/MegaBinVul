#include <stddef.h>

#define SB_RDONLY 1
#define GLR_TRYFAILED 1
#define EROFS 30
#define SHOULD_DEFER_EVICTION 0
#define SHOULD_DELETE_DINODE 1
#define GIF_GLOP_PENDING 0
#define GL_NOCACHE 0
#define TASK_UNINTERRUPTIBLE 0

struct address_space {
    // placeholder for address_space structure
};

struct inode {
    struct super_block *i_sb;
    unsigned long i_nlink;
    struct address_space i_data;
};

struct super_block {
    unsigned long s_flags;
    void *s_fs_info;
};

struct gfs2_sbd {
    void *sd_jdesc;
};

struct gfs2_rs {};
struct gfs2_qadata {
    int qa_ref;
};
struct gfs2_glock {};
struct gfs2_holder {
    unsigned int gh_flags;
    struct gfs2_glock *gh_gl;
};

struct gfs2_inode {
    struct gfs2_rs i_res;
    struct gfs2_qadata *i_qadata;
    struct gfs2_holder i_iopen_gh;
    struct gfs2_glock *i_gl;
    unsigned long i_flags;
    unsigned long i_no_addr;
};

static inline int sb_rdonly(struct super_block *sb) { return sb->s_flags & SB_RDONLY; }

static inline struct gfs2_inode *GFS2_I(struct inode *inode) { return NULL; }
static inline void gfs2_holder_mark_uninitialized(struct gfs2_holder *gh) {}
static inline int gfs2_holder_initialized(struct gfs2_holder *gh) { return 0; }
static inline void gfs2_glock_dq_uninit(struct gfs2_holder *gh) {}
static inline void gfs2_glock_hold(struct gfs2_glock *gl) {}
static inline void gfs2_glock_put_eventually(struct gfs2_glock *gl) {}
static inline void gfs2_glock_add_to_lru(struct gfs2_glock *gl) {}
static inline void glock_clear_object(struct gfs2_glock *gl, struct gfs2_inode *ip) {}
static inline int gfs2_rs_active(struct gfs2_rs *rs) { return 0; }
static inline void gfs2_rs_deltree(struct gfs2_rs *rs) {}
static inline void gfs2_ordered_del_inode(struct gfs2_inode *ip) {}
static inline void gfs2_dir_hash_inval(struct gfs2_inode *ip) {}
static inline void gfs2_assert_warn(struct gfs2_sbd *sdp, int condition) {}
static inline void fs_warn(struct gfs2_sbd *sdp, const char *fmt, ...) {}
static inline int evict_should_delete(struct inode *inode, struct gfs2_holder *gh) { return 0; }
static inline int evict_unlinked_inode(struct inode *inode) { return 0; }
static inline int evict_linked_inode(struct inode *inode) { return 0; }
static inline void truncate_inode_pages_final(struct address_space *mapping) {}
static inline void clear_inode(struct inode *inode) {}
static inline void wait_on_bit_io(unsigned long *word, int bit, unsigned mode) {}