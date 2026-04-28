#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

struct ctl_table {
    void *data;
    size_t maxlen;
};

struct hstate {
    unsigned long max_huge_pages;
};

extern struct hstate default_hstate;
extern bool hugepages_supported(void);
extern int __nr_hugepages_store_common(bool obey_mempolicy, struct hstate *h, int nid, unsigned long nr_pages, size_t len);
extern int proc_doulongvec_minmax(struct ctl_table *table, int write, void *buffer, size_t *lenp, off_t *ppos);

#define NUMA_NO_NODE (-1)
#define EOPNOTSUPP 95