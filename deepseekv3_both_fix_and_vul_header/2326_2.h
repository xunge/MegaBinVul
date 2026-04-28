#include <stdint.h>
#include <stddef.h>

struct domain;
struct page_info;
struct vcpu;

typedef struct {
    unsigned long x;
} mfn_t;

struct page_list_head {
    struct page_info *next;
    struct page_info *prev;
};

#define mfn_x(mfn) ((mfn).x)
#define page_to_mfn(pg) ((mfn_t){0})
#define mfn_to_page(mfn) ((struct page_info *)NULL)
#define for_each_vcpu(d, v) 
#define SH_type_none 0
#define SH_type_max_shadow 0
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_WRITABLE_HEURISTIC 0
#define SHOPT_FAST_EMULATION 0
#define ASSERT(cond) 

typedef uint32_t u32;

struct page_info {
    union {
        struct {
            u32 type;
            u32 head;
        } sh;
    } u;
    unsigned long tlbflush_timestamp;
    struct page_list_head list;
};

struct vcpu {
    struct {
        struct {
            unsigned long last_writeable_pte_smfn;
            int last_write_emul_ok;
        } shadow;
    } arch;
};

struct domain {
    struct {
        struct {
            struct {
                struct page_list_head freelist;
                struct page_list_head pinned_shadows;
                unsigned int free_pages;
            } shadow;
        } paging;
    } arch;
};

static inline unsigned int shadow_size(u32 type) { return 0; }
static inline int paging_locked_by_me(struct domain *d) { return 1; }
static inline unsigned long tlbflush_current_time(void) { return 0; }
static inline void perfc_incr(int counter) {}
static inline void perfc_decr(int counter) {}
static inline struct page_info *page_list_next(struct page_info *page, struct page_list_head *list) { return NULL; }
static inline void page_list_add_tail(struct page_info *page, struct page_list_head *list) {}

extern int shadow_alloc_count;