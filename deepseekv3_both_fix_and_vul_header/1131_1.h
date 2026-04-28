#include <stdio.h>

#define HD_ERROR_READ_ERROR 1

typedef unsigned char uchar;

typedef struct {
    int width;
    int height;
    int depth;
    uchar *pixels;
    char *filename;
} image_t;

typedef uchar gif_cmap_t[256][3];

extern int gif_read_lzw(FILE *fp, int init, int code_size);
extern void progress_error(int error, const char *format, ...);
extern void image_set_mask(image_t *img, int x, int y);