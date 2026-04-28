#include <stdint.h>

#define RTF_EXPIRES 0x0001

struct fib6_table;
struct fib6_info {
    uint32_t fib6_flags;
    unsigned long expires;
    struct fib6_table *fib6_table;
};

struct fib6_table {
    int tb6_lock;
};

static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline void fib6_clean_expires_locked(struct fib6_info *f6i) {
    f6i->fib6_flags &= ~RTF_EXPIRES;
    f6i->expires = 0;
}