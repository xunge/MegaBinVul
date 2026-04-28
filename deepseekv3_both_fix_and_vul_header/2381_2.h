#include <stdatomic.h>
#include <stddef.h>

#define noinline __attribute__((noinline))

struct list_head {
    struct list_head *next, *prev;
};

#define list_empty(list) ((list)->next == (list))
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

struct key {
    struct list_head graveyard_link;
    short state;
    unsigned int serial;
    unsigned long flags;
    struct key_type *type;
    struct key_user *user;
    unsigned int quotalen;
    char *description;
};

struct key_type {
    void (*destroy)(struct key *);
};

struct key_user {
    atomic_int lock;
    atomic_int nkeys;
    atomic_int nikeys;
    int qnkeys;
    int qnbytes;
};

#define KEY_IS_POSITIVE 1
#define KEY_IS_UNINSTANTIATED 0
#define KEY_FLAG_IN_QUOTA (0)
#define KEY_FLAG_INSTANTIATED (1)
#define KEY_FLAG_NEGATIVE (2)

#define test_bit(nr, addr) ((*(addr)) & (1UL << (nr)))

static inline void spin_lock(atomic_int *lock) {
    while (atomic_exchange(lock, 1)) {}
}

static inline void spin_unlock(atomic_int *lock) {
    atomic_store(lock, 0);
}

static inline void atomic_dec(atomic_int *v) {
    atomic_fetch_sub(v, 1);
}

extern struct kmem_cache *key_jar;
extern void kdebug(const char *fmt, ...);
extern void key_check(const struct key *key);
extern void security_key_free(struct key *key);
extern void key_user_put(struct key_user *user);
extern void kfree(void *ptr);
extern void memzero_explicit(void *s, size_t count);
extern void kmem_cache_free(struct kmem_cache *cachep, void *objp);