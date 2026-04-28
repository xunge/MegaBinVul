#include <stdbool.h>
#include <stddef.h>

struct page {
    unsigned long flags;
};

struct zone {
    void *lru_lock;
};

#define BUG_ON(cond) ((void)0)
#define PageLocked(page) ((page)->flags & 0x1)
#define TestClearPageMlocked(page) ((page)->flags &= ~0x2)
#define NR_MLOCK 0

struct zone *page_zone(struct page *page);
unsigned int hpage_nr_pages(struct page *page);
void __mod_zone_page_state(struct zone *zone, int item, long delta);
bool __munlock_isolate_lru_page(struct page *page, bool clear_mlock);
void __munlock_isolated_page(struct page *page);
void __munlock_isolation_failed(struct page *page);

void spin_lock_irq(void *lock);
void spin_unlock_irq(void *lock);