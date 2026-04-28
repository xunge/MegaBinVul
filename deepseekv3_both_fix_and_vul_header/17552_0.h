#include <stdatomic.h>

#define _QW_CPUMASK 0xffff
#define _QW_WMASK 0x10000

typedef struct {
    atomic_int cnts;
} rwlock_t;

#define ASSERT(cond) ((void)0)
#define preempt_enable() ((void)0)

static inline int _is_write_locked_by_me(int cnts);
static inline int atomic_read(atomic_int *v);
static inline void atomic_and(int mask, atomic_int *v);