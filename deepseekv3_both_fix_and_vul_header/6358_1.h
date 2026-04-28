#include <assert.h>
#include <stddef.h>
#include <stdint.h>

typedef struct sixel_allocator_t sixel_allocator_t;
typedef void *(*sixel_allocator_malloc_t)(size_t n);

struct sixel_allocator_t {
    sixel_allocator_malloc_t fn_malloc;
};

#define SIXEL_ALLOCATE_BYTES_MAX (SIZE_MAX / 2)

void sixel_helper_set_additional_message(const char *message);

#define SIXELAPI