#include <stddef.h>
#include <limits.h>

#define ENFILE 23

struct io_file_table {
    unsigned long *bitmap;
    unsigned long alloc_hint;
};

struct io_ring_ctx {
    struct io_file_table file_table;
    unsigned long file_alloc_end;
    unsigned long file_alloc_start;
};

static int find_next_zero_bit(const unsigned long *addr, unsigned long size, unsigned long offset) {
    for (unsigned long i = offset; i < size; i++) {
        if (!(addr[i / (8 * sizeof(unsigned long))] & (1UL << (i % (8 * sizeof(unsigned long)))))) {
            return i;
        }
    }
    return size;
}