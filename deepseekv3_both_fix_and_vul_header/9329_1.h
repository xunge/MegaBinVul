#include <stdint.h>

typedef struct SwsContext {
    int srcFormat;
    int srcW;
} SwsContext;

enum AVPixelFormat {
    AV_PIX_FMT_BAYER_BGGR8,
    AV_PIX_FMT_BAYER_BGGR16LE,
    AV_PIX_FMT_BAYER_BGGR16BE,
    AV_PIX_FMT_BAYER_RGGB8,
    AV_PIX_FMT_BAYER_RGGB16LE,
    AV_PIX_FMT_BAYER_RGGB16BE,
    AV_PIX_FMT_BAYER_GBRG8,
    AV_PIX_FMT_BAYER_GBRG16LE,
    AV_PIX_FMT_BAYER_GBRG16BE,
    AV_PIX_FMT_BAYER_GRBG8,
    AV_PIX_FMT_BAYER_GRBG16LE,
    AV_PIX_FMT_BAYER_GRBG16BE
};

void bayer_bggr8_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_bggr8_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_bggr16le_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_bggr16le_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_bggr16be_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_bggr16be_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_rggb8_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_rggb8_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_rggb16le_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_rggb16le_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_rggb16be_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_rggb16be_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_gbrg8_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_gbrg8_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_gbrg16le_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_gbrg16le_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_gbrg16be_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_gbrg16be_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_grbg8_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_grbg8_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_grbg16le_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_grbg16le_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_grbg16be_to_rgb24_copy(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);
void bayer_grbg16be_to_rgb24_interpolate(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int width);