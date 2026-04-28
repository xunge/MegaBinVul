#include <stdint.h>
#include <string.h>

#define PAGE_CACHE_BITS 4096
#define PAGE_CACHE_SIZE 4096
#define DBG_BITMAP 0

typedef uint32_t u32;
typedef uint32_t __be32;

struct mutex {
    int dummy;
};

struct super_block {
    unsigned long s_blocksize;
    unsigned char s_dirt;
    struct hfsplus_sb_info *s_fs_info;
};

struct inode {
    struct address_space *i_mapping;
    struct mutex i_mutex;
};

struct address_space {
    // minimal definition
};

struct page {
    // minimal definition  
};

struct hfsplus_sb_info {
    struct inode *alloc_file;
    u32 free_blocks;
};

#define HFSPLUS_SB(sb) (*(sb->s_fs_info))

static inline u32 be32_to_cpu(__be32 val) {
    return val;
}

static inline __be32 cpu_to_be32(u32 val) {
    return val;
}

static inline void dprint(int type, const char *fmt, ...) {}

static inline void kunmap(struct page *page) {}
static inline void *kmap(struct page *page) { return NULL; }
static inline void set_page_dirty(struct page *page) {}
static inline struct page *read_mapping_page(struct address_space *mapping, 
                                          unsigned long index, void *data) { 
    return NULL; 
}

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

#define min(a, b) ((a) < (b) ? (a) : (b))