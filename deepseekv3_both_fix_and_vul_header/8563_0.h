#include <stdint.h>
#include <stddef.h>

#define NUM_TYPES 10
#define DATA_ALIGNMENT 4
#define ALIGN_TO(x, align) (((x) + (align) - 1) & ~((align) - 1))

static const size_t camera_metadata_type_size[NUM_TYPES] = {
    0, 1, 2, 4, 8, 4, 8, 4, 8, 4
};