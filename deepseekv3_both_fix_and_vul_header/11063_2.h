#include <stddef.h>
#include <stdbool.h>

enum ttm_caching_state {
    tt_cached,
    tt_uncached,
    tt_wc
};

struct page {
    int lru;
};

struct ttm_page_pool {
    int lock;
    struct page list;
    unsigned npages;
};

struct ttm_pool_manager {
    struct {
        unsigned max_size;
    } options;
};

extern struct ttm_pool_manager *_manager;
extern struct ttm_page_pool *ttm_get_pool(int flags, bool huge, enum ttm_caching_state cstate);
extern void ttm_page_pool_free(struct ttm_page_pool *pool, unsigned nr_free, bool use_static);
extern void __free_pages(struct page *page, unsigned int order);
extern int page_count(struct page *page);
extern void pr_err(const char *fmt, ...);
extern void spin_lock_irqsave(int *lock, unsigned long flags);
extern void spin_unlock_irqrestore(int *lock, unsigned long flags);
extern void list_add_tail(int *entry, struct page *head);

#define CONFIG_TRANSPARENT_HUGEPAGE
#define TTM_PAGE_FLAG_DMA32 (1 << 0)
#define HPAGE_PMD_NR (1 << HPAGE_PMD_ORDER)
#define HPAGE_PMD_ORDER 9
#define NUM_PAGES_TO_ALLOC 16