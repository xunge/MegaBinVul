#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define __cold
#define __must_hold(x)
#define u32 uint32_t
#define atomic_read(x) atomic_load(x)

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)

#define list_empty(head) ((head)->next == (head))

#define list_del_init(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
    (entry)->next = (entry)->prev = (entry); \
} while (0)

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); \
})

struct io_ring_ctx {
    struct list_head timeout_list;
    uint32_t cached_cq_tail;
    atomic_uint cq_timeouts;
    uint32_t cq_last_tm_flush;
    int timeout_lock;
    int completion_lock;
};

struct io_kiocb {
    struct {
        struct list_head list;
        uint32_t target_seq;
    } timeout;
};

static inline bool io_is_timeout_noseq(struct io_kiocb *req) { return false; }
static inline void io_kill_timeout(struct io_kiocb *req, int flags) {}
static inline void spin_lock_irq(int *lock) {}
static inline void spin_unlock_irq(int *lock) {}