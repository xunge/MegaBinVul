#include <stddef.h>

#define BUG_ON(cond) ((void)0)
#define NR_MLOCK 0
#define UNEVICTABLE_PGMLOCKED 0

struct page {
    unsigned long flags;
};

struct zone;

static inline int PageLocked(struct page *page) { return 1; }
static inline int TestSetPageMlocked(struct page *page) { return 0; }
static inline struct zone *page_zone(struct page *page) { return NULL; }
static inline void mod_zone_page_state(struct zone *zone, int item, long delta) {}
static inline void count_vm_event(int event) {}
static inline int isolate_lru_page(struct page *page) { return 0; }
static inline void putback_lru_page(struct page *page) {}
static inline int hpage_nr_pages(struct page *page) { return 1; }