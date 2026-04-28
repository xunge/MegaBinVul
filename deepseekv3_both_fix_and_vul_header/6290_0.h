#include <stdbool.h>
#include <stddef.h>

typedef struct ok_csv_circular_buffer {
    size_t start;
    size_t length;
    size_t capacity;
} ok_csv_circular_buffer;