#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define EPT_TABLE_ORDER 9
#define EPT_PAGETABLE_ENTRIES 512

#define GUEST_TABLE_POD_PAGE 1
#define GUEST_TABLE_MAP_FAILED 2
#define GUEST_TABLE_SUPER_PAGE 3
#define GUEST_TABLE_NORMAL_PAGE 4

typedef uint32_t u32;
typedef bool bool_t;

struct p2m_domain;
typedef struct p2m_domain p2m_domain_t;

typedef enum {
    p2m_populate_on_demand
} p2m_type_t;

typedef struct {
    p2m_type_t sa_p2mt;
    uint64_t mfn;
} ept_entry_t;

#define ASSERT(x) ((void)0)

static ept_entry_t* ept_set_middle_entry(p2m_domain_t *p2m, ept_entry_t *ept_entry);
static bool_t is_epte_present(const ept_entry_t *e);
static bool_t is_epte_superpage(const ept_entry_t *e);
static ept_entry_t atomic_read_ept_entry(ept_entry_t *ept_entry);
static void unmap_domain_page(ept_entry_t *table);
static ept_entry_t* map_domain_page(uint64_t mfn);
static uint64_t _mfn(uint64_t mfn);