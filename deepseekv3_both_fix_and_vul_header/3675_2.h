#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

struct kioctx {
    unsigned nr_events;
    void *ring_pages[0];
    int ring_lock;
};

struct aio_ring {
    unsigned head;
    unsigned tail;
};

struct io_event {
    // io_event fields would be defined here
};

struct page {
    // page fields would be defined here
};

#define PAGE_SIZE 4096
#define AIO_EVENTS_PER_PAGE (PAGE_SIZE / sizeof(struct io_event))
#define AIO_EVENTS_OFFSET (PAGE_SIZE / sizeof(struct io_event))

#define mutex_lock(lock) (void)0
#define mutex_unlock(lock) (void)0
#define kmap_atomic(page) ((void *)0)
#define kunmap_atomic(addr) (void)0
#define kmap(page) ((void *)0)
#define kunmap(page) (void)0
#define flush_dcache_page(page) (void)0
#define unlikely(x) (x)
#define pr_debug(fmt, ...) (void)0
#define __user

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define min_t(type, a, b) min((type)(a), (type)(b))