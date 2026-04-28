#include <stdint.h>

struct inode {
    void *i_sb;
};

struct ocfs2_write_ctxt {
    struct page *w_target_page;
};

struct ocfs2_super {
    // minimal definition
};

struct page {
    // minimal definition
};

#define PAGE_CACHE_SIZE 4096
#define BUG_ON(cond) ((void)0)
#define PageUptodate(page) (1)

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t loff_t;

#define OCFS2_SB(sb) ((struct ocfs2_super *)(sb))

int ocfs2_map_page_blocks(struct page *page, u64 *p_blkno, struct inode *inode,
                          unsigned int from, unsigned int to, int new);
void ocfs2_figure_cluster_boundaries(struct ocfs2_super *osb, u32 cpos,
                                     unsigned int *cluster_start,
                                     unsigned int *cluster_end);
void ocfs2_clear_page_regions(struct page *page, struct ocfs2_super *osb,
                              u32 cpos, unsigned int user_data_from,
                              unsigned int user_data_to);
void mlog_errno(int err);
void flush_dcache_page(struct page *page);