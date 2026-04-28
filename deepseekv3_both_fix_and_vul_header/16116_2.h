#include <stddef.h>

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

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
};

struct periodic_time {
    int pending_intr_nr;
    unsigned long scheduled;
    void *timer;
    struct list_head list;
};

void pt_process_missed_ticks(struct periodic_time *pt);
void pt_thaw_time(struct vcpu *v);
void spin_lock(int *lock);
void spin_unlock(int *lock);
void set_timer(void *timer, unsigned long scheduled);