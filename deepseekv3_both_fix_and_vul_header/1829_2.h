#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define fallthrough

enum fscache_cookie_state {
    FSCACHE_COOKIE_STATE_QUIESCENT,
    FSCACHE_COOKIE_STATE_LOOKING_UP,
    FSCACHE_COOKIE_STATE_INVALIDATING,
    FSCACHE_COOKIE_STATE_ACTIVE,
    FSCACHE_COOKIE_STATE_FAILED,
    FSCACHE_COOKIE_STATE_LRU_DISCARDING,
    FSCACHE_COOKIE_STATE_RELINQUISHING,
    FSCACHE_COOKIE_STATE_WITHDRAWING,
    FSCACHE_COOKIE_STATE_DROPPED
};

struct fscache_cache;
struct fscache_cache_ops;

struct fscache_volume {
    struct fscache_cache *cache;
};

struct fscache_cookie {
    unsigned int debug_id;
    enum fscache_cookie_state state;
    atomic_int n_accesses;
    unsigned long flags;
    void *cache_priv;
    struct fscache_volume *volume;
    struct fscache_cache_ops *ops;
    int lock;
};

struct fscache_cache {
    struct fscache_cache_ops *ops;
};

struct fscache_cache_ops {
    void (*withdraw_cookie)(struct fscache_cookie *);
};

enum fscache_access_trace {
    fscache_access_invalidate_cookie_end,
    fscache_cookie_see_relinquish,
    fscache_cookie_see_lru_discard,
    fscache_cookie_see_withdraw
};

#define FSCACHE_COOKIE_DO_RELINQUISH    0
#define FSCACHE_COOKIE_DO_PREP_TO_WRITE 1
#define FSCACHE_COOKIE_DO_LRU_DISCARD   2
#define FSCACHE_COOKIE_DO_WITHDRAW      3
#define FSCACHE_COOKIE_DO_INVALIDATE    4
#define FSCACHE_COOKIE_NEEDS_UPDATE     5
#define FSCACHE_COOKIE_NO_DATA_TO_READ  6

static inline int atomic_read(const atomic_int *v) {
    return atomic_load_explicit(v, memory_order_relaxed);
}

static inline void spin_lock(int *lock) { *lock = 1; }
static inline void spin_unlock(int *lock) { *lock = 0; }
static inline bool test_bit(int nr, unsigned long *addr) { return (*addr & (1UL << nr)) != 0; }
static inline bool test_and_clear_bit(int nr, unsigned long *addr) {
    bool ret = test_bit(nr, addr);
    *addr &= ~(1UL << nr);
    return ret;
}
static inline void clear_bit(int nr, unsigned long *addr) { *addr &= ~(1UL << nr); }
static inline void set_bit(int nr, unsigned long *addr) { *addr |= (1UL << nr); }

#define BUG() do { fprintf(stderr, "BUG at %s:%d\n", __FILE__, __LINE__); abort(); } while(0)
#define WARN_ONCE(cond, fmt, ...) do { \
    if (cond) fprintf(stderr, fmt, ##__VA_ARGS__); \
} while(0)

static void __fscache_set_cookie_state(struct fscache_cookie *cookie,
                                     enum fscache_cookie_state state) {
    cookie->state = state;
}

static void _enter(const char *fmt, ...) {}
static void _leave(const char *fmt, ...) {}