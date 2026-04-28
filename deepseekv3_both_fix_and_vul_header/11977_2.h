#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    const uint8_t *data;
    size_t size;
} GVariantSerialised;

struct Offsets {
    size_t offset_size;
    size_t data_size;
    const uint8_t *array;
    size_t length;
    bool is_normal;
};

#define TRUE true
#define FALSE false
typedef size_t gsize;

size_t gvs_get_offset_size(size_t size);
size_t gvs_read_unaligned_le(const uint8_t *data, size_t offset_size);