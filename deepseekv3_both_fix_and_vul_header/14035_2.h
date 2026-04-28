#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#define PAGE_SHIFT 12
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SIZE 4096
#define PGT_type_mask 0x7F
#define PGT_l1_page_table 0
#define P2M_ALLOC 0
#define GNTST_okay 0
#define GNTST_general_error 1
#define XENLOG_WARNING 1
#define unlikely(x) (x)
#define PRIpte "lx"

struct domain {
    void *vcpu[1];
};

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

typedef uint64_t l1_pgentry_t;

#define l1e_get_pfn(x) ((x) >> PAGE_SHIFT)
#define l1e_get_intpte(x) (x)
#define l1e_empty() 0

static struct page_info *get_page_from_gfn(struct domain *d, unsigned long gmfn, void *null, int p2m_alloc) { return 0; }
static unsigned long page_to_mfn(struct page_info *page) { return 0; }
static void *map_domain_page(unsigned long mfn) { return 0; }
static void unmap_domain_page(void *va) {}
static void put_page(struct page_info *page) {}
static int page_lock(struct page_info *page) { return 1; }
static void page_unlock(struct page_info *page) {}
static void gdprintk(int level, const char *fmt, ...) {}

#define UPDATE_ENTRY(l1, entry, old, new, mfn, vcpu, flags) 1

#define _mfn(x) (x)