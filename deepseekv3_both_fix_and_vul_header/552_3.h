#include <stdint.h>
#include <stdlib.h>

typedef int64_t loff_t;
typedef uint64_t u64;
typedef uint32_t u32;

struct super_block {
    void *s_fs_info;
};

struct inode {
    loff_t i_size;
    struct super_block *i_sb;
};

struct gfs2_inode {
    struct inode i_inode;
};

struct gfs2_sbd {
    struct {
        unsigned sb_bsize;
    } sd_sb;
    unsigned sd_rgrps;
    unsigned sd_max_rg_data;
    void *sd_rindex_spin;
};

struct gfs2_rindex {
    u64 ri_addr;
    u32 ri_length;
    u64 ri_data0;
    u32 ri_data;
    u32 ri_bitbytes;
};

struct gfs2_rgrpd {
    struct gfs2_sbd *rd_sbd;
    u64 rd_addr;
    u32 rd_length;
    u64 rd_data0;
    u32 rd_data;
    u32 rd_bitbytes;
    void *rd_rsspin;
    struct gfs2_glock *rd_gl;
    void *rd_rgl;
    unsigned rd_flags;
    void *rd_bits;
};

struct gfs2_glock {
    void *gl_object;
    struct {
        unsigned long start;
        unsigned long end;
    } gl_vm;
    struct {
        void *sb_lvbptr;
    } gl_lksb;
};

struct gfs2_glock_operations;

#define GFS2_SB(inode) ((struct gfs2_sbd *)((inode)->i_sb->s_fs_info))
#define GFP_NOFS 0
#define ENOMEM 12
#define CREATE 0
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE - 1))
#define PAGE_ALIGN(addr) (((addr) + PAGE_SIZE - 1) & PAGE_MASK)
#define GFS2_RDF_UPTODATE (1 << 0)
#define GFS2_RDF_PREFERRED (1 << 1)

static inline loff_t i_size_read(const struct inode *inode) {
    return inode->i_size;
}

static inline u64 be64_to_cpu(u64 x) { return x; }
static inline u32 be32_to_cpu(u32 x) { return x; }

static inline void spin_lock_init(void *lock) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

extern struct kmem_cache *gfs2_rgrpd_cachep;
extern const struct gfs2_glock_operations gfs2_rgrp_glops;

static void *kmem_cache_zalloc(void *cachep, int flags) { return calloc(1, sizeof(struct gfs2_rgrpd)); }
static void kmem_cache_free(void *cachep, void *ptr) { free(ptr); }
static void kfree(void *ptr) { free(ptr); }

static int gfs2_internal_read(struct gfs2_inode *ip, char *buf, loff_t *pos, unsigned int len) { return 0; }
static int compute_bitstructs(struct gfs2_rgrpd *rgd) { return 0; }
static int gfs2_glock_get(struct gfs2_sbd *sdp, u64 number, const struct gfs2_glock_operations *glops, int create, struct gfs2_glock **glp) { return 0; }
static void gfs2_glock_put(struct gfs2_glock *gl) {}
static int rgd_insert(struct gfs2_rgrpd *rgd) { return 0; }