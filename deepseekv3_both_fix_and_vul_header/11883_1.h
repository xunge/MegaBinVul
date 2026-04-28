#include <stdbool.h>
#include <stddef.h>

typedef struct {
    unsigned long val;
} gfn_t;

#define INVALID_GFN ((gfn_t){ 0 })
#define _PGC_allocated 0
#define PGT_writable_page 0
#define MEMF_no_refcount 0
#define EPERM 1
#define ENOMEM 2
#define ENODATA 3

struct page_info {
    unsigned long count_info;
};

struct hvm_ioreq_page {
    struct page_info *page;
    void *va;
    gfn_t gfn;
};

struct hvm_ioreq_server {
    struct hvm_ioreq_page ioreq;
    struct hvm_ioreq_page bufioreq;
    struct domain *emulator;
};

struct domain;

static bool gfn_eq(gfn_t a, gfn_t b) { return a.val == b.val; }
static struct page_info *alloc_domheap_page(struct domain *d, unsigned int flags) { return NULL; }
static bool get_page_and_type(struct page_info *page, struct domain *d, unsigned int type) { return false; }
static void domain_crash(struct domain *d) {}
static void *__map_domain_page_global(struct page_info *page) { return NULL; }
static void clear_page(void *va) {}
static bool test_and_clear_bit(int nr, unsigned long *addr) { return false; }
static void put_page(struct page_info *page) {}
static void put_page_and_type(struct page_info *page) {}