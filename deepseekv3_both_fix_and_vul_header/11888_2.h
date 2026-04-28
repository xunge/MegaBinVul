#include <stdint.h>
#include <stddef.h>

struct domain;

typedef uint64_t mfn_t;
typedef uint32_t u32;

struct page_info {
    unsigned long count_info;
    unsigned long shadow_flags;
};

#define _PGC_page_table 0
#define SHF_page_type_mask 0
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_OUT_OF_SYNC 0
#define TRCE_SFLAG_DEMOTE 0

#define ASSERT(x) 
#define TRACE_SHADOW_PATH_FLAG(x) 

static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline int test_bit(int nr, volatile void *addr) { return 0; }
static inline void clear_bit(int nr, volatile void *addr) {}
static inline int page_is_out_of_sync(struct page_info *page) { return 0; }
static inline void oos_hash_remove(struct domain *d, mfn_t gmfn) {}