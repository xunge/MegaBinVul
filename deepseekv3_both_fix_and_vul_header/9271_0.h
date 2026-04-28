#include <stdint.h>
#include <assert.h>

#define ASSERT(expr) assert(expr)
#define EINVAL 22
#define L1_PAGETABLE_ENTRIES (1UL << 9)
#define SGT_type_mask 0xFF
#define SGT_none 0
#define SGT_dynamic 1

struct domain;
struct spage_info {
    unsigned long type_info;
};

extern int opt_allow_superpage;

unsigned long mfn_to_spage(unsigned long mfn);
int mfn_valid(unsigned long mfn);
void put_spage_pages(void *page);
void *spage_to_page(struct spage_info *spage);
int get_spage_pages(void *page, struct domain *d);
void MEM_LOG(const char *fmt, ...);
unsigned long spage_to_mfn(struct spage_info *spage);
unsigned long cmpxchg(unsigned long *ptr, unsigned long old, unsigned long new);