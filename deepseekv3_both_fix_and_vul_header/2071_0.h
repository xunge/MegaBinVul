#include <pthread.h>
#include <stddef.h>
#include <stdint.h>

#define BACKTRACE_SIZE 16
#define GUARD 0xDEADBEEF

typedef struct AllocationEntry AllocationEntry;
typedef struct BacktraceEntry BacktraceEntry;

struct BacktraceEntry {
    intptr_t backtrace[BACKTRACE_SIZE];
    size_t numEntries;
    size_t size;
};

struct AllocationEntry {
    BacktraceEntry* entry;
    unsigned int guard;
};

extern void* dlmalloc(size_t bytes);
extern BacktraceEntry* record_backtrace(intptr_t* backtrace, size_t numEntries, size_t size);
extern size_t get_backtrace(intptr_t* backtrace, size_t size);

pthread_mutex_t gAllocationsMutex = PTHREAD_MUTEX_INITIALIZER;