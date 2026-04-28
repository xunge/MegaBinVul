#include <stddef.h>
#include <errno.h>
#include <string.h>

typedef unsigned long l1_pgentry_t;

#define _PAGE_PRESENT    (1UL<<0)
#define _PAGE_RW         (1UL<<1)
#define PAGE_CACHE_ATTRS (0x1f8UL)
#define FASTPATH_FLAG_WHITELIST (_PAGE_PRESENT|_PAGE_RW|PAGE_CACHE_ATTRS)
#define PAGE_SHIFT 12
#define PAGE_MASK  (~(PAGE_SIZE-1))
#define PAGE_SIZE  (1UL << PAGE_SHIFT)

#define unlikely(x) (x)
#define likely(x)   (x)

#define EFAULT      14
#define EBUSY       16
#define EINVAL      22

struct domain {
    struct vcpu *vcpu;
};

struct vcpu {
    struct domain *domain;
};

struct page_info;

#define MEM_LOG(fmt, ...) 

#define __copy_from_user(dst, src, size) (memcpy(dst, src, size), 0)

#define l1e_get_flags(x) ((x) & PAGE_MASK)
#define l1e_get_pfn(x) ((x) >> PAGE_SHIFT)
#define l1e_from_pfn(pfn, flags) (((pfn) << PAGE_SHIFT) | (flags))
#define l1e_has_changed(o, n, mask) (((o) ^ (n)) & (mask))
#define l1e_flip_flags(l1e, flags) ((l1e) ^= (flags))
#define l1_disallow_mask(d) (0)

#define UPDATE_ENTRY(lvl, pl, ol, nl, mfn, v, a) (1)
#define paging_mode_refcounts(d) (0)
#define paging_mode_translate(d) (0)
#define adjust_guest_l1e(l1e, d) 
#define get_page_from_gfn(d, gfn, t, a) NULL
#define get_page_from_l1e(l1e, d1, d2) (0)
#define put_page_from_l1e(l1e, d) 
#define put_page(p) 
#define page_to_mfn(p) (0)
#define P2M_ALLOC 0
#define ASSERT(x)