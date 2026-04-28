#include <stdatomic.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    _Atomic u32 cnts;
} rwlock_t;

#define _QR_BIAS (1U << 2)
#define likely(x) __builtin_expect(!!(x), 1)

static inline void preempt_disable(void) {}
static inline int _can_read_lock(u32 cnts) { return 0; }
static inline void queue_read_lock_slowpath(rwlock_t *lock) {}
static inline u32 atomic_add_return(u32 val, _Atomic u32 *ptr) { return 0; }