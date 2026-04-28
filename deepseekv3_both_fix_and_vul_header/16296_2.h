#include <stddef.h>

struct task_struct {
    struct numa_group *numa_group;
    unsigned long *numa_faults;
    unsigned long total_numa_faults;
};

struct numa_group {
    unsigned long lock;
    unsigned long *faults;
    unsigned long total_faults;
    int nr_tasks;
};

#define NR_NUMA_HINT_FAULT_STATS 0
extern int nr_node_ids;

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void RCU_INIT_POINTER(void *p, void *v) {}
static inline void put_numa_group(struct numa_group *grp) {}
static inline void kfree(void *p) {}