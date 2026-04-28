#include <stdlib.h>

struct list_head {
    struct list_head *next, *prev;
};

struct timer {
    int dummy;
};

struct radix_tree_root {
    void *rnode;
};

struct hvm_pirq_dpci {
    unsigned int flags;
    struct timer timer;
    struct list_head digl_list;
    int pirq;
    struct hvm_pirq_dpci *pending_pirq_dpci;
};

struct domain {
    struct radix_tree_root pirq_tree;
};

struct dev_intx_gsi_link {
    struct list_head list;
};

#define pt_irq_need_timer(flags) ((flags) & 0x1)
#define pt_pirq_softirq_active(pirq_dpci) (0)
#define ERESTART (-1)

static inline void kill_timer(struct timer *timer) {}
static inline void xfree(void *ptr) { free(ptr); }
static inline void list_del(struct list_head *entry) {}
static inline void radix_tree_delete(struct radix_tree_root *root, unsigned long index) {}
static inline struct hvm_pirq_dpci *dpci_pirq(struct hvm_pirq_dpci *pirq_dpci) { return pirq_dpci; }
static inline void pirq_guest_unbind(struct domain *d, struct hvm_pirq_dpci *pirq_dpci) {}
static inline struct hvm_pirq_dpci *domain_get_irq_dpci(struct domain *d) { return NULL; }

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((head)->next), \
         n = (typeof(*pos)*)(pos->member.next); \
         &pos->member != (head); \
         pos = n, n = (typeof(*pos)*)(n->member.next))