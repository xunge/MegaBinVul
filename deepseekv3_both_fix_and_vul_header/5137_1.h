#include <stdio.h>

struct seq_file;
struct cfs_rq;
struct rq;

#define rcu_read_lock() 
#define rcu_read_unlock()

#define for_each_leaf_cfs_rq(rq, cfs_rq) \
    for (cfs_rq = NULL; cfs_rq; cfs_rq = NULL)

#define for_each_leaf_cfs_rq_safe(rq, cfs_rq, pos) \
    for (cfs_rq = NULL, pos = NULL; cfs_rq; cfs_rq = NULL, pos = NULL)

static inline struct rq *cpu_rq(int cpu) { return NULL; }
static inline void print_cfs_rq(struct seq_file *m, int cpu, struct cfs_rq *cfs_rq) {}