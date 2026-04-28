#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

#define list_first_entry(ptr, type, member) \
    ((type *)((char *)((ptr)->next) - offsetof(type, member)))

#define list_move(list, head) \
    do { \
        struct list_head *prev = (list)->prev, *next = (list)->next; \
        prev->next = next; \
        next->prev = prev; \
        (list)->next = (head)->next; \
        (list)->prev = (head); \
        (head)->next->prev = (list); \
        (head)->next = (list); \
    } while (0)

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}

struct io_buf_ring {
    unsigned int tail;
};

struct io_ring_ctx {
    void *uring_lock;
    struct list_head io_buffers_cache;
};

struct io_buffer {
    struct list_head list;
};

struct io_buffer_list {
    unsigned int is_mapped;
    unsigned int is_mmap;
    unsigned int buf_nr_pages;
    void **buf_pages;
    struct list_head buf_list;
    struct io_buf_ring *buf_ring;
    unsigned int head;
};

static inline void cond_resched(void) {}
static inline void lockdep_assert_held(void *lock) {}
static inline void kvfree(void *addr) {}
static inline void unpin_user_page(void *page) {}
static inline void folio_put(void *folio) {}
static inline void *virt_to_folio(void *addr) { return addr; }