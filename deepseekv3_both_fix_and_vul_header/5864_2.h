#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct _wmem_block_chunk_t wmem_block_chunk_t;
typedef struct _wmem_block_free_t wmem_block_free_t;
typedef struct _wmem_block_allocator_t wmem_block_allocator_t;

typedef bool gboolean;
typedef uint32_t guint32;

#define FALSE false
#define TRUE true

struct _wmem_block_chunk_t {
    guint32 len;
    gboolean last;
    guint32 prev;
    gboolean used;
    gboolean jumbo;
};

struct _wmem_block_free_t {
    wmem_block_chunk_t *prev;
    wmem_block_chunk_t *next;
};

struct _wmem_block_allocator_t {
    wmem_block_chunk_t *master_head;
    wmem_block_chunk_t *recycler_head;
};

#define WMEM_ALIGN_SIZE(size) (((size) + 7) & ~7)
#define WMEM_CHUNK_HEADER_SIZE (sizeof(wmem_block_chunk_t))
#define WMEM_CHUNK_DATA_LEN(chunk) ((chunk)->len - WMEM_CHUNK_HEADER_SIZE)
#define WMEM_CHUNK_NEXT(chunk) ((wmem_block_chunk_t*)((uint8_t*)(chunk) + (chunk)->len))
#define WMEM_GET_FREE(chunk) ((wmem_block_free_t*)((uint8_t*)(chunk) + WMEM_CHUNK_HEADER_SIZE))

static void wmem_block_pop_master(wmem_block_allocator_t *allocator);
static void wmem_block_remove_from_recycler(wmem_block_allocator_t *allocator, wmem_block_chunk_t *chunk);