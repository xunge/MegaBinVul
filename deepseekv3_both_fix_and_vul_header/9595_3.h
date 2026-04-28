#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

#define KEY_FLAG_IN_QUOTA 0
#define KEY_FLAG_INSTANTIATED 1
#define KEY_DEBUG_MAGIC_X 0xdeadbeef
#define noinline __attribute__((noinline))

struct list_head {
    struct list_head *next, *prev;
};

struct key;

struct key_type {
    void (*destroy)(struct key *);
};

struct key_user {
    atomic_int nkeys;
    atomic_int nikeys;
    unsigned int qnkeys;
    unsigned int qnbytes;
    int lock;
};

struct key {
    struct list_head graveyard_link;
    unsigned int serial;
    unsigned long flags;
    struct key_user *user;
    unsigned int quotalen;
    struct key_type *type;
    char *description;
#ifdef KEY_DEBUGGING
    unsigned int magic;
#endif
};

#define list_empty(list) ((list)->next == (list))
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

#define test_bit(nr, addr) ((*(addr) & (1UL << (nr))) != 0)

extern struct kmem_cache *key_jar;
extern void key_check(const struct key *key);
extern void security_key_free(struct key *key);
extern void key_user_put(struct key_user *user);
extern void kdebug(const char *fmt, ...);
extern void spin_lock(int *lock);
extern void spin_unlock(int *lock);
extern void kfree(void *ptr);
extern void kmem_cache_free(struct kmem_cache *cache, void *ptr);
extern void atomic_dec(atomic_int *v);