#include <stdint.h>

typedef struct SwsContext {
    int srcFormat;
    int srcW;
    int32_t *input_rgb2yuv_table;
} SwsContext;

#define AV_PIX_FMT_BAYER_BGGR8    0
#define AV_PIX_FMT_BAYER_BGGR16LE 1
#define AV_PIX_FMT_BAYER_BGGR16BE 2
#define AV_PIX_FMT_BAYER_RGGB8    3
#define AV_PIX_FMT_BAYER_RGGB16LE 4
#define AV_PIX_FMT_BAYER_RGGB16BE 5
#define AV_PIX_FMT_BAYER_GBRG8    6
#define AV_PIX_FMT_BAYER_GBRG16LE 7
#define AV_PIX_FMT_BAYER_GBRG16BE 8
#define AV_PIX_FMT_BAYER_GRBG8    9
#define AV_PIX_FMT_BAYER_GRBG16LE 10
#define AV_PIX_FMT_BAYER_GRBG16BE 11

void bayer_bggr8_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_bggr8_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_bggr16le_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_bggr16le_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_bggr16be_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_bggr16be_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_rggb8_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_rggb8_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_rggb16le_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_rggb16le_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_rggb16be_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_rggb16be_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_gbrg8_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_gbrg8_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_gbrg16le_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_gbrg16le_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_gbrg16be_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_gbrg16be_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_grbg8_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_grbg8_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_grbg16le_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_grbg16le_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_grbg16be_to_yv12_copy(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);
void bayer_grbg16be_to_yv12_interpolate(const uint8_t *src, int src_stride, uint8_t *dstY, uint8_t *dstU, uint8_t *dstV, int luma_stride, int width, int32_t *rgb2yuv);