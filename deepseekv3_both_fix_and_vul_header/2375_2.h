#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

struct key_preparsed_payload {
    size_t datalen;
    void *data;
};

struct trusted_key_payload {
    int migratable;
    size_t key_len;
    char *key;
    struct rcu_head {
        struct rcu_head *next;
        void (*func)(struct rcu_head *head);
    } rcu;
};

struct trusted_key_options {
    int keyhandle;
    int pcrlock;
};

struct key {
    unsigned long flags;
    union {
        void *data[0];
    } payload;
};

#define KEY_FLAG_NEGATIVE 1
#define ENOKEY 126
#define EPERM 1
#define EINVAL 22
#define ENOMEM 12
#define GFP_KERNEL 0
#define Opt_update 1

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return (*addr >> nr) & 1;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kzfree(void *p) {
    free(p);
}

static inline void dump_payload(struct trusted_key_payload *p) {}

static inline struct trusted_key_options *trusted_options_alloc(void) {
    return calloc(1, sizeof(struct trusted_key_options));
}

static inline struct trusted_key_payload *trusted_payload_alloc(struct key *key) {
    return calloc(1, sizeof(struct trusted_key_payload));
}

static inline int datablob_parse(char *datablob, struct trusted_key_payload *new_p, struct trusted_key_options *new_o) {
    return 0;
}

static inline int key_seal(struct trusted_key_payload *new_p, struct trusted_key_options *new_o) {
    return 0;
}

static inline int pcrlock(int pcrlock) {
    return 0;
}

static inline void rcu_assign_keypointer(struct key *key, struct trusted_key_payload *new_p) {
    key->payload.data[0] = new_p;
}

static inline void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head)) {
    head->func = func;
    func(head);
}

static inline void trusted_rcu_free(struct rcu_head *rcu) {
    struct trusted_key_payload *p = container_of(rcu, struct trusted_key_payload, rcu);
    free(p);
}

static inline void pr_info(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}