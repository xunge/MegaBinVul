#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef int64_t loff_t;
typedef unsigned long pgoff_t;

#define PAGE_CACHE_SHIFT 12
#define PAGE_CACHE_SIZE (1 << PAGE_CACHE_SHIFT)
#define PAGE_CACHE_MASK (~(PAGE_CACHE_SIZE - 1))
#define GFP_KERNEL 0
#define KM_USER0 0
#define KM_USER1 1
#define ENOMEM 12
#define AOP_TRUNCATED_PAGE 1

struct pipe_inode_info;
struct pipe_buffer;
struct splice_desc {
    loff_t pos;
    unsigned int len;
    union {
        struct file *file;
        void *data;
    } u;
};
struct address_space;
struct file {
    struct address_space *f_mapping;
};
struct page;
struct pipe_buf_operations {
    int (*confirm)(struct pipe_inode_info *, struct pipe_buffer *);
    char *(*map)(struct pipe_inode_info *, struct pipe_buffer *, int);
    void (*unmap)(struct pipe_inode_info *, struct pipe_buffer *, char *);
};
struct pipe_buffer {
    struct page *page;
    unsigned int offset;
    const struct pipe_buf_operations *ops;
};
struct address_space_operations {
    int (*prepare_write)(struct file *, struct page *, unsigned int, unsigned int);
    int (*commit_write)(struct file *, struct page *, unsigned int, unsigned int);
};
struct address_space {
    struct address_space_operations *a_ops;
    void *host;
};

static inline loff_t i_size_read(void *host) { return 0; }
static inline void vmtruncate(void *host, loff_t isize) {}
static inline void mark_page_accessed(struct page *page) {}
static inline void flush_dcache_page(struct page *page) {}
static inline void kunmap_atomic(char *addr, int km_type) {}
static inline char *kmap_atomic(struct page *page, int km_type) { return NULL; }
static inline int add_to_page_cache_lru(struct page *page, struct address_space *mapping, pgoff_t index, int gfp) { return 0; }
static inline struct page *page_cache_alloc_cold(struct address_space *mapping) { return NULL; }
static inline struct page *find_lock_page(struct address_space *mapping, pgoff_t index) { return NULL; }
static inline void unlock_page(struct page *page) {}
static inline void page_cache_release(struct page *page) {}

#define unlikely(x) (x)