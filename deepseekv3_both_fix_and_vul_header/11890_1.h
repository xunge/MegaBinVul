#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint64_t mfn_t;

struct domain {
    bool is_shutting_down;
};

struct page_info {
    union {
        struct {
            uint32_t type_info;
        } inuse;
    } u;
    uint32_t count_info;
    uint32_t shadow_flags;
    bool pagetable_dying;
};

#define PGT_type_mask 0xFF
#define PGT_writable_page 0x01
#define PGT_count_mask 0xFF00
#define _PGC_page_table 0
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_OUT_OF_SYNC 0

#define ASSERT(x) (void)(x)
#define TRACE_SHADOW_PATH_FLAG(x) (void)(x)
#define TRCE_SFLAG_PROMOTE 0

static inline bool mfn_valid(mfn_t mfn) { return true; }
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline bool page_is_out_of_sync(struct page_info *page) { return false; }
static inline void sh_resync(struct domain *d, mfn_t gmfn) {}
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline bool test_and_set_bit(int nr, volatile void *addr) { return false; }
static inline bool test_bit(int nr, const volatile void *addr) { return false; }
static inline void set_bit(int nr, volatile void *addr) {}