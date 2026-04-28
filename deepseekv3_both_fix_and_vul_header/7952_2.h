#include <stdatomic.h>
#include <stdint.h>
#include <time.h>

struct assoc_array_edit;

struct keyring_index_key {
    unsigned hash;
    const char *description;
    size_t desc_len;
};

struct key_user {
    atomic_int nikeys;
};

struct key {
    unsigned long flags;
    struct key_user *user;
    int reject_error;
    time_t expiry;
    struct keyring_index_key index_key;
    int (*restrict_link)(struct key *keyring);
};

extern struct {
    int lock;
} key_construction_mutex;
extern unsigned long key_gc_delay;

#define KEY_FLAG_INSTANTIATED 0
#define KEY_FLAG_NEGATIVE 1
#define KEY_FLAG_USER_CONSTRUCT 2

#define EBUSY 16
#define EPERM 1

static inline void key_check(struct key *key) {}
static inline int __key_link_begin(struct key *keyring, struct keyring_index_key *index_key, struct assoc_array_edit **edit) { return 0; }
static inline void __key_link(struct key *key, struct assoc_array_edit **edit) {}
static inline void __key_link_end(struct key *keyring, struct keyring_index_key *index_key, struct assoc_array_edit *edit) {}
static inline void key_schedule_gc(time_t expiry) {}
static inline void key_revoke(struct key *key) {}
static inline struct timespec current_kernel_time(void) { struct timespec ts = {0}; return ts; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void set_bit(int nr, volatile unsigned long *addr) {}
static inline int test_and_clear_bit(int nr, volatile unsigned long *addr) { return 0; }
static inline void wake_up_bit(const void *word, int bit) {}
static inline void smp_wmb(void) {}
static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}