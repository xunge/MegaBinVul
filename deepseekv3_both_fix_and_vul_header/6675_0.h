#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum vpx_img_fmt {
    VPX_IMG_FMT_NONE,
    VPX_IMG_FMT_RGB32,
    VPX_IMG_FMT_RGB32_LE,
    VPX_IMG_FMT_ARGB,
    VPX_IMG_FMT_ARGB_LE,
    VPX_IMG_FMT_RGB24,
    VPX_IMG_FMT_BGR24,
    VPX_IMG_FMT_RGB565,
    VPX_IMG_FMT_RGB565_LE,
    VPX_IMG_FMT_RGB555,
    VPX_IMG_FMT_RGB555_LE,
    VPX_IMG_FMT_UYVY,
    VPX_IMG_FMT_YUY2,
    VPX_IMG_FMT_YVYU,
    VPX_IMG_FMT_I420,
    VPX_IMG_FMT_YV12,
    VPX_IMG_FMT_VPXI420,
    VPX_IMG_FMT_VPXYV12,
    VPX_IMG_FMT_I422,
    VPX_IMG_FMT_I440,
    VPX_IMG_FMT_I444,
    VPX_IMG_FMT_I42016,
    VPX_IMG_FMT_I42216,
    VPX_IMG_FMT_I44016,
    VPX_IMG_FMT_I44416,
    VPX_IMG_FMT_PLANAR = 0x100,
    VPX_IMG_FMT_HIGHBITDEPTH = 0x200
} vpx_img_fmt_t;

typedef enum {
    VPX_PLANE_Y,
    VPX_PLANE_U,
    VPX_PLANE_V,
    VPX_PLANE_ALPHA
} vpx_plane_t;

typedef struct vpx_image {
    vpx_img_fmt_t fmt;
    unsigned int w;
    unsigned int h;
    unsigned int bit_depth;
    unsigned int x_chroma_shift;
    unsigned int y_chroma_shift;
    unsigned int bps;
    unsigned int stride[4];
    unsigned char *img_data;
    int img_data_owner;
    int self_allocd;
} vpx_image_t;

void *vpx_memalign(unsigned int align, size_t size);
void vpx_img_free(vpx_image_t *img);
int vpx_img_set_rect(vpx_image_t *img, unsigned int x, unsigned int y, unsigned int w, unsigned int h);