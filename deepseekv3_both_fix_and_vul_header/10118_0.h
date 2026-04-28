#include <stdlib.h>
#include <string.h>

#define MagickFalse 0
#define MagickTrue 1
typedef int MagickBooleanType;

#define SIXEL_PALETTE_MAX 256
#define SIXEL_RGB(r, g, b) (((r) << 16) | ((g) << 8) | (b))
#define SIXEL_XRGB(r, g, b) SIXEL_RGB((r)*255/100, (g)*255/100, (b)*255/100)

extern void *AcquireQuantumMemory(size_t, size_t);
extern void *RelinquishMagickMemory(void *);
extern void *ResetMagickMemory(void *, int, size_t);
extern void *CopyMagickMemory(void *, const void *, size_t);

static const int sixel_default_color_table[16] = {
    0x000000, 0x0000AA, 0x00AA00, 0x00AAAA,
    0xAA0000, 0xAA00AA, 0xAA5500, 0xAAAAAA,
    0x555555, 0x5555FF, 0x55FF55, 0x55FFFF,
    0xFF5555, 0xFF55FF, 0xFFFF55, 0xFFFFFF
};

static unsigned char *get_params(unsigned char *p, int *params, int *nparams);
static int hls_to_rgb(int h, int l, int s);