#include <stdint.h>
#include <string.h>

#define HUFF_MAGIC "HUFF"
#define HUFF_HEADER_LEN 24
#define HUFF_CODETABLE_SIZE 33

typedef enum {
    MOBI_SUCCESS,
    MOBI_MALLOC_FAILED,
    MOBI_DATA_CORRUPT
} MOBI_RET;

typedef struct {
    uint8_t *data;
    size_t size;
} MOBIPdbRecord;

typedef struct {
    size_t offset;
    size_t maxlen;
    uint8_t *data;
} MOBIBuffer;

typedef struct {
    uint32_t table1[256];
    uint32_t mincode_table[HUFF_CODETABLE_SIZE];
    uint32_t maxcode_table[HUFF_CODETABLE_SIZE];
} MOBIHuffCdic;

extern void debug_print(const char *format, ...);
extern MOBIBuffer *mobi_buffer_init_null(const uint8_t *data, size_t size);
extern void mobi_buffer_free_null(MOBIBuffer *buf);
extern void mobi_buffer_getstring(char *str, MOBIBuffer *buf, size_t len);
extern uint32_t mobi_buffer_get32(MOBIBuffer *buf);
extern void mobi_buffer_setpos(MOBIBuffer *buf, size_t pos);