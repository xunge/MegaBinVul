#include <stdint.h>

typedef int JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef int32_t JLONG;
typedef int16_t INT16;

struct jpeg_decompress_struct {
    void *upsample;
    JSAMPLE *sample_range_limit;
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
#define GETJSAMPLE(x) ((int)(x))
#define SCALEBITS 16
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define PACK_SHORT_565(r, g, b) (((r) << 11) | ((g) << 5) | (b))
#define PACK_TWO_PIXELS(a, b) (((b) << 16) | (a))
#define WRITE_TWO_PIXELS(ptr, val) (*(int *)(ptr) = (val))
#define SHIFT_TEMPS