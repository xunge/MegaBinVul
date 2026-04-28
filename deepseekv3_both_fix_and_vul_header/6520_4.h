#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

#define PG_SH_enable    (1 << 0)
#define PG_translate    (1 << 1)
#define PGT_l2_page_table (1 << 0)
#define PGT_validated   (1 << 1)
#define PGC_count_mask  0xFFFF
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_LINUX_L3_TOPLEVEL (1 << 0)
#define EINVAL 22
#define ENOMEM 12

struct domain {
    struct {
        struct {
            struct {
                unsigned int total_pages;
                unsigned int opt_flags;
                void *unpaged_pagetable;
            } shadow;
            void *alloc_page;
            void *free_page;
        } paging;
    } arch;
};

struct page_info {
    unsigned long count_info;
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

struct p2m_domain {
    void *pagetable;
};

static inline struct p2m_domain *p2m_get_hostp2m(struct domain *d) { return NULL; }
static inline void domain_pause(struct domain *d) {}
static inline int shadow_mode_enabled(struct domain *d) { return 0; }
static inline void paging_lock(struct domain *d) {}
static inline int shadow_set_allocation(struct domain *d, int size, void *arg) { return 0; }
static inline void paging_unlock(struct domain *d) {}
static inline int p2m_alloc_table(struct p2m_domain *p2m) { return 0; }
static inline int is_hvm_domain(struct domain *d) { return 0; }
static inline struct page_info *shadow_alloc_p2m_page(struct domain *d) { return NULL; }
static inline uint32_t *__map_domain_page(struct page_info *pg) { return NULL; }
static inline void write_32bit_pse_identmap(uint32_t *e) {}
static inline void unmap_domain_page(uint32_t *e) {}
static inline void page_set_owner(struct page_info *pg, struct domain *d) {}
static inline int shadow_hash_alloc(struct domain *d) { return 0; }
static inline void *pagetable_from_page(struct page_info *pg) { return NULL; }
static inline void sh_new_mode(struct domain *d, u32 mode) {}
static inline int pagetable_is_null(void *p) { return 1; }
static inline void *p2m_get_pagetable(struct p2m_domain *p2m) { return NULL; }
static inline void p2m_teardown(struct p2m_domain *p2m) {}
static inline void shadow_free_p2m_page(struct domain *d, struct page_info *pg) {}
static inline void domain_unpause(struct domain *d) {}