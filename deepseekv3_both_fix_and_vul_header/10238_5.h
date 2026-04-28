#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define XEN_GUEST_HANDLE(type) void*

typedef uint64_t xen_pfn_t;

struct xen_memory_exchange {
    struct {
        uint32_t domid;
        uint32_t nr_extents;
        uint32_t extent_order;
        uint32_t mem_flags;
        XEN_GUEST_HANDLE(xen_pfn_t) extent_start;
    } in, out;
    uint64_t nr_exchanged;
};

struct page_list_head {
    void *next, *prev;
};
#define PAGE_LIST_HEAD_INIT(name) { &(name), &(name) }
#define PAGE_LIST_HEAD(name) struct page_list_head name = PAGE_LIST_HEAD_INIT(name)

struct page_info;
struct domain {
    bool is_dying;
    struct {
        unsigned long tot_pages;
    } page_alloc;
    struct {
        struct page_list_head page_alloc_lock;
    } page_alloc_lock;
};

#define MEMF_no_refcount (1U << 0)
#define MEMF_no_owner (1U << 1)
#define MEMF_bits(x) ((x) << 2)
#define MEMF_node(x) ((x) << 10)

#define _PGC_allocated 0
#define PGC_allocated (1U << _PGC_allocated)

#define BUG() do { } while (0)
#define BUG_ON(cond) do { if (cond) BUG(); } while (0)

#define unlikely(x) (x)
#define likely(x) (x)

#define XSM_TARGET 0
#define XENMEM_exchange 0
#define __HYPERVISOR_memory_op 0

#define PAGE_SHIFT 12
#define BITS_PER_LONG (sizeof(long) * 8)

#define XENMEMF_address_bits_mask 0xff
#define XENMEMF_node_shift 8
#define XENMEMF_node_mask 0xff

#define XENMEMF_get_address_bits(x) ((x) & XENMEMF_address_bits_mask)
#define XENMEMF_get_node(x) (((x) >> XENMEMF_node_shift) & XENMEMF_node_mask)

#define SHARED_M2P(x) (0)

#define mfn_x(x) (x)
#define _mfn(x) (x)
#define mfn_valid(x) (1)
#define _gfn(x) (x)
#define gfn_to_mfn(d, gfn) (gfn)
#define get_gfn_unshare(d, gfn, p2mt) (0)
#define put_gfn(d, gfn) do { } while (0)
#define p2m_is_shared(x) (0)
#define mfn_to_page(x) ((struct page_info *)NULL)
#define page_to_mfn(x) (0)
#define mfn_to_gmfn(d, mfn) (mfn)
#define steal_page(d, page, flags) (0)
#define page_list_add(page, head) do { } while (0)
#define page_list_remove_head(head) (NULL)
#define alloc_domheap_pages(d, order, flags) (NULL)
#define free_domheap_pages(page, order) do { } while (0)
#define assign_pages(d, page, order, flags) (0)
#define domain_adjust_tot_pages(d, delta) (0)
#define put_domain(d) do { } while (0)
#define put_page(page) do { } while (0)
#define set_gpfn_from_mfn(mfn, gpfn) do { } while (0)
#define guest_physmap_add_page(d, gfn, mfn, order) do { } while (0)
#define guest_physmap_remove_page(d, gfn, mfn, order) do { } while (0)
#define paging_mode_translate(d) (0)
#define domain_clamp_alloc_bitsize(d, bits) (bits)
#define max_order(d) (0)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define test_and_clear_bit(nr, addr) (0)
#define clear_bit(nr, addr) do { } while (0)
#define spin_lock(lock) do { } while (0)
#define spin_unlock(lock) do { } while (0)
#define rcu_lock_domain_by_any_id(id) (NULL)
#define rcu_unlock_domain(d) do { } while (0)
#define hypercall_preempt_check() (0)
#define hypercall_create_continuation(op, fmt, ...) (0)
#define current ((struct domain *)NULL)
#define copy_from_guest(dst, src, nr) (0)
#define __copy_from_guest_offset(dst, src, off, nr) (0)
#define __copy_to_guest_offset(dst, off, src, nr) (0)
#define __copy_field_to_guest(dst, src, field) (0)
#define guest_handle_subrange_okay(hnd, first, last) (1)
#define guest_handle_okay(hnd, nr) (1)
#define xsm_memory_exchange(perm, d) (0)

typedef bool bool_t;