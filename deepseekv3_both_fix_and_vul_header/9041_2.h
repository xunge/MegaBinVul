#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;
typedef unsigned long xen_pfn_t;

#define MAX_ORDER 20
#define TRC_MEM_DECREASE_RESERVATION 0
#define unlikely(x) (x)

struct domain {
    int domain_id;
    struct domain *domain;
};

struct memop_args {
    unsigned long nr_done;
    unsigned long nr_extents;
    unsigned int extent_order;
    int preempted;
    struct domain *domain;
    void *extent_list;
};

extern int tb_init_done;
extern int guest_handle_subrange_okay(void *, unsigned long, unsigned long);
extern int hypercall_preempt_check(void);
extern int __copy_from_guest_offset(xen_pfn_t *, void *, unsigned long, unsigned long);
extern void __trace_var(int, int, size_t, void *);
extern int is_hvm_domain(struct domain *);
extern int p2m_pod_decrease_reservation(struct domain *, xen_pfn_t, unsigned int);
extern int guest_remove_page(struct domain *, xen_pfn_t);
extern unsigned int max_order(struct domain *);
extern struct domain *current;