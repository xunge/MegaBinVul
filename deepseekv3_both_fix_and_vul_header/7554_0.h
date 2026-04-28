#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef void* MemoryPoolHandle;

#define S3_MEMPOOL_INVALID_ARG (-1)
#define ENABLE_LOCKING (1 << 0)
#define MEMPOOL_LOG_DEBUG 0

struct memory_pool_element {
    struct memory_pool_element *next;
};

struct mempool {
    struct memory_pool_element *free_list;
    size_t mempool_item_size;
    unsigned int flags;
    pthread_mutex_t lock;
    void (*log_callback_func)(int, const char*);
};