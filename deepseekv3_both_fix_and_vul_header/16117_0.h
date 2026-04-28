#include <stddef.h>
#include <assert.h>

#define ASSERT assert

enum {
    PTSRC_isa,
    PTSRC_ioapic
};

struct list_head {
    struct list_head *next, *prev;
};

struct timer {
    // timer fields
};

struct pl_time {
    struct list_head pt_migrate;
};

struct hvm {
    struct list_head tm_list;
    struct pl_time *pl_time;
    struct list_head tm_lock;
};

struct arch {
    struct hvm hvm;
};

struct domain {
    struct arch arch;
};

struct vcpu {
    struct arch arch;
    int processor;
    struct domain *domain;
};

struct periodic_time {
    int source;
    struct vcpu *vcpu;
    int on_list;
    struct list_head list;
    struct timer timer;
};

void write_lock(struct list_head *lock);
void write_unlock(struct list_head *lock);
void pt_lock(struct periodic_time *pt);
void pt_unlock(struct periodic_time *pt);
void spin_lock(struct list_head *lock);
void spin_unlock(struct list_head *lock);
void list_del(struct list_head *entry);
void list_add(struct list_head *entry, struct list_head *head);
void migrate_timer(struct timer *timer, int processor);