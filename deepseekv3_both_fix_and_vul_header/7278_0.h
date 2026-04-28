#include <stdint.h>
#include <stdbool.h>

#define HUFFMAN_LOOKUP_SIZE_BITS 8

typedef struct {
    uint8_t size[256];
    uint16_t code[256];
    int16_t maxcode[16];
    uint16_t mincode[16];
    uint8_t valptr[16];
    int count;
} ok_jpg_huffman_table;