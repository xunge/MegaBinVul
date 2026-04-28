#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

#define LOGW(...)
#define LOGE(...)
#define LOGI(...)

typedef struct {
    void* addr;
    size_t length;
} MappedRange;

typedef struct {
    void* addr;
    size_t length;
    unsigned int range_count;
    MappedRange* ranges;
} MemMapping;

#define mmap64 mmap
#define off64_t off_t