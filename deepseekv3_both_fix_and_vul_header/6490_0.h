#include <stdint.h>
#include <string.h>

#define MAX_STRIDE 4096U
#define MAX_H 8U

extern void ff_gmc_c(uint8_t *dst, uint8_t *src, int stride, int h, int ox, int oy, int dxx, int dxy, int dyx, int dyy, int shift, int r, int width, int height);
extern void ff_emulated_edge_mc_8(uint8_t *edge_buf, uint8_t *src, int stride, int src_stride, int width, int height, int x, int y, int src_width, int src_height);