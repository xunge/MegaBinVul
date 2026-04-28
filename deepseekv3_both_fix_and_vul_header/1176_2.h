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
    unsigned long i_private;
    unsigned long i_size;
    struct address_space *i_mapping;
};

struct page {
    unsigned long flags;
};

struct udf_inode_info {
    struct rw_semaphore i_data_sem;
    char *i_data;
    unsigned int i_lenAlloc;
    unsigned int i_lenEAttr;
    int i_alloc_type;
};

struct address_space_operations {
    int dummy;
};

#define UDF_I(inode) ((struct udf_inode_info *)(inode)->i_private)
#define UDF_QUERY_FLAG(sb, flag) ((sb)->s_flags & (flag))
#define UDF_FLAG_USE_SHORT_AD (1 << 0)
#define GFP_NOFS 0
#define ENOMEM 12
#define PAGE_SIZE 4096

enum {
    ICBTAG_FLAG_AD_IN_ICB = 0,
    ICBTAG_FLAG_AD_SHORT = 1,
    ICBTAG_FLAG_AD_LONG = 2
};

struct address_space_operations udf_aops;
struct address_space_operations udf_adinicb_aops;

#define inode_is_locked(inode) 1
#define WARN_ON_ONCE(condition) (void)(condition)
#define PageUptodate(page) ((page)->flags & (1 << 0))
#define SetPageUptodate(page) ((page)->flags |= (1 << 0))
#define flush_dcache_page(page) do {} while (0)
#define kmap_atomic(page) ((char *)0)
#define kunmap_atomic(addr) do {} while (0)
#define up_write(sem) do {} while (0)
#define down_write(sem) do {} while (0)
#define mark_inode_dirty(inode) do {} while (0)
#define set_page_dirty(page) do {} while (0)
#define unlock_page(page) do {} while (0)
#define lock_page(page) do {} while (0)
#define put_page(page) do {} while (0)
#define filemap_fdatawrite(mapping) 0
#define find_or_create_page(mapping, index, gfp) ((struct page *)0)