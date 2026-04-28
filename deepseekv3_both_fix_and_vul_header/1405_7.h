#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef size_t JDIMENSION;
typedef long JLONG;

#define INLINE inline
#define LOCAL(type) static type
#define SHIFT_TEMPS
#define SCALEBITS 16
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define GETJSAMPLE(x) (x)
#define RGB_RED 0
#define RGB_GREEN 1
#define RGB_BLUE 2
#define RGB_ALPHA 3
#define RGB_PIXELSIZE 3

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct my_merged_upsample_struct *my_merged_upsample_ptr;
typedef struct my_upsample_struct *my_upsample_ptr;

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

struct jpeg_decompress_struct {
    struct my_merged_upsample_struct *upsample;
    JSAMPLE *sample_range_limit;
    JDIMENSION output_width;
};