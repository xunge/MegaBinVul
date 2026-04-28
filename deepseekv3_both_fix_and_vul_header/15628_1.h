#include <stdint.h>

struct fib6_table {
    uintptr_t tb6_lock;
};

struct fib6_info {
    unsigned long expires;
    unsigned int fib6_flags;
    struct fib6_table *fib6_table;
};

#define RTF_EXPIRES (1 << 0)

static inline void fib6_set_expires_locked(struct fib6_info *f6i, unsigned long expires);
static inline void spin_lock_bh(uintptr_t *lock);
static inline void spin_unlock_bh(uintptr_t *lock);