#include <stdint.h>
#include <stdlib.h>

#define WMEM_BLOCK_MAX_ALLOC_SIZE 4096
#define WMEM_JUMBO_HEADER_SIZE sizeof(wmem_block_fast_jumbo_t)
#define WMEM_CHUNK_HEADER_SIZE sizeof(wmem_block_fast_chunk_t)
#define WMEM_ALIGN_SIZE(size) ((size + 7) & ~7)
#define WMEM_BLOCK_SIZE 65536
#define JUMBO_MAGIC 0x4A554D42
#define WMEM_CHUNK_TO_DATA(chunk) ((void*)((uint8_t*)(chunk) + WMEM_CHUNK_HEADER_SIZE))

typedef struct wmem_block_fast_chunk_t wmem_block_fast_chunk_t;
typedef struct wmem_block_fast_block_t wmem_block_fast_block_t;
typedef struct wmem_block_fast_jumbo_t wmem_block_fast_jumbo_t;
typedef struct wmem_block_fast_allocator_t wmem_block_fast_allocator_t;

struct wmem_block_fast_chunk_t {
    uint32_t len;
};

struct wmem_block_fast_block_t {
    wmem_block_fast_block_t *next;
    int32_t pos;
    uint8_t data[];
};

struct wmem_block_fast_jumbo_t {
    wmem_block_fast_jumbo_t *next;
    wmem_block_fast_jumbo_t *prev;
    uint8_t data[];
};

struct wmem_block_fast_allocator_t {
    wmem_block_fast_jumbo_t *jumbo_list;
    wmem_block_fast_block_t *block_list;
};

static void *wmem_alloc(void *allocator, size_t size) {
    return malloc(size);
}

static void wmem_block_fast_new_block(wmem_block_fast_allocator_t *allocator) {
    wmem_block_fast_block_t *block = (wmem_block_fast_block_t*)wmem_alloc(NULL, WMEM_BLOCK_SIZE);
    block->next = allocator->block_list;
    block->pos = sizeof(wmem_block_fast_block_t);
    allocator->block_list = block;
}