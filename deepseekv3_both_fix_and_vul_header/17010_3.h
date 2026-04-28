#include <stdint.h>
#include <stdlib.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

struct list_head {
    struct list_head *next, *prev;
};

struct v4l2_timecode {
    u32 type;
    u32 flags;
    u8 frames;
    u8 seconds;
    u8 minutes;
    u8 hours;
    u8 userbits[4];
};

struct amvdec_session {
    struct list_head timestamps;
    int ts_spinlock;
};

struct amvdec_timestamp {
    u64 ts;
    struct v4l2_timecode tc;
    u32 offset;
    u32 flags;
    struct list_head list;
};

#define GFP_KERNEL 0
#define ENOMEM 12

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}