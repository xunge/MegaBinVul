#include <stddef.h>

#define ASSERT(cond) ((void)0)

struct list_head {
    struct list_head *next, *prev;
};

struct timer {
    // dummy definition
};

struct hvm_vcpu {
    int tm_lock;
    struct list_head tm_list;
};

struct arch_vcpu {
    struct hvm_vcpu hvm_vcpu;
};

struct vcpu {
    int processor;
    struct arch_vcpu arch;
};

struct periodic_time {
    int source;
    struct vcpu *vcpu;
    int on_list;
    struct list_head list;
    struct timer timer;
};

static void list_del(struct list_head *entry) {}
static void list_add(struct list_head *new, struct list_head *head) {}
static void migrate_timer(struct timer *timer, int processor) {}
static void pt_lock(struct periodic_time *pt) {}
static void pt_unlock(struct periodic_time *pt) {}
static void spin_lock(int *lock) {}
static void spin_unlock(int *lock) {}

#define PTSRC_isa 0