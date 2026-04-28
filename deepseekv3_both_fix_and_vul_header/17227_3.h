#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <stddef.h>

typedef unsigned int refcount_t;
typedef unsigned int uid_t;
typedef int rwlock_t;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct key {
    char *description;
    unsigned long flags;
    struct user_struct *user;
    refcount_t usage;
    time_t last_used_at;
    struct list_head name_link;
};

struct user_struct {
    uid_t uid;
};

struct list_head keyring_name_hash[1];
rwlock_t keyring_name_lock;

#define ERR_PTR(err) ((void *)(long)(err))
#define EINVAL 22
#define ENOKEY 126
#define KEY_FLAG_REVOKED 0
#define KEY_FLAG_UID_KEYRING 1
#define KEY_NEED_SEARCH 1

static inline int keyring_hash(const char *name) { return 0; }
static inline bool kuid_has_mapping(void *ns, uid_t uid) { return true; }
static inline int test_bit(int nr, unsigned long *addr) { return 0; }
static inline int key_permission(void *ref, int perm) { return 0; }
static inline void *make_key_ref(struct key *keyring, int flags) { return keyring; }
static inline bool refcount_inc_not_zero(refcount_t *r) { return true; }
static inline struct timespec current_kernel_time(void) { struct timespec ts = {0}; return ts; }
static inline void read_lock(rwlock_t *lock) {}
static inline void read_unlock(rwlock_t *lock) {}
static inline void *current_user_ns(void) { return NULL; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (struct key *)((char *)(head)->next - offsetof(struct key, member)); \
         &pos->member != (head); \
         pos = (struct key *)((char *)pos->member.next - offsetof(struct key, member)))