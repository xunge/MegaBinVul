#include <stddef.h>
#include <assert.h>
#include <stdint.h>

#define SIXELAPI

typedef struct sixel_allocator sixel_allocator_t;

struct sixel_allocator {
    void *(*fn_calloc)(size_t, size_t);
};

#define SIXEL_ALLOCATE_BYTES_MAX (SIZE_MAX / 2)

void sixel_helper_set_additional_message(const char *message);