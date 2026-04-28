#include <stddef.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct ok_csv_circular_buffer {
    size_t start;
    size_t length;
    size_t capacity;
} ok_csv_circular_buffer;