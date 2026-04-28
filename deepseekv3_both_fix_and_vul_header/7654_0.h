#include <stddef.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    unsigned int signature;
} alloc_info_t;

typedef struct {
    size_t current_size;
    size_t max_size;
    size_t total_size;
    size_t overhead_size;
    size_t alloc_cnt;
    size_t alloc_fail_cnt;
} heap_stats_t;

extern heap_stats_t heap_stats;
extern void* (*SUPER_MALLOC)(size_t);
extern void* (*MALLOC_HEADER_PTR)(void*);
extern size_t (*MALLOC_HEAP_TOTAL_SIZE)(void*);