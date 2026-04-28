#include <stdint.h>
#include <stddef.h>

typedef int64_t loff_t;
typedef uint64_t u64;
typedef uint64_t pgoff_t;
typedef uint64_t sector_t;

struct inode {
    unsigned long i_blkbits;
    loff_t i_size;
    void *i_mapping;
};

struct gfs2_inode {
    void *i_gl;
};

struct buffer_head {
    unsigned long b_state;
    sector_t b_blocknr;
    unsigned long b_size;
};

struct page;

#define GFS2_I(inode) ((struct gfs2_inode *)(inode))
#define PAGE_CACHE_SHIFT 12
#define PAGE_CACHE_SIZE (1 << PAGE_CACHE_SHIFT)
#define PAGE_CACHE_MASK (~(PAGE_CACHE_SIZE - 1))

#define FALLOC_FL_KEEP_SIZE 1
#define AOP_FLAG_NOFS 0
#define BH_New 0
#define I_DIRTY_DATASYNC 0
#define ENOMEM 12
#define EIO 5

#define unlikely(x) (x)

static inline void set_buffer_zeronew(struct buffer_head *bh) { bh->b_state |= (1 << BH_New); }
static inline int buffer_new(struct buffer_head *bh) { return bh->b_state & (1 << BH_New); }
static inline int buffer_zeronew(struct buffer_head *bh) { return bh->b_state & (1 << BH_New); }

static inline void i_size_write(struct inode *inode, loff_t i_size) { inode->i_size = i_size; }
static inline void mark_inode_dirty(struct inode *inode) { (void)inode; }
static inline void brelse(struct buffer_head *bh) { (void)bh; }
static inline void unlock_page(struct page *page) { (void)page; }
static inline void page_cache_release(struct page *page) { (void)page; }

extern int gfs2_meta_inode_buffer(struct gfs2_inode *ip, struct buffer_head **bhp);
extern void gfs2_trans_add_bh(void *gl, struct buffer_head *bh, int meta);
extern int gfs2_is_stuffed(struct gfs2_inode *ip);
extern int gfs2_unstuff_dinode(struct gfs2_inode *ip, struct buffer_head *bh);
extern int gfs2_block_map(struct inode *inode, sector_t lblock, struct buffer_head *bh, int create);
extern int write_empty_blocks(struct page *page, unsigned int from, unsigned int to, int mode);
extern struct page *grab_cache_page_write_begin(void *mapping, pgoff_t index, unsigned flags);