#include <stdlib.h>
#include <stdio.h>

#define VIDEO_MAX_FRAME 32
#define dprintk(level, fmt, ...) printf(fmt, ##__VA_ARGS__)

struct vm_area_struct {
    void *vm_private_data;
    unsigned long vm_start;
    unsigned long vm_end;
};

struct videobuf_mapping {
    struct videobuf_queue *q;
    int count;
};

struct videobuf_queue {
    int lock;
    struct videobuf_buffer **bufs;
    struct videobuf_qtype_ops *ops;
};

struct videobuf_buffer {
    struct videobuf_mapping *map;
    unsigned long baddr;
};

struct videobuf_qtype_ops {
    void (*buf_release)(struct videobuf_queue *q, struct videobuf_buffer *buf);
};

void mutex_lock(int *lock);
void mutex_unlock(int *lock);
void kfree(void *ptr);