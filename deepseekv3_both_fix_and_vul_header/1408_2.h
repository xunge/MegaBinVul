#include <stdint.h>
#include <stdlib.h>

typedef int JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;

typedef int32_t JLONG;
typedef int16_t INT16;

typedef struct jpeg_decompress_struct {
    struct jpeg_upsampler *upsample;
    JSAMPLE *sample_range_limit;
    JDIMENSION output_scanline;
    JDIMENSION output_width;
} *j_decompress_ptr;

typedef struct jpeg_upsampler {
    int *Cr_r_tab;
    int *Cb_b_tab;
    JLONG *Cr_g_tab;
    JLONG *Cb_g_tab;
} *my_merged_upsample_ptr, *my_upsample_ptr;

#define INLINE inline
#define LOCAL(type) static type
#define GETJSAMPLE(x) ((int)(x))
#define SCALEBITS 16
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define DITHER_MASK 7
#define DITHER_ROTATE(x) ((x) = ((x) << 1) | ((x) >> 31))
#define PACK_SHORT_565(r, g, b) (((r) << 11) | ((g) << 5) | (b))
#define PACK_TWO_PIXELS(a, b) (((a) << 16) | (b))
#define WRITE_TWO_PIXELS(addr, rgb) \
    do { \
        *(addr) = (JSAMPLE)((rgb) >> 16); \
        *((addr) + 1) = (JSAMPLE)(rgb); \
    } while (0)
#define DITHER_565_R(y, d) ((y) + ((d) & 0x07))
#define DITHER_565_G(y, d) ((y) + ((d) & 0x07))
#define DITHER_565_B(y, d) ((y) + ((d) & 0x07))
#define SHIFT_TEMPS

static const JLONG dither_matrix[8] = {0, 4, 2, 6, 1, 5, 3, 7};