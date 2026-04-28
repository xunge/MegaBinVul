#include <stdint.h>

typedef struct GetBitContext {
    // minimal definition needed for compilation
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct dec_2dvlc {
    int golomb_order;
    int max_run;
    int *level_add;
    int inc_limit;
    int rltab[64][3];
} dec_2dvlc;

typedef struct DSPContext {
    void (*clear_block)(int16_t *block);
} DSPContext;

typedef struct CDSPContext {
    void (*cavs_idct8_add)(uint8_t *dst, int16_t *block, int stride);
} CDSPContext;

typedef struct AVSContext {
    int16_t *block;
    struct {
        DSPContext dsp;
    } s;
    CDSPContext cdsp;
} AVSContext;

typedef int16_t DCTELEM;

#define ESCAPE_CODE 59

extern int get_ue_code(GetBitContext *gb, int golomb_order);
extern int dequant(AVSContext *h, DCTELEM *level_buf, uint8_t *run_buf, 
                  DCTELEM *block, const uint8_t *mul, const uint8_t *shift, int count);
extern const uint8_t ff_cavs_dequant_mul[64];
extern const uint8_t ff_cavs_dequant_shift[64];