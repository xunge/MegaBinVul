#include <stdint.h>
#include <stddef.h>

typedef enum {
    MOBI_SUCCESS,
    MOBI_DATA_CORRUPT
} MOBI_RET;

#define MOBI_HUFFMAN_MAXDEPTH 100
#define HUFF_CODETABLE_SIZE 32

typedef struct {
    uint8_t *data;
    size_t offset;
    size_t maxlen;
    MOBI_RET error;
} MOBIBuffer;

typedef struct {
    uint32_t *table1;
    uint32_t *mincode_table;
    uint32_t *maxcode_table;
    uint32_t *symbol_offsets;
    uint8_t **symbols;
    uint16_t code_length;
    uint32_t index_count;
} MOBIHuffCdic;

uint64_t mobi_buffer_fill64(MOBIBuffer *buf);
void mobi_buffer_addraw(MOBIBuffer *buf, const uint8_t *data, size_t len);
void debug_print(const char *format, ...);