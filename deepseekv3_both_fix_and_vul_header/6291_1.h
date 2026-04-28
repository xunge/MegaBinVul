#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct ok_csv_circular_buffer {
    uint8_t *data;
    size_t capacity;
    size_t length;
    size_t start;
} ok_csv_circular_buffer;

static size_t ok_csv_circular_buffer_readable(ok_csv_circular_buffer *buffer) {
    return buffer->length - buffer->start;
}