#include <stdbool.h>
#include <stdatomic.h>

struct static_key {
    _Atomic int enabled;
};

#define DEFINE_SPINLOCK(x) atomic_flag x = ATOMIC_FLAG_INIT

typedef unsigned long spinlock_t;
#define spin_lock_irqsave(lock, flags) \
    do { flags = 0; while (atomic_flag_test_and_set_explicit(lock, memory_order_acquire)) {} } while (0)
#define spin_unlock_irqrestore(lock, flags) atomic_flag_clear_explicit(lock, memory_order_release)

void get_random_bytes(void *buf, int nbytes);
void __net_random_once_disable_jump(struct static_key *key);