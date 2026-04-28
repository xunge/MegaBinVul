#include <stddef.h>

#define MAX_INLINE_DATA 0
#define NEW_ADDR 0
#define PAGE_CACHE_SIZE 0
#define DATA 0
#define WRITE_SYNC 0
#define REQ_PRIO 0
#define KERN_WARNING 0
#define EINVAL 0
#define SBI_NEED_FSCK 0
#define FI_APPEND_WRITE 0

struct dnode_of_data {
    struct inode *inode;
    struct page *inode_page;
    unsigned int data_blkaddr;
};

struct page {
    unsigned long index;
};

struct inode {
    unsigned long i_ino;
};

struct f2fs_io_info {
    struct f2fs_sb_info *sbi;
    int type;
    int rw;
    struct page *page;
    struct page *encrypted_page;
    unsigned int blk_addr;
};

struct f2fs_sb_info {
    struct super_block *sb;
};

struct super_block;

static inline struct f2fs_sb_info *F2FS_I_SB(struct inode *inode) { return NULL; }
static inline void f2fs_bug_on(struct f2fs_sb_info *sbi, unsigned long index) {}
static inline int f2fs_exist_data(struct inode *inode) { return 0; }
static inline int f2fs_reserve_block(struct dnode_of_data *dn, int i) { return 0; }
static inline void f2fs_put_dnode(struct dnode_of_data *dn) {}
static inline void set_sbi_flag(struct f2fs_sb_info *sbi, int flag) {}
static inline int f2fs_msg(struct super_block *sb, int level, const char *fmt, ...) { return 0; }
static inline void f2fs_wait_on_page_writeback(struct page *page, int type) {}
static inline int PageUptodate(struct page *page) { return 0; }
static inline void zero_user_segment(struct page *page, unsigned start, unsigned end) {}
static inline void *inline_data_addr(struct page *page) { return NULL; }
static inline void *kmap_atomic(struct page *page) { return NULL; }
static inline void flush_dcache_page(struct page *page) {}
static inline void kunmap_atomic(void *addr) {}
static inline void SetPageUptodate(struct page *page) {}
static inline void set_page_dirty(struct page *page) {}
static inline int clear_page_dirty_for_io(struct page *page) { return 0; }
static inline void set_page_writeback(struct page *page) {}
static inline void write_data_page(struct dnode_of_data *dn, struct f2fs_io_info *fio) {}
static inline void set_data_blkaddr(struct dnode_of_data *dn) {}
static inline void f2fs_update_extent_cache(struct dnode_of_data *dn) {}
static inline void inode_dec_dirty_pages(struct inode *inode) {}
static inline void set_inode_flag(struct inode *inode, int flag) {}
static inline void truncate_inline_inode(struct page *page, int i) {}
static inline void stat_dec_inline_inode(struct inode *inode) {}
static inline void f2fs_clear_inline_inode(struct inode *inode) {}
static inline void sync_inode_page(struct dnode_of_data *dn) {}