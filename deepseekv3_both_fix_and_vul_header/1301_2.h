#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define WINDOW_MIN_US 50000
#define WINDOW_MAX_US 10000000
#define UPDATES_PER_WINDOW 10
#define NSEC_PER_USEC 1000L
#define GFP_KERNEL 0

#define ERR_PTR(err) ((void *)(long)(err))
#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)(-1000))
#define ERR_CAST(ptr) ((void *)(ptr))

#define EOPNOTSUPP 95
#define EINVAL 22
#define ENOMEM 12

typedef uint32_t u32;
typedef uint64_t u64;

enum psi_res {
    PSI_IO,
    PSI_MEM,
    PSI_CPU,
    NR_PSI_RESOURCES
};

enum psi_states {
    PSI_IO_SOME,
    PSI_IO_FULL,
    PSI_MEM_SOME,
    PSI_MEM_FULL,
    PSI_CPU_SOME,
    PSI_CPU_FULL,
    PSI_NONIDLE,
    NR_PSI_STATES
};

struct psi_window {
    u64 size;
};

struct list_head {
    struct list_head *next, *prev;
};

struct psi_trigger {
    struct psi_group *group;
    enum psi_states state;
    u64 threshold;
    struct psi_window win;
    int event_wait;
    u64 event;
    u64 last_event_time;
    int refcount;
    struct list_head node;
};

struct psi_group {
    int trigger_lock;
    struct list_head triggers;
    void *poll_task;
    int poll_wakeup;
    u64 poll_min_period;
    unsigned long poll_states;
    int nr_triggers[NR_PSI_STATES];
};

static bool psi_disabled = false;
#define static_branch_likely(x) (*(x))

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
void mutex_lock(int *lock);
void mutex_unlock(int *lock);
void *kthread_create(void *func, void *data, const char *name);
void wake_up_process(void *task);
void rcu_assign_pointer(void *p, void *v);
void *rcu_access_pointer(void *p);
void list_add(struct list_head *new, struct list_head *head);
u64 div_u64(u64 dividend, unsigned int divisor);
void window_reset(struct psi_window *win, int a, int b, int c);
void init_waitqueue_head(int *q);
void kref_init(int *ref);
void atomic_set(int *v, int i);
void psi_poll_worker(void *data);

#define min(a, b) ((a) < (b) ? (a) : (b))