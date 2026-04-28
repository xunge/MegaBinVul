#include <stddef.h>
#include <stdint.h>

typedef unsigned char JSAMPLE;
typedef short INT16;
typedef unsigned int JDIMENSION;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef int32_t JLONG;

struct jpeg_decompress_struct {
    void *upsample;
    JSAMPLE *sample_range_limit;
    JDIMENSION output_scanline;
    JDIMENSION output_width;
};

struct my_merged_upsample_struct {
    int *Cr_r_tab;
    int *Cb_b_tab;
    JLONG *Cr_g_tab;
    JLONG *Cb_g_tab;
};

struct my_upsample_struct {
    int *Cr_r_tab;
    int *Cb_b_tab;
    JLONG *Cr_g_tab;
    JLONG *Cb_g_tab;
};

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct my_merged_upsample_struct *my_merged_upsample_ptr;
typedef struct my_upsample_struct *my_upsample_ptr;

#define INLINE inline
#define LOCAL(type) static type

#define SCALEBITS 16
#define DITHER_MASK 7

#define GETJSAMPLE(x) (x)
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define DITHER_ROTATE(x) ((x) = ((x) << 1) | ((x) >> 31))
#define PACK_SHORT_565(r, g, b) (((r) << 11) | ((g) << 5) | (b))
#define PACK_TWO_PIXELS(a, b) (((JLONG)(a) << 16) | (b))
#define WRITE_TWO_PIXELS(ptr, val) \
    do { \
        *(ptr) = (JSAMPLE)((val) >> 16); \
        *((ptr) + 1) = (JSAMPLE)(val); \
    } while (0)

#define DITHER_565_R(y, d) ((y) + ((d) & 0x1F))
#define DITHER_565_G(y, d) ((y) + (((d) >> 5) & 0x3F))
#define DITHER_565_B(y, d) ((y) + (((d) >> 11) & 0x1F))

#define SHIFT_TEMPS

extern const JLONG dither_matrix[8];