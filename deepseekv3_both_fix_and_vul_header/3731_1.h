#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define ASSERT(cond) ((void)0)
#define EPT_TABLE_ORDER 9
#define EPT_PAGETABLE_ENTRIES 512

#define GUEST_TABLE_POD_PAGE 0
#define GUEST_TABLE_MAP_FAILED 1
#define GUEST_TABLE_SUPER_PAGE 2
#define GUEST_TABLE_NORMAL_PAGE 3

typedef uint32_t u32;
typedef uint64_t mfn_t;
typedef bool bool_t;

struct p2m_domain;
typedef struct p2m_domain p2m_domain_t;

typedef struct ept_entry {
    uint64_t mfn;
    uint32_t sa_p2mt;
} ept_entry_t;

#define p2m_populate_on_demand 0

static inline bool_t is_epte_present(const ept_entry_t *e) { return false; }
static inline bool_t is_epte_superpage(const ept_entry_t *e) { return false; }
static inline ept_entry_t *ept_set_middle_entry(p2m_domain_t *p2m, ept_entry_t *ept_entry) { return NULL; }
static inline ept_entry_t atomic_read_ept_entry(ept_entry_t *ept_entry) { return *ept_entry; }
static inline void unmap_domain_page(void *table) {}
static inline ept_entry_t *map_domain_page(mfn_t mfn) { return NULL; }
static inline mfn_t _mfn(uint64_t mfn) { return mfn; }