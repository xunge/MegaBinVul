#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef unsigned long mfn_t;
typedef unsigned long gfn_t;
typedef uint32_t p2m_type_t;

#define gfn_x(gfn) (gfn)
#define _mfn(mfn) (mfn)
#define mfn_valid(mfn) (1)
#define PFEC_page_present (1 << 0)
#define PFEC_write_access (1 << 1)
#define BAD_GVA_TO_GFN (0)
#define BAD_GFN_TO_MFN (0)
#define READONLY_GFN (0)
#define INVALID_GFN (0)
#define P2M_ALLOC (0)
#define ASSERT(x) assert(x)

struct paging {
    gfn_t (*gva_to_gfn)(struct vcpu *, void *, unsigned long, uint32_t *);
    int last_write_was_pt;
};

struct vcpu {
    struct domain *domain;
    struct {
        struct paging paging;
    } arch;
};

struct domain {
};

struct page_info {
};

struct sh_emulate_ctxt {
    struct {
    } ctxt;
};

static struct paging *paging_get_hostmode(struct vcpu *v) { return (struct paging *)0; }
static int paging_locked_by_me(struct domain *d) { return 0; }
static struct page_info *get_page_from_gfn(struct domain *d, gfn_t gfn, p2m_type_t *p2mt, int alloc) { return (struct page_info *)0; }
static void put_page(struct page_info *page) {}
static int p2m_is_discard_write(p2m_type_t p2mt) { return 0; }
static int p2m_is_ram(p2m_type_t p2mt) { return 0; }
static mfn_t page_to_mfn(struct page_info *page) { return 0; }
static void x86_emul_pagefault(uint32_t pfec, unsigned long vaddr, void *ctxt) {}
static int sh_mfn_is_a_page_table(mfn_t mfn) { return 0; }