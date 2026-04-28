#include <stdio.h>
#include <stdlib.h>

#define IMAGE_MAX_DIM 32767
#define GIF_COLORMAP 0x80
#define GIF_INTERLACE 0x40

typedef unsigned char uchar;

typedef struct {
    uchar r;
    uchar g;
    uchar b;
} gif_rgb_t;

typedef uchar gif_cmap_t[256][3];

typedef struct image_t {
    int width;
    int height;
    int depth;
    int use;
    uchar *pixels;
} image_t;

extern int Encryption;
extern char BodyColor[256];
extern int gif_read_cmap(FILE *fp, int ncolors, gif_cmap_t cmap, int *gray);
extern int gif_get_block(FILE *fp, uchar *buf);
extern int gif_read_image(FILE *fp, image_t *img, gif_cmap_t cmap, int interlace, int transparent);
extern void image_need_mask(image_t *img);
extern void get_color(uchar *color, float *rgb);