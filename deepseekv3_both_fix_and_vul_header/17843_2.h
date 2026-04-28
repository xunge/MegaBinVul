#include <stdint.h>

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;

typedef struct {
    int prec;
    int sgnd;
} opj_image_comp_t;

typedef struct {
    int x0;
    int y0;
    opj_image_comp_t *comps;
} opj_image_t;

typedef struct {
    unsigned x0;
    unsigned y0;
    unsigned x1;
    unsigned y1;
} JPEG2KTILEINFO;

typedef struct {
    UINT8 **image;
} *Imaging;

static UINT8 j2ku_shift(int value, int shift) {
    if (shift > 0) {
        return (value + (1 << (shift - 1))) >> shift;
    } else if (shift < 0) {
        return value << (-shift);
    }
    return value;
}