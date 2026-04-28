#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint64_t mfn_t;
typedef uint64_t type_info_t;

#define ASSERT(cond) ((void)0)
#define mfn_x(mfn) (mfn)
#define mfn_valid(mfn) (1)
#define INVALID_MFN ((mfn_t)-1)
#define SHADOW_OOS_PAGES 0
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_VIRTUAL_TLB 0
#define SHOPT_OUT_OF_SYNC 0
#define PRI_mfn "lx"
#define PRtype_info "lx"
#define PGC_count_mask 0
#define PG_log_dirty 0
#define SHADOW_ERROR(fmt, ...) ((void)0)

struct page_info {
    unsigned long count_info;
    union {
        type_info_t type_info;
    } u;
};

struct shadow_paging_mode {
    void (*detach_old_tables)(void *);
    void (*destroy_monitor_table)(void *, mfn_t);
};

struct paging_mode {
    struct shadow_paging_mode shadow;
};

struct shadow_paging_vcpu {
    mfn_t oos_snapshot[SHADOW_OOS_PAGES];
};

struct paging_vcpu {
    struct paging_mode *mode;
    void *vtlb;
    struct shadow_paging_vcpu shadow;
};

struct shadow_paging {
    unsigned long total_pages;
    void *hash_table;
    mfn_t unpaged_pagetable;
};

struct paging_domain {
    unsigned int mode;
    struct shadow_paging shadow;
};

struct dirty_vram {
    void *sl1ma;
    void *dirty_bitmap;
};

struct hvm_domain {
    struct dirty_vram *dirty_vram;
};

struct arch_vcpu {
    struct paging_vcpu paging;
    mfn_t monitor_table;
    mfn_t guest_table;
};

struct arch_domain {
    struct paging_domain paging;
    struct hvm_domain hvm_domain;
};

struct vcpu {
    struct arch_vcpu arch;
    struct domain *domain;
};

struct domain {
    bool is_dying;
    struct arch_domain arch;
    int domain_id;
    struct domain *current;
};

#define for_each_vcpu(d, v) \
    for ((v) = NULL; (v) != NULL; (v) = NULL)

#define pagetable_null() ((mfn_t)0)
#define pagetable_is_null(mfn) ((mfn) == 0)
#define pagetable_get_mfn(pt) (pt)
#define pagetable_get_page(pt) ((struct page_info *)NULL)

static inline void paging_lock(struct domain *d) {}
static inline void paging_unlock(struct domain *d) {}
static inline bool shadow_mode_enabled(struct domain *d) { return false; }
static inline bool shadow_mode_external(struct domain *d) { return false; }
static inline void shadow_set_allocation(struct domain *d, int i, bool *p) {}
static inline void shadow_hash_teardown(struct domain *d) {}
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline bool hvm_paging_enabled(struct vcpu *v) { return false; }
static inline void shadow_free(struct domain *d, mfn_t mfn) {}
static inline void shadow_free_p2m_page(struct domain *d, struct page_info *pg) {}
static inline struct domain *page_get_owner(struct page_info *pg) { return NULL; }
static inline void page_set_owner(struct page_info *pg, struct domain *d) {}
static inline mfn_t page_to_mfn(struct page_info *pg) { return 0; }

static inline void *xfree(void *ptr) { return NULL; }