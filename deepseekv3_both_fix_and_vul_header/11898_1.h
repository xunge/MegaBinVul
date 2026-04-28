#include <stddef.h>
#include <stdlib.h>

#define __init
typedef unsigned long paddr_t;
typedef unsigned long mfn_t;

#define CONFIG_X86
#define PAGE_SHIFT 12
#define MAX_ORDER 11
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

struct frame_table_entry {
    union {
        struct {
            unsigned long first_dirty;
        } free;
        unsigned long u;
    } u;
};

extern struct frame_table_entry *frame_table;
extern mfn_t first_valid_mfn;
extern const char *opt_badpage;
extern int xen_guest;

struct platform_bad_page {
    unsigned long mfn;
    unsigned int order;
};

paddr_t round_pgup(paddr_t addr);
paddr_t round_pgdown(paddr_t addr);
mfn_t maddr_to_mfn(paddr_t addr);
mfn_t mfn_min(mfn_t a, mfn_t b);
void bootmem_region_add(unsigned long start, unsigned long end);
void bootmem_region_zap(unsigned long start, unsigned long end);
const struct platform_bad_page *get_platform_badpages(unsigned int *size);
const struct platform_bad_page *hypervisor_reserved_pages(unsigned int *size);
unsigned long simple_strtoul(const char *cp, const char **endp, unsigned int base);