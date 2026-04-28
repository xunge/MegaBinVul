#include <stddef.h>

#define VPF_blocked (1 << 0)

typedef struct spinlock {
    int lock;
} spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct timer {
    // minimal timer definition
    int dummy;
};

struct periodic_time {
    struct list_head list;
    int do_not_freeze;
    struct timer timer;
};

struct vcpu {
    struct {
        struct {
            struct list_head tm_list;
            spinlock_t tm_lock;
        } hvm;
    } arch;
    unsigned int pause_flags;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((char *)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(pos))((char *)pos->member.next - offsetof(typeof(*pos), member)))

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
void stop_timer(struct timer *);
void pt_freeze_time(struct vcpu *);