#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    void* addr;
    size_t length;
} MappedRange;

typedef struct {
    void* addr;
    size_t length;
    int range_count;
    MappedRange* ranges;
} MemMapping;