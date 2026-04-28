#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define EFAULT 14
#define EPERM 1
#define EINVAL 22
#define ESRCH 3
#define ENOMEM 12

typedef uint64_t xen_pfn_t;

struct xen_memory_exchange {
    struct {
        uint32_t domid;
        uint32_t nr_extents;
        uint32_t extent_order;
        uint32_t mem_flags;
        void *extent_start;
    } in, out;
    uint64_t nr_exchanged;
};

#define XENMEMF_get_address_bits(flags) ((flags) & 0xff)
#define XENMEMF_get_node(flags) (((flags) >> 8) & 0xff)

#define PAGE_SHIFT 12
#define BITS_PER_LONG (sizeof(long) * 8)
#define _PGC_allocated 0
#define MEMF_no_refcount (1U << 0)
#define MEMF_no_owner (1U << 1)
#define MEMF_bits(x) ((x) << 2)
#define MEMF_node(x) ((x) << 10)

#define XENMEM_exchange 14
#define __HYPERVISOR_memory_op 17

#define XSM_TARGET 0

struct page_info {
    unsigned long count_info;
};

struct domain {
    bool is_dying;
    struct {
        unsigned long tot_pages;
    } page_alloc;
    struct {
        struct page_info *next;
        struct page_info *prev;
    } page_alloc_lock;
};

#define PAGE_LIST_HEAD(name) struct page_list_head name = { NULL, NULL }

struct page_list_head {
    struct page_info *next;
    struct page_info *prev;
};

typedef unsigned long mfn_t;
typedef unsigned long gfn_t;

#define mfn_x(x) (x)
#define _mfn(x) (x)
#define _gfn(x) (x)
#define gfn_x(x) (x)
#define gfn_to_mfn(d, g) (g)
#define mfn_to_gmfn(d, m) (m)
#define mfn_to_page(mfn) ((struct page_info *)(mfn))
#define page_to_mfn(pg) ((unsigned long)(pg))

#define SHARED_M2P(x) 0
#define p2m_is_shared(x) 0
#define p2m_type_t unsigned int
#define paging_mode_translate(d) 0

#define XEN_GUEST_HANDLE_PARAM(type) void *
#define guest_handle_subrange_okay(h, s, e) 1
#define __copy_from_guest_offset(dst, hnd, off, nr) 0
#define __copy_to_guest_offset(hnd, off, src, nr) 0
#define copy_from_guest(dst, src, nr) 0
#define __copy_field_to_guest(dst, src, field) 0

#define max(a, b) ((a) > (b) ? (a) : (b))
#define max_order(d) 0
#define domain_clamp_alloc_bitsize(d, b) (b)
#define rcu_lock_domain_by_any_id(id) NULL
#define rcu_unlock_domain(d) do {} while (0)
#define xsm_memory_exchange(t, d) 0
#define hypercall_preempt_check() 0
#define hypercall_create_continuation(op, fmt, ...) 0
#define get_gfn_unshare(d, g, t) ({ *(t) = 0; 0; })
#define put_gfn(d, g) do {} while (0)
#define mfn_valid(mfn) 1
#define steal_page(d, p, f) 0
#define page_list_add(p, l) do {} while (0)
#define page_list_remove_head(l) NULL
#define alloc_domheap_pages(d, o, f) NULL
#define assign_pages(d, p, o, f) 0
#define domain_adjust_tot_pages(d, n) 0
#define put_domain(d) do {} while (0)
#define free_domheap_pages(p, o) do {} while (0)
#define guest_physmap_remove_page(d, g, m, o) 0
#define guest_physmap_add_page(d, g, m, o) 0
#define set_gpfn_from_mfn(m, g) do {} while (0)
#define put_page(p) do {} while (0)
#define domain_crash(d) do {} while (0)
#define test_and_clear_bit(n, p) 0
#define BUG_ON(cond) do { if (cond) for(;;); } while (0)
#define BUG() for(;;)

#define current ((struct { struct domain *domain; }){ NULL })
#define spin_lock(l) do {} while (0)
#define spin_unlock(l) do {} while (0)

#define unlikely(x) (x)

typedef bool bool_t;