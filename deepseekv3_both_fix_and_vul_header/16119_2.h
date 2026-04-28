#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct vcpu {
    struct {
        struct {
            struct list_head tm_list;
            int tm_lock;
        } hvm;
    } arch;
    int processor;
};

struct timer {
    int dummy;
};

struct periodic_time {
    struct list_head list;
    struct timer timer;
};

void migrate_timer(struct timer *t, int processor);

#define spin_lock(lock) (void)(lock)
#define spin_unlock(lock) (void)(lock)
#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (void*)(head); pos = (void*)1)