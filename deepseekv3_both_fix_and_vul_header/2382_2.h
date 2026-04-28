#include <stddef.h>
#include <stdint.h>

struct key {
    unsigned long flags;
    uint64_t expiry;
};

struct key_preparsed_payload {
    size_t datalen;
    uint64_t expiry;
    struct {
        void *data[1];
    } payload;
};

struct user_key_payload {
    struct {
        struct user_key_payload *next;
        void (*func)(struct user_key_payload *);
    } rcu;
};

#define KEY_FLAG_NEGATIVE (0)

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return (*addr >> nr) & 1;
}

static inline int key_payload_reserve(struct key *key, size_t datalen) {
    return 0;
}

static inline struct user_key_payload *dereference_key_locked(struct key *key) {
    return NULL;
}

static inline void rcu_assign_keypointer(struct key *key, void *data) {
}

static void user_free_payload_rcu(struct user_key_payload *payload) {
}

static inline void call_rcu(struct user_key_payload *rcu, 
                          void (*func)(struct user_key_payload *)) {
}