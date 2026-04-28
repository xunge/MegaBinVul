#include <stdlib.h>
#include <string.h>

typedef int SIXELSTATUS;
#define SIXEL_FALSE 0
#define SIXEL_FAILED(x) ((x) != 0)

typedef struct {
    int pixelformat;
    void *allocator;
    int method_for_diffuse;
    unsigned char *palette;
    int bodyonly;
} sixel_dither_t;

typedef struct {
} sixel_output_t;

#define SIXEL_PIXELFORMAT_RGB888 0
#define PALETTE_CHANGE 1
#define PALETTE_HIT 2

extern void *sixel_allocator_malloc(void *allocator, size_t size);
extern void sixel_allocator_free(void *allocator, void *ptr);
extern SIXELSTATUS sixel_helper_normalize_pixelformat(unsigned char *dst, int *dst_format, unsigned char *src, int src_format, int width, int height);
extern void sixel_apply_15bpp_dither(unsigned char *pixels, int x, int y, int width, int height, int method);
extern SIXELSTATUS sixel_encode_header(int width, int height, sixel_output_t *output);
extern SIXELSTATUS sixel_encode_body(unsigned char *pixels, int width, int height, unsigned char *palette, int ncolors, int keycolor, int bodyonly, sixel_output_t *output, unsigned char *palstate, void *allocator);
extern SIXELSTATUS sixel_encode_footer(sixel_output_t *output);