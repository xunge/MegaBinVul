#include <stddef.h>

struct ctl_table_header {
    struct ctl_dir *parent;
    int nreg;
    int count;
    void *rcu;
};

struct ctl_dir {
    struct ctl_table_header header;
};

static void put_links(struct ctl_table_header *header) {}
static void start_unregistering(struct ctl_table_header *header) {}
static void kfree_rcu(struct ctl_table_header *header, void *rcu_param) {
    header->rcu = rcu_param;
}

#define rcu header->rcu