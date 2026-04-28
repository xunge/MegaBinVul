#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};
struct kioctx {
    struct list_head ctx_lock;
    int reqs_active;
};
struct kiocb_batch {
    struct list_head head;
};
struct kiocb {
    struct list_head ki_batch;
    struct list_head ki_list;
};
extern struct kmem_cache *kiocb_cachep;

#define list_empty(list) ((list)->next == (list))
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(pos))((char *)(head)->next - offsetof(typeof(*pos), member)), \
        n = (typeof(pos))((char *)pos->member.next - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = n, n = (typeof(pos))((char *)n->member.next - offsetof(typeof(*pos), member)))
#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

static inline void spin_lock_irq(struct list_head *lock) {}
static inline void spin_unlock_irq(struct list_head *lock) {}
void kmem_cache_free(struct kmem_cache *cachep, void *objp);