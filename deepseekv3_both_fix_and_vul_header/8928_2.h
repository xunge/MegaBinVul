#include <stdatomic.h>
#include <stddef.h>

#define KEY_FLAG_INSTANTIATED 0
#define KEY_FLAG_NEGATIVE 1
#define KEY_FLAG_IN_QUOTA 2
#define KEY_DEBUG_MAGIC_X 0xdeadbeef
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
    unsigned int serial;
    unsigned long flags;
    struct key_type *type;
    struct key_user *user;
    unsigned int quotalen;
    char *description;
#ifdef KEY_DEBUGGING
    unsigned int magic;
#endif
};

struct key_type {
    void (*destroy)(struct key *key);
};

struct key_user {
    int lock;
    atomic_int nkeys;
    atomic_int nikeys;
    unsigned int qnkeys;
    unsigned int qnbytes;
};

extern struct kmem_cache *key_jar;
extern void kdebug(const char *fmt, ...);
extern void key_check(const struct key *key);
extern void key_user_put(struct key_user *user);
extern void spin_lock(int *lock);
extern void spin_unlock(int *lock);
extern int test_bit(int nr, volatile unsigned long *addr);
extern void kmem_cache_free(struct kmem_cache *cache, void *obj);
extern void kfree(const void *obj);
extern void security_key_free(struct key *key);