#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <assert.h>

#define PATH_MAX 4096
#define YR_API
#define YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK 0
#define YR_DEBUG_FPRINTF(level, stream, ...)
#define ERROR_SUCCESS 0

typedef struct YR_MEMORY_BLOCK {
    uint64_t base;
    uint64_t size;
} YR_MEMORY_BLOCK;

typedef struct YR_MEMORY_BLOCK_ITERATOR {
    void* context;
    int last_error;
} YR_MEMORY_BLOCK_ITERATOR;

typedef struct YR_PROC_INFO {
    FILE* maps;
    uint64_t next_block_end;
    uint64_t map_offset;
    uint64_t map_dmaj;
    uint64_t map_dmin;
    uint64_t map_ino;
    char map_path[PATH_MAX];
} YR_PROC_INFO;

typedef struct YR_PROC_ITERATOR_CTX {
    YR_PROC_INFO* proc_info;
    YR_MEMORY_BLOCK current_block;
} YR_PROC_ITERATOR_CTX;

uint64_t yr_min(uint64_t a, uint64_t b);
void yr_get_configuration(int config, void* value);