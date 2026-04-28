#include <stddef.h>

#define LOCAL(type) static type
#define SHIFT_TEMPS
#define MAXJSAMPLE 255
#define CENTERJSAMPLE 128
#define SCALEBITS 16
#define ONE_HALF (1 << (SCALEBITS - 1))
#define FIX(x) ((JLONG)((x) * (1L << SCALEBITS) + 0.5))
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define JPOOL_IMAGE 0

typedef long JLONG;

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct jpeg_common_struct *j_common_ptr;

struct jpeg_memory_mgr {
    void *(*alloc_small)(j_common_ptr, int, size_t);
};

struct jpeg_decompress_struct {
    struct jpeg_memory_mgr *mem;
    void *upsample;
};

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