#include <stdatomic.h>

typedef struct {
    atomic_int cnts;
} rwlock_t;

static inline void preempt_disable(void) {}
static inline int _write_lock_val(void) { return 0; }
static inline void queue_write_lock_slowpath(rwlock_t *lock) {}