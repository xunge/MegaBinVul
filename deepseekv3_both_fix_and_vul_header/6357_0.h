#include <assert.h>
#include <stddef.h>

#define SIXELAPI
#define SIXEL_ALLOCATE_BYTES_MAX (1024 * 1024 * 1024)

typedef struct sixel_allocator {
    void *(*fn_realloc)(void *, size_t);
} sixel_allocator_t;

void sixel_helper_set_additional_message(const char *message);