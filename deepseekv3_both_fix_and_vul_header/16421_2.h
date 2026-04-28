#include <stdint.h>
#include <stdlib.h>

#define LZW_IS_DECODER(obj) (1)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_CODES 4096
#define LZW_CODE_MAX 12

typedef size_t gsize;
typedef uint8_t guint8;
typedef unsigned int guint;

typedef struct {
    guint8 min_code_size;
    guint8 code_size;
    guint code_bits;
    guint code;
    guint clear_code;
    guint eoi_code;
    guint last_code;
    guint code_table_size;
} LZWDecoder;

void add_code(LZWDecoder *self, guint code);
gsize write_indexes(LZWDecoder *self, guint8 *output, gsize output_length);