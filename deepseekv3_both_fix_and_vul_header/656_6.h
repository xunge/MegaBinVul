#include <stdlib.h>
#include <errno.h>

struct trace_array_cpu {
    int dummy;
};

struct trace_buffer {
    struct trace_array *tr;
    void *buffer;
    struct trace_array_cpu *data;
};

struct trace_array {
    unsigned int trace_flags;
    struct trace_buffer trace_buffer;
};

enum ring_buffer_flags {
    RB_FL_OVERWRITE
};

#define TRACE_ITER_OVERWRITE 0x1
#define ENOMEM 12

void *ring_buffer_alloc(int size, enum ring_buffer_flags flags);
void ring_buffer_free(void *buffer);
void *alloc_percpu(size_t size);
void set_buffer_entries(struct trace_buffer *buf, int size);
int ring_buffer_size(void *buffer, int cpu);

// 修改函数调用方式
#define alloc_percpu(type) ((type *)alloc_percpu(sizeof(type)))