#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define unlikely(x) (x)
#define _PAGE_PRESENT (1UL << 0)
#define EINVAL 22
#define PGT_l2_page_table 2

typedef uint64_t l3_pgentry_t;

struct domain;

unsigned long l3e_get_flags(l3_pgentry_t l3e);
unsigned long l3e_get_pfn(l3_pgentry_t l3e);
unsigned long l3_disallow_mask(struct domain *d);
int get_page_and_type_from_pagenr(unsigned long pfn, int type, struct domain *d, int partial, int preemptible);
int get_l3_linear_pagetable(l3_pgentry_t l3e, unsigned long pfn, struct domain *d);

#define MEM_LOG(fmt, ...)