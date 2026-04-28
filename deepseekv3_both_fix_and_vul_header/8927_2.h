#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

#define noinline __attribute__((noinline))
#define KEY_FLAG_INSTANTIATED 0
#define KEY_FLAG_NEGATIVE 1
#define KEY_FLAG_IN_QUOTA 2
#define KEY_DEBUGGING 1
#define KEY_DEBUG_MAGIC_X 0x12345678

struct list_head {
    struct list_head *next, *prev;
};

#define list_empty(list) ((list)->next == (list))
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_del(entry) \
    do { \
        (entry)->next->prev = (entry)->prev; \
        (entry)->prev->next = (entry)->next; \
    } while (0)

struct key {
    struct list_head graveyard_link;
    unsigned int serial;
    unsigned long flags;
    bool instantiated;
    struct key_type *type;
    struct key_user *user;
    unsigned int quotalen;
    char *description;
#ifdef KEY_DEBUGGING
    unsigned int magic;
#endif
};

struct key_user {
    atomic_int lock;
    unsigned int qnkeys;
    unsigned int qnbytes;
    atomic_int nkeys;
    atomic_int nikeys;
};

struct key_type {
    void (*destroy)(struct key *);
};

static inline void spin_lock(atomic_int *lock) {
    while (atomic_exchange(lock, 1)) {}
}

static inline void spin_unlock(atomic_int *lock) {
    atomic_store(lock, 0);
}

static inline int test_bit(int nr, volatile unsigned long *addr) {
    return (*addr >> nr) & 1;
}

static inline void atomic_dec(atomic_int *v) {
    atomic_fetch_sub(v, 1);
}

extern struct kmem_cache *key_jar;
extern void key_check(const struct key *);
extern void key_user_put(struct key_user *);
extern void security_key_free(struct key *);
extern void kdebug(const char *, ...);
extern void kmem_cache_free(struct kmem_cache *, void *);
extern void kfree(void *);