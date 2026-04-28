#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ROCCAT_CBUF_SIZE 16
#define GFP_ATOMIC 0
#define ENOMEM 12

typedef uint8_t u8;

struct mutex {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct roccat_report {
    uint8_t *value;
};

struct roccat_reader {
    unsigned int cbuf_start;
    struct list_head node;
};

struct roccat_device {
    size_t report_size;
    struct roccat_report *cbuf;
    unsigned int cbuf_end;
    struct list_head readers;
    int wait;
    struct mutex cbuf_lock;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (struct roccat_reader *)((head)->next); \
        &pos->member != (head); \
        pos = (struct roccat_reader *)(pos->member.next))

extern struct roccat_device *devices[];

static inline void *kmemdup(const void *src, size_t len, int gfp) {
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static inline void kfree(void *p) {
    free(p);
}

static inline void wake_up_interruptible(int *wait) {}

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}