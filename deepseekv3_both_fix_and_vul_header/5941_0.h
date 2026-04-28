#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVSContext {
    struct {
        GetBitContext gb;
    } s;
    int mbx;
    int stc;
    int mb_height;
} AVSContext;

int get_bits_count(GetBitContext *gb);
unsigned int show_bits(GetBitContext *gb, int bits);
unsigned int show_bits_long(GetBitContext *gb, int bits);
void skip_bits_long(GetBitContext *gb, int bits);
int get_bits(GetBitContext *gb, int bits);
void decode_slice_header(AVSContext *h, GetBitContext *gb);