#include <sys/types.h>
#include <stddef.h>

typedef struct chunk_t {
  size_t memlen;
  char *mem;
  char *data;
#ifdef DEBUG_CHUNK_ALLOC
  size_t DBG_alloc;
#endif
} chunk_t;

extern size_t total_bytes_allocated_in_chunks;

#define CHUNK_ALLOC_SIZE(sz) ((sz) + sizeof(chunk_t))
#define tor_assert(cond) do { if (!(cond)) abort(); } while (0)
static void *tor_realloc(void *ptr, size_t sz);

#define INLINE inline