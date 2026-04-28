#include <stdatomic.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    _Atomic u32 cnts;
} rwlock_t;

#define _write_lock_val() (0x80000000)
#define unlikely(x) (x)
#define preempt_disable()
#define preempt_enable()

static inline u32 atomic_read(const _Atomic u32 *obj) {
    return atomic_load(obj);
}

static inline u32 atomic_cmpxchg(_Atomic u32 *obj, u32 expected, u32 desired) {
    atomic_compare_exchange_strong(obj, &expected, desired);
    return expected;
}