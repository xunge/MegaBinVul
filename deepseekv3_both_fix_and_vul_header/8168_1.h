#include <stddef.h>

enum migrate_mode {
    MIGRATE_ASYNC,
    MIGRATE_SYNC,
    MIGRATE_SYNC_NO_COPY
};

#define MIGRATEPAGE_SUCCESS 0
#define EAGAIN 11

struct address_space {
    void *page_tree;
    void *tree_lock;
};

struct page {
    unsigned long index;
    struct address_space *mapping;
    unsigned long private;
};

struct zone {
    // dummy zone structure
};

struct buffer_head {
    // dummy buffer_head structure
};

#define PageSwapBacked(page) (0)
#define SetPageSwapBacked(page) do { } while (0)
#define PageDirty(page) (0)
#define ClearPageDirty(page) do { } while (0)
#define SetPageDirty(page) do { } while (0)
#define PageSwapCache(page) (0)
#define SetPageSwapCache(page) do { } while (0)
#define NR_FILE_PAGES 0
#define NR_SHMEM 0
#define NR_FILE_DIRTY 0

static inline void spin_lock_irq(void *lock) {}
static inline void spin_unlock_irq(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void local_irq_enable(void) {}
static inline int page_count(struct page *page) { return 0; }
static inline void set_page_memcg(struct page *page, void *memcg) {}
static inline void *page_memcg(struct page *page) { return NULL; }
static inline void *page_zone(struct page *page) { return NULL; }
static inline void *radix_tree_lookup_slot(void *tree, unsigned long index) { return NULL; }
static inline unsigned long page_index(struct page *page) { return 0; }
static inline int page_has_private(struct page *page) { return 0; }
static inline void *radix_tree_deref_slot_protected(void **slot, void *lock) { return NULL; }
static inline int page_freeze_refs(struct page *page, int count) { return 0; }
static inline int buffer_migrate_lock_buffers(struct buffer_head *head, enum migrate_mode mode) { return 0; }
static inline void page_unfreeze_refs(struct page *page, int count) {}
static inline void get_page(struct page *page) {}
static inline unsigned long page_private(struct page *page) { return 0; }
static inline void set_page_private(struct page *page, unsigned long priv) {}
static inline void radix_tree_replace_slot(void **slot, struct page *page) {}
static inline void __dec_zone_state(struct zone *zone, int counter) {}
static inline void __inc_zone_state(struct zone *zone, int counter) {}
static inline int mapping_cap_account_dirty(struct address_space *mapping) { return 0; }