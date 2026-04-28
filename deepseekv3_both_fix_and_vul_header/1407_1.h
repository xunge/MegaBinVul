#include <stddef.h>
#include <stdint.h>

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;
typedef int JLONG;
typedef int16_t INT16;

#define INLINE inline
#define LOCAL(type) static type
#define GETJSAMPLE(x) ((int)(x))
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define SCALEBITS 16
#define SHIFT_TEMPS
#define PACK_SHORT_565(r, g, b) (((r) << 11) | ((g) << 5) | (b))
#define PACK_TWO_PIXELS(a, b) (((JLONG)(a) << 16) | (b))
#define WRITE_TWO_PIXELS(addr, rgb) *((JLONG *)(addr)) = (rgb)

typedef struct my_merged_upsample {
  int *Cr_r_tab;
  int *Cb_b_tab;
  JLONG *Cr_g_tab;
  JLONG *Cb_g_tab;
} *my_merged_upsample_ptr;

typedef struct my_upsample {
  int *Cr_r_tab;
  int *Cb_b_tab;
  JLONG *Cr_g_tab;
  JLONG *Cb_g_tab;
} *my_upsample_ptr;

typedef struct jpeg_decompress_struct {
  void *upsample;
  JDIMENSION output_width;
  JSAMPLE *sample_range_limit;
} jpeg_decompress_struct;