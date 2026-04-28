#include <stdlib.h>
#include <stddef.h>

typedef struct chunk_t {
    struct chunk_t *next;
    size_t datalen;
    size_t memlen;
    char *data;
    char mem[];
#ifdef DEBUG_CHUNK_ALLOC
    size_t DBG_alloc;
#endif
} chunk_t;

extern size_t total_bytes_allocated_in_chunks;

#define CHUNK_SIZE_WITH_ALLOC(alloc) ((alloc) - offsetof(chunk_t, mem))
#define INLINE inline

void *tor_malloc(size_t size);