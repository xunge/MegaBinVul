#include <stddef.h>
#include <stdlib.h>

struct _reent;
struct alloc_info_t {
    size_t size;
    unsigned int signature;
};
struct heap_stats_t {
    size_t current_size;
    size_t max_size;
    size_t total_size;
    size_t overhead_size;
    size_t alloc_cnt;
    size_t alloc_fail_cnt;
};

extern struct heap_stats_t heap_stats;
extern void* __real__malloc_r(struct _reent *r, size_t size);
extern void mbed_mem_trace_lock(void);
extern void mbed_mem_trace_unlock(void);
extern void mbed_mem_trace_malloc(void *ptr, size_t size, void *caller);

#define MBED_HEAP_STATS_SIGNATURE 0xDEADBEEF
#define MALLOC_HEAP_TOTAL_SIZE(ptr) (0)
#define MALLOC_HEADER_PTR(ptr) (ptr)