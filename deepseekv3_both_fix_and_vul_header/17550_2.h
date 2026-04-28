#include <stdint.h>
#include <stdatomic.h>

typedef struct {
    _Atomic uint32_t cnts;
} rwlock_t;

#define likely(x)       __builtin_expect(!!(x), 1)
#define preempt_disable() 
#define preempt_enable() 

#define _QR_BIAS (1U << 31)
#define u32 uint32_t

static inline int _can_read_lock(uint32_t cnts) {
    return !(cnts & _QR_BIAS);
}

#define atomic_read(v) atomic_load_explicit(v, memory_order_relaxed)
#define atomic_add_return(i, v) (atomic_fetch_add_explicit(v, i, memory_order_acquire) + i)
#define atomic_sub(i, v) atomic_fetch_sub_explicit(v, i, memory_order_release)