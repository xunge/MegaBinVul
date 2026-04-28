#include <stdatomic.h>
#include <pthread.h>
#include <limits.h>
#include <stdbool.h>

struct key_user {
    atomic_int nikeys;
};

struct key_type {
    int (*instantiate)(struct key *key, struct key_preparsed_payload *prep);
};

struct key_preparsed_payload {
    time_t expiry;
};

struct key {
    struct key_type *type;
    struct key_user *user;
    unsigned long flags;
    int state;
    time_t expiry;
};

struct assoc_array_edit;

extern pthread_mutex_t key_construction_mutex;
extern unsigned long key_gc_delay;

#define KEY_FLAG_USER_CONSTRUCT 0
#define KEY_FLAG_INSTANTIATED 1
#define KEY_FLAG_KEEP 2
#define KEY_IS_UNINSTANTIATED 0
#define EBUSY 16
#define TIME_T_MAX LONG_MAX

static inline void key_check(const struct key *key) {}
static inline void mark_key_instantiated(struct key *key, int flag) {}
static inline void __key_link(struct key *key, struct assoc_array_edit **edit) {}
static inline void key_revoke(struct key *key) {}
static inline void key_schedule_gc(time_t expiry) {}
static inline void wake_up_bit(unsigned long *flags, int bit) {}

static inline void mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static inline void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static inline bool test_bit(int nr, const unsigned long *addr) { return (*addr & (1UL << nr)) != 0; }
static inline void set_bit(int nr, unsigned long *addr) { *addr |= (1UL << nr); }
static inline bool test_and_clear_bit(int nr, unsigned long *addr) {
    bool ret = test_bit(nr, addr);
    *addr &= ~(1UL << nr);
    return ret;
}