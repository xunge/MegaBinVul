#include <stdbool.h>
#include <stddef.h>

struct page;
struct folio;

struct migrate_vma {
    unsigned long npages;
    unsigned long *src;
    unsigned long cpages;
    struct page *fault_page;
};

#define MIGRATE_PFN_MIGRATE 0

static inline struct page *migrate_pfn_to_page(unsigned long pfn) { return NULL; }
static inline bool is_zone_device_page(struct page *page) { return false; }
static inline bool PageLRU(struct page *page) { return false; }
static inline int isolate_lru_page(struct page *page) { return 0; }
static inline void put_page(struct page *page) {}
static inline struct folio *page_folio(struct page *page) { return NULL; }
static inline bool folio_mapped(struct folio *folio) { return false; }
static inline void try_to_migrate(struct folio *folio, int flags) {}
static inline bool page_mapped(struct page *page) { return false; }
static inline bool migrate_vma_check_page(struct page *page, ...) { return false; }
static inline void get_page(struct page *page) {}
static inline void putback_lru_page(struct page *page) {}
static inline void remove_migration_ptes(struct folio *src, struct folio *dst, bool locked) {}
static inline void folio_unlock(struct folio *folio) {}
static inline void folio_put(struct folio *folio) {}
static inline void lru_add_drain(void) {}
static inline void lru_add_drain_all(void) {}