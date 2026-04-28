#include <stddef.h>
#include <stdint.h>

typedef uint64_t mfn_t;
#define INVALID_MFN 0
#define mfn_eq(a, b) ((a) == (b))
#define mfn_x(mfn) (mfn)

struct p2m_domain {
    unsigned int default_access;
};

typedef struct ept_entry {
    uint64_t epte;
    uint64_t mfn;
    unsigned int access;
    unsigned int r:1;
    unsigned int w:1;
    unsigned int x:1;
    unsigned int a:1;
    unsigned int suppress_ve:1;
} ept_entry_t;

#define EPT_PAGETABLE_ENTRIES 512

mfn_t p2m_alloc_ptp(struct p2m_domain *p2m, int level);
ept_entry_t *map_domain_page(mfn_t mfn);
int cpu_has_vmx_ept_ad;