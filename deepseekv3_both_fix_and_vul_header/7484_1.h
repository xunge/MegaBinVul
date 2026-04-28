#include <stddef.h>
#include <stdint.h>

struct pipe_inode_info;
struct pipe_buffer {
    void *private;
    unsigned long offset;
    unsigned long len;
    struct page *page;
};

struct watch_queue {
    unsigned long *notes_bitmap;
};

struct page {
    unsigned long index;
};

#define WATCH_QUEUE_NOTE_SIZE 32

static inline void set_bit(unsigned int nr, volatile unsigned long *addr);