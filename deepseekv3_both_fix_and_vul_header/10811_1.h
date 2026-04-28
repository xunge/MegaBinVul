#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct domain;
struct page_info {
    struct domain *owner;
    unsigned long count_info;
};

struct grant_table {
    void **status;
    unsigned int nr_status_frames;
};

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;

#define INVALID_GFN ((gfn_t) { 0 })
#define PGC_xen_heap (1UL << 0)
#define _PGC_allocated (0)
#define XENLOG_ERR (0)
#define EBUSY (-1)

static inline bool gfn_eq(gfn_t a, gfn_t b) { return a == b; }
static inline unsigned long gfn_x(gfn_t gfn) { return gfn; }
static inline mfn_t page_to_mfn(struct page_info *pg) { return (mfn_t) { 0 }; }
static inline mfn_t _mfn(mfn_t mfn) { return mfn; }

static inline unsigned int nr_status_frames(struct grant_table *gt) { return gt->nr_status_frames; }
static inline gfn_t gnttab_get_frame_gfn(struct grant_table *gt, bool status, unsigned int idx) { return INVALID_GFN; }
static inline void gnttab_set_frame_gfn(struct grant_table *gt, bool status, unsigned int idx, gfn_t gfn) {}
static inline bool paging_mode_translate(struct domain *d) { return false; }
static inline int guest_physmap_remove_page(struct domain *d, gfn_t gfn, mfn_t mfn, int flags) { return 0; }
static inline void gprintk(int level, const char *fmt, ...) {}
static inline void domain_crash(struct domain *d) {}
static inline struct domain *page_get_owner(struct page_info *pg) { return pg->owner; }
static inline void page_set_owner(struct page_info *pg, struct domain *d) { pg->owner = d; }
static inline bool test_and_clear_bit(int bit, unsigned long *addr) { return false; }
static inline void put_page(struct page_info *pg) {}
static inline bool get_page(struct page_info *pg, struct domain *d) { return false; }
static inline void set_bit(int bit, unsigned long *addr) {}
static inline void gnttab_create_status_page(struct domain *d, struct grant_table *gt, unsigned int idx) {}
static inline void free_xenheap_page(void *ptr) {}
static inline struct page_info *virt_to_page(void *virt) { return NULL; }

#define BUG_ON(cond) do { if (cond) {} } while (0)