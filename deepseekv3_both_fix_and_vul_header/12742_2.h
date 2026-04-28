#include <stdint.h>
#include <stdlib.h>

typedef uint64_t u64;
typedef uint32_t __u32;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct io_provide_buf {
    u64 addr;
    __u32 len;
    int bid;
    int nbufs;
};

struct io_buffer {
    u64 addr;
    __u32 len;
    int bid;
    struct list_head list;
};

#define MAX_RW_COUNT 0
#define GFP_KERNEL 0
#define ENOMEM 12

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})