#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#define NEW_ADDR ((unsigned long)-1)
#define MAX_INLINE_DATA 0
#define INLINE_DENTRY_BITMAP_SIZE 0
#define SIZE_OF_DENTRY_BITMAP 0
#define NR_INLINE_DENTRY 0
#define F2FS_SLOT_LEN 0
#define PAGE_CACHE_SIZE 4096
#define KERN_WARNING 0
#define DATA 0
#define ENOMEM 1
#define EINVAL 2

struct inode {
    unsigned long i_ino;
    void *i_mapping;
};

struct page;

struct f2fs_dir_entry {
    unsigned int hash;
    unsigned int ino;
    unsigned int name_len;
    unsigned char file_type;
    char name[F2FS_SLOT_LEN];
};

struct f2fs_inline_dentry {
    char dentry_bitmap[INLINE_DENTRY_BITMAP_SIZE];
    struct f2fs_dir_entry dentry[NR_INLINE_DENTRY];
    char filename[NR_INLINE_DENTRY * F2FS_SLOT_LEN];
};

struct dnode_of_data {
    unsigned long data_blkaddr;
};

struct f2fs_dentry_block {
    char dentry_bitmap[SIZE_OF_DENTRY_BITMAP];
    struct f2fs_dir_entry dentry[NR_INLINE_DENTRY];
    char filename[NR_INLINE_DENTRY * F2FS_SLOT_LEN];
};

struct super_block {
    void *sb;
};

struct f2fs_sb_info {
    struct super_block *sb;
};

enum {
    SBI_NEED_FSCK,
    FI_INLINE_DENTRY,
    FI_UPDATE_DIR
};

#define unlikely(x) __builtin_expect(!!(x), 0)

static inline void set_sbi_flag(struct f2fs_sb_info *sbi, int flag) {}
static inline void f2fs_msg(struct super_block *sb, int level, const char *fmt, ...) {}
static inline void f2fs_wait_on_page_writeback(struct page *page, int type) {}
static inline void zero_user_segment(struct page *page, unsigned start, unsigned end) {}
static inline void SetPageUptodate(struct page *page) {}
static inline void set_page_dirty(struct page *page) {}
static inline void truncate_inline_inode(struct page *ipage, int off) {}
static inline void stat_dec_inline_dir(struct inode *dir) {}
static inline void clear_inode_flag(void *inode, int flag) {}
static inline long i_size_read(const struct inode *inode) { return 0; }
static inline void i_size_write(struct inode *inode, long i_size) {}
static inline void set_inode_flag(void *inode, int flag) {}
static inline void sync_inode_page(struct dnode_of_data *dn) {}
static inline void f2fs_put_page(struct page *page, int unlock) {}
static inline void f2fs_put_dnode(struct dnode_of_data *dn) {}
static inline int f2fs_reserve_block(struct dnode_of_data *dn, int off) { return 0; }
static inline void set_new_dnode(struct dnode_of_data *dn, struct inode *inode,
                struct page *ipage, struct page *npage, int ofs) {}
static inline struct page *grab_cache_page(void *mapping, unsigned long index) { return NULL; }
static inline void *F2FS_I(struct inode *inode) { return NULL; }
static inline struct f2fs_sb_info *F2FS_P_SB(struct page *page) { return NULL; }
static inline void *kmap_atomic(struct page *page) { return NULL; }
static inline void kunmap_atomic(void *addr) {}