#include <stdint.h>
#include <stddef.h>

#define ENAMETOOLONG 36
#define EIO 5
#define ICBTAG_FLAG_AD_IN_ICB 0

struct inode;
struct file;
struct page;
struct rw_semaphore {
    int dummy;
};

struct buffer_head {
    unsigned char *b_data;
};

struct super_block {
    unsigned long s_blocksize;
};

struct address_space {
    struct inode *host;
};

struct inode {
    struct super_block *i_sb;
    unsigned long i_size;
    struct address_space *i_mapping;
};

struct page {
    struct address_space *mapping;
};

struct udf_inode_info {
    struct inode vfs_inode;
    struct rw_semaphore i_data_sem;
    int i_alloc_type;
    int i_lenEAttr;
    union {
        unsigned char i_data[1];
        struct {
            unsigned char i_data[1];
        } i_ext;
    };
};

#define UDF_I(inode) ((struct udf_inode_info *)(inode))

static inline void *kmap(struct page *page) { return NULL; }
static inline void kunmap(struct page *page) {}
static inline void SetPageUptodate(struct page *page) {}
static inline void SetPageError(struct page *page) {}
static inline void unlock_page(struct page *page) {}
static inline void down_read(struct rw_semaphore *sem) {}
static inline void up_read(struct rw_semaphore *sem) {}
static inline void brelse(struct buffer_head *bh) {}
static inline struct buffer_head *sb_bread(struct super_block *sb, uint32_t block) { return NULL; }
static inline uint32_t udf_block_map(struct inode *inode, uint32_t block) { return 0; }
static inline void udf_pc_to_char(struct super_block *sb, unsigned char *from, int fromlen, unsigned char *to) {}