#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#define unlikely(x) (x)
#define ASSERT(cond) ((void)0)
#define PGC_count_mask 0xFFFFFFFF
#define PRI_mfn "lx"
#define XENLOG_WARNING 0

struct page_info {
    unsigned long count_info;
};

typedef uint64_t mfn_t;

static inline mfn_t page_to_mfn(struct page_info *page) { return 0; }
static inline unsigned long mfn_x(mfn_t mfn) { return 0; }
static int cleanup_page_cacheattr(struct page_info *page) { return 0; }
static void free_domheap_page(struct page_info *page) {}
static void gdprintk(int level, const char *fmt, ...) {}

static inline unsigned long cmpxchg(volatile unsigned long *ptr,
                                  unsigned long old,
                                  unsigned long new_val) {
    return 0;
}