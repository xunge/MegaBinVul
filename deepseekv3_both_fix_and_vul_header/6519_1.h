#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define ASSERT(expr) assert(expr)
#define SHADOW_ERROR(fmt, ...) 
#define PRtype_info "ld"

struct domain {
    struct {
        struct {
            struct {
                unsigned long p2m_pages;
                unsigned long total_pages;
            } shadow;
        } paging;
    } arch;
};

struct page_info {
    unsigned long count_info;
    union {
        unsigned long type_info;
        struct {
            unsigned long type;
        } sh;
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

#define PGC_count_mask 0xFFFFFFFF
#define SH_type_p2m_table 0

static inline struct domain *page_get_owner(struct page_info *pg) { return NULL; }
static inline void page_set_owner(struct page_info *pg, void *owner) {}
static inline void paging_lock_recursive(struct domain *d) {}
static inline void paging_unlock(struct domain *d) {}
static inline void shadow_free(struct domain *d, unsigned long mfn) {}
static inline unsigned long page_to_mfn(struct page_info *pg) { return 0; }