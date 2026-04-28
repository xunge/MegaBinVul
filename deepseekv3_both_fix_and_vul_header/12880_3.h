#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

typedef uchar gif_cmap_t[256][3];

typedef struct {
    int width;
    int height;
    int depth;
    uchar *pixels;
    int use;
} image_t;

extern int Encryption;
extern char BodyColor[];
extern int gif_read_cmap(FILE *fp, int ncolors, gif_cmap_t cmap, int *gray);
extern int gif_get_block(FILE *fp, uchar *buf);
extern int gif_read_image(FILE *fp, image_t *img, gif_cmap_t cmap, int interlace, int transparent);
extern void image_need_mask(image_t *img);
extern void get_color(uchar *color, float *rgb);

#define GIF_COLORMAP 0x80
#define GIF_INTERLACE 0x40