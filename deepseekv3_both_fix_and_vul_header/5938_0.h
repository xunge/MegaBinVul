#include <stdint.h>

typedef struct GetBitContext GetBitContext;
typedef struct dec_2dvlc {
    int golomb_order;
    int max_run;
    const int *level_add;
    int inc_limit;
    const int (*rltab)[3];
} dec_2dvlc;

typedef int16_t DCTELEM;

#define ESCAPE_CODE 59

typedef struct AVSContext {
    DCTELEM *block;
    struct {
        struct {
            void (*clear_block)(DCTELEM *block);
        } dsp;
    } s;
    struct {
        void (*cavs_idct8_add)(uint8_t *dst, DCTELEM *block, int stride);
    } cdsp;
} AVSContext;

extern const uint8_t ff_cavs_dequant_mul[32];
extern const uint8_t ff_cavs_dequant_shift[32];

int get_ue_code(GetBitContext *gb, int order);
int dequant(AVSContext *h, DCTELEM *level_buf, uint8_t *run_buf, DCTELEM *block,
            const uint8_t mul, const uint8_t shift, int num_coeff);