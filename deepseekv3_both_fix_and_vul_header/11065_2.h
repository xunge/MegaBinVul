#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

enum ttm_caching_state {
    tt_uncached,
    tt_wc,
    tt_cached
};

struct page {
    struct {
        struct page *next;
        struct page *prev;
    } lru;
};

struct ttm_page_pool {
    unsigned long lock;
    struct {
        struct page *next;
        struct page *prev;
    } list;
    unsigned npages;
};

struct {
    struct {
        unsigned max_size;
    } options;
} *_manager;

#define CONFIG_TRANSPARENT_HUGEPAGE
#define HPAGE_PMD_NR (1 << HPAGE_PMD_ORDER)
#define HPAGE_PMD_ORDER 9
#define TTM_PAGE_FLAG_DMA32 (1 << 0)
#define NUM_PAGES_TO_ALLOC 16

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void list_add_tail(void *new, void *head) {}
static inline int page_count(struct page *page) { return 0; }
static inline void __free_pages(struct page *page, unsigned int order) {}
static inline void pr_err(const char *fmt, ...) {}
static inline void ttm_page_pool_free(struct ttm_page_pool *pool, unsigned nr_pages, bool free_all) {}
static inline struct ttm_page_pool *ttm_get_pool(int flags, bool huge, enum ttm_caching_state cstate) { return NULL; }