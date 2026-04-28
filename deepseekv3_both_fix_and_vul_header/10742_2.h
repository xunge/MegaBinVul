#include <stddef.h>

struct radix_tree_root {
    void *rnode;
};

struct domain {
    struct radix_tree_root pirq_tree;
    unsigned int nr_pirqs;
};

struct pirq {
    unsigned int pirq;
    int masked;
    int evtchn;
};

extern int evtchn_port_is_masked(struct domain *d, int port);
extern int evtchn_from_port(struct domain *d, int port);
extern void pirq_guest_eoi(struct pirq *pirq);
extern size_t radix_tree_gang_lookup(struct radix_tree_root *root, void **results, unsigned long first_index, unsigned int max_items);

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))