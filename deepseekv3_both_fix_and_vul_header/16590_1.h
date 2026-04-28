#include <stdbool.h>

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x)   __builtin_expect(!!(x), 1)
#define BUG_ON(condition) do { if (condition) ; } while (0)
#define INVALID_P2M_ENTRY (~0UL)
#define IDENTITY_FRAME(pfn) (pfn)
#define PG_LEVEL_4K 0
#define PAGE_SHIFT 12
#define PFN_DOWN(x) ((x) >> PAGE_SHIFT)

typedef struct {
    unsigned long pte;
} pte_t;

extern unsigned long *xen_p2m_addr;
extern unsigned long xen_p2m_size;
extern unsigned long p2m_missing;
extern unsigned long p2m_identity;

unsigned long __pa(unsigned long);
pte_t *lookup_address(unsigned long, unsigned int *);
bool xen_safe_write_ulong(unsigned long *, unsigned long);
unsigned long pte_pfn(pte_t);