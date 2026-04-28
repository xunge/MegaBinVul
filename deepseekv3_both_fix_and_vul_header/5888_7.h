#include <stdint.h>
#include <stddef.h>

struct buffer_head {
    unsigned char *b_data;
};

struct super_block {
    unsigned long s_blocksize;
};

struct inode {
    struct super_block *i_sb;
    unsigned long i_size;
    struct inode *host;
};

struct file;
struct page {
    struct inode *mapping;
};

struct rw_semaphore {
    int dummy;
};

static inline void down_read(struct rw_semaphore *sem) {}
static inline void up_read(struct rw_semaphore *sem) {}

static inline void *kmap(struct page *page) { return NULL; }
static inline void kunmap(struct page *page) {}
static inline void unlock_page(struct page *page) {}
static inline void SetPageUptodate(struct page *page) {}
static inline void SetPageError(struct page *page) {}

struct buffer_head *sb_bread(struct super_block *sb, uint32_t block) { return NULL; }
static inline void brelse(struct buffer_head *bh) {}

struct udf_inode_info {
    struct inode vfs_inode;
    struct rw_semaphore i_data_sem;
    int i_alloc_type;
    unsigned int i_lenEAttr;
    struct {
        unsigned char *i_data;
        struct {
            unsigned char *i_data;
        } i_ext;
    };
};

#define UDF_I(inode) ((struct udf_inode_info *)(inode))
#define ENAMETOOLONG (-36)
#define EIO (-5)
#define ICBTAG_FLAG_AD_IN_ICB 0x00
#define PAGE_SIZE 4096

static int udf_pc_to_char(struct super_block *sb, unsigned char *from, int fromlen, unsigned char *to, ...) { return 0; }
static uint32_t udf_block_map(struct inode *inode, int block) { return 0; }