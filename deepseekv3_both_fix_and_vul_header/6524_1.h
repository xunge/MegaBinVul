#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define PRtype_info "lx"
#define PGC_count_mask 0xffffffff
#define HAP_ERROR(fmt, ...)
#define WARN()
#define ASSERT(expr) assert(expr)

struct domain {
    struct {
        struct {
            struct {
                int p2m_pages;
                int total_pages;
            } hap;
        } paging;
    } arch;
};

struct page_info {
    uint64_t count_info;
    union {
        uint64_t type_info;
    } u;
};

typedef uint64_t mfn_t;

static void paging_lock_recursive(struct domain *d);
static void paging_unlock(struct domain *d);
static struct domain *page_get_owner(struct page_info *pg);
static void page_set_owner(struct page_info *pg, struct domain *d);
static mfn_t page_to_mfn(struct page_info *pg);
static void hap_free(struct domain *d, mfn_t mfn);