#include <stddef.h>

struct futex_key {
    int dummy;  // 假设包含至少一个成员
};
struct futex_hash_bucket {
    int lock;
};
struct futex_q {
    struct futex_key key;
    void *lock_ptr;
};

void get_futex_key_refs(struct futex_key *key);
struct futex_hash_bucket *hash_futex(struct futex_key *key);
void spin_lock(int *lock);