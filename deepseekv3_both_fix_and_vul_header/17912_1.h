#include <stdatomic.h>

struct task_struct {
    struct mm_struct *mm;
    struct signal_struct *signal;
};

struct mm_struct {
    atomic_int oom_disable_count;
    unsigned long nr_ptes;
};

struct signal_struct {
    int oom_score_adj;
};

struct mem_cgroup;

typedef struct { 
    unsigned long bits[1]; 
} nodemask_t;

#define MM_SWAPENTS 0
#define CAP_SYS_ADMIN 0

unsigned int oom_unkillable_task(struct task_struct *p, struct mem_cgroup *mem, const nodemask_t *nodemask);
struct task_struct *find_lock_task_mm(struct task_struct *p);
void task_unlock(struct task_struct *p);
int get_mm_rss(struct mm_struct *mm);
int get_mm_counter(struct mm_struct *mm, int counter);
int has_capability_noaudit(struct task_struct *p, int cap);