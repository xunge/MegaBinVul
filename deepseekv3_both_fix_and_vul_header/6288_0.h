#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct ok_csv_circular_buffer {
    uint8_t *data;
    size_t start;
    size_t length;
    size_t capacity;
} ok_csv_circular_buffer;

static size_t ok_csv_circular_buffer_readable(ok_csv_circular_buffer *buffer);