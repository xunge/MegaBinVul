#include <stdbool.h>
#include <errno.h>

struct page_info {
    unsigned long linear_pt_count;
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    struct {
        bool is_dying;
    } *owner;
};

#define PGT_type_equal(a, b) ((a) == (b))
#define PGT_count_mask 0xFF
#define PGT_validated 0x100
#define PGT_partial 0x200

static inline void dec_linear_uses(struct page_info *page) {}
static inline void dec_linear_entries(struct page_info *page) {}
static inline struct page_info *page_get_owner(struct page_info *page) { return page->owner; }
static inline void set_tlbflush_timestamp(struct page_info *page) {}
static inline void smp_wmb() {}
static inline void get_page_light(struct page_info *page) {}
static inline int free_page_type(struct page_info *page, unsigned long type, bool preemptible) { return 0; }

#define ASSERT(cond) ((void)0)
#define BUG_ON(cond) ((void)0)