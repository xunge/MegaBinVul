#include <stdatomic.h>

struct sock;
struct file;
struct unix_sock;
struct user_struct;

extern atomic_flag unix_gc_lock;
extern long unix_tot_inflight;

struct list_head {
    struct list_head *next, *prev;
};

struct unix_sock {
    struct list_head link;
    _Atomic long inflight;
};

struct file {
    struct cred *f_cred;
};

struct cred {
    struct user_struct *user;
};

struct user_struct {
    long unix_inflight;
};

static inline void spin_lock(atomic_flag *lock) {
    while (atomic_flag_test_and_set(lock));
}

static inline void spin_unlock(atomic_flag *lock) {
    atomic_flag_clear(lock);
}

#define BUG_ON(cond) do { if (cond) abort(); } while (0)

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry->prev = entry;
}