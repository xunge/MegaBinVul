#include <stddef.h>
#include <sys/types.h>

typedef unsigned long pgoff_t;

struct page {
    // Minimal page structure definition
};

struct file {
    void *f_mapping;
};

struct address_space {
    const void *a_ops;
};

struct address_space_operations {
    int (*write_begin)(struct file *, struct address_space *, loff_t, unsigned long, unsigned int, struct page **, void **);
    int (*write_end)(struct file *, struct address_space *, loff_t, unsigned long, unsigned long, struct page *, void *);
};

struct iov_iter {
    // Minimal iov_iter structure definition
};

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define PAGE_CACHE_SIZE PAGE_SIZE
#define PAGE_CACHE_SHIFT PAGE_SHIFT

#define KERNEL_DS 0
#define AOP_FLAG_UNINTERRUPTIBLE 0x0001
#define EFAULT 14

typedef int mm_segment_t;

static inline mm_segment_t get_fs(void) { return 0; }
static inline int segment_eq(mm_segment_t a, mm_segment_t b) { return a == b; }
static inline size_t iov_iter_count(struct iov_iter *i) { return 0; }
static inline int iov_iter_fault_in_readable(struct iov_iter *i, size_t bytes) { return 0; }
static inline size_t iov_iter_copy_from_user_atomic(struct page *page, struct iov_iter *i, unsigned long offset, size_t bytes) { return 0; }
static inline void iov_iter_advance(struct iov_iter *i, size_t bytes) {}
static inline size_t iov_iter_single_seg_count(struct iov_iter *i) { return 0; }
static inline void pagefault_disable(void) {}
static inline void pagefault_enable(void) {}
static inline void flush_dcache_page(struct page *page) {}
static inline void cond_resched(void) {}
static inline void balance_dirty_pages_ratelimited(struct address_space *mapping) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define unlikely(x) (x)