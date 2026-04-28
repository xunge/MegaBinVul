#include <stdint.h>
#include <assert.h>

#define PREDICT(pred, a, b, c, predictor) \
    switch (predictor) { \
        case 1: pred = a; break; \
        case 2: pred = b; break; \
        case 3: pred = c; break; \
        case 4: pred = a + b - c; break; \
        case 5: pred = a + ((b - c) >> 1); break; \
        case 6: pred = b + ((a - c) >> 1); break; \
        case 7: pred = (a + b) >> 1; break; \
    }

typedef struct MJpegDecodeContext {
    int bits;
    int mb_height;
    int mb_width;
    int restart_interval;
    int restart_count;
    int interlaced;
    int width;
    int height;
    int *nb_blocks;
    int *comp_index;
    int *h_scount;
    int *v_scount;
    int *linesize;
    struct {
        uint8_t *data[4];
    } *picture_ptr;
    int bottom_field;
    int *dc_index;
    struct {
        int index;
    } gb;
} MJpegDecodeContext;

static void align_get_bits(struct { int index; } *gb);
static void skip_bits(struct { int index; } *gb, int n);
static int mjpeg_decode_dc(MJpegDecodeContext *s, int index);