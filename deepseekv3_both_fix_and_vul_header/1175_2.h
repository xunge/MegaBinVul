#include <stddef.h>
#include <string.h>

struct rw_semaphore {
    int dummy;
};

struct super_block {
    unsigned long s_flags;
};

struct address_space {
    struct address_space_operations *a_ops;
};

struct inode {
    struct super_block *i_sb;
    struct address_space i_data;
    unsigned long i_size;
    void *i_private;
    void *i_mapping;
};

struct page {
    unsigned long dummy;
};

struct writeback_control {
    int sync_mode;
    int nr_to_write;
};

struct udf_inode_info {
    struct rw_semaphore i_data_sem;
    unsigned int i_lenAlloc;
    unsigned int i_lenEAttr;
    unsigned char i_alloc_type;
    char *i_data;
};

struct address_space_operations {
    int (*writepage)(struct page *, struct writeback_control *);
};

#define UDF_I(inode) ((struct udf_inode_info *)(inode)->i_private)
#define UDF_QUERY_FLAG(sb, flag) ((sb)->s_flags & (flag))
#define UDF_FLAG_USE_SHORT_AD (1 << 0)

#define ICBTAG_FLAG_AD_SHORT 0
#define ICBTAG_FLAG_AD_LONG 1
#define ICBTAG_FLAG_AD_IN_ICB 2

#define WB_SYNC_NONE 0
#define GFP_NOFS 0
#define ENOMEM 12
#define PAGE_SIZE 4096

struct address_space_operations udf_aops;
struct address_space_operations udf_adinicb_aops;

#define inode_is_locked(inode) (1)
#define WARN_ON_ONCE(condition) ((void)0)
#define PageUptodate(page) (1)
#define flush_dcache_page(page) ((void)0)
#define SetPageUptodate(page) ((void)0)
#define kunmap_atomic(addr) ((void)0)
#define kmap_atomic(page) ((void *)(page))
#define lock_page(page) ((void)0)
#define unlock_page(page) ((void)0)
#define put_page(page) ((void)0)
#define mark_inode_dirty(inode) ((void)0)
#define down_write(sem) ((void)0)
#define up_write(sem) ((void)0)

static inline struct page *find_or_create_page(void *mapping, unsigned long index, int gfp_mask) {
    return NULL;
}