#include <stdatomic.h>

struct spinlock {
    atomic_flag locked;
};

struct futex_key {
    atomic_uint refcount;
    void *pointer;
    unsigned long offset;
};

struct futex_q {
    struct futex_key key;
};

struct futex_hash_bucket {
    struct spinlock lock;
};

void spin_unlock(struct spinlock *lock);
void drop_futex_key_refs(struct futex_key *key);