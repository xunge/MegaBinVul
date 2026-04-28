#include <stdatomic.h>
#include <time.h>
#include <stdint.h>
#include <stddef.h>

struct key_user {
    atomic_int nikeys;
};

struct key {
    int state;
    unsigned long flags;
    struct key_user *user;
    int reject_error;
    time_t expiry;
    void *index_key;
    int restrict_link;
};

struct assoc_array_edit;
struct timespec;

extern int key_construction_mutex;
extern unsigned long key_gc_delay;

#define KEY_IS_UNINSTANTIATED 0
#define KEY_FLAG_USER_CONSTRUCT 0
#define KEY_FLAG_INSTANTIATED 1
#define KEY_FLAG_NEGATIVE 2
#define EBUSY 16
#define EPERM 1

static inline void mutex_lock(int *mutex) { (void)mutex; }
static inline void mutex_unlock(int *mutex) { (void)mutex; }
static inline int test_bit(int nr, unsigned long *addr) { return 0; }
static inline void set_bit(int nr, unsigned long *addr) { (void)nr; (void)addr; }
static inline int test_and_clear_bit(int nr, unsigned long *addr) { return 0; }
static inline void smp_wmb(void) {}

void key_check(struct key *key);
int __key_link_begin(struct key *keyring, void *index_key, struct assoc_array_edit **edit);
void mark_key_instantiated(struct key *key, int error);
struct timespec current_kernel_time(void);
void key_schedule_gc(unsigned long expiry);
void __key_link(struct key *key, struct assoc_array_edit **edit);
void key_revoke(struct key *key);
void __key_link_end(struct key *keyring, void *index_key, struct assoc_array_edit *edit);
void wake_up_bit(void *flags, int bit);