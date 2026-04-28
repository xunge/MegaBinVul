#include <stdint.h>
#include <limits.h>
#include <stddef.h>

struct tiff {
    unsigned int bitspersample;
    unsigned int samplesperpixel;
    unsigned int colormaplen;
    unsigned int imagelength;
    unsigned int imagewidth;
    unsigned int stride;
    unsigned char *samples;
    unsigned char *colormap;
    int extrasamples;
};

enum {
    FZ_ERROR_GENERIC
};

typedef struct fz_context fz_context;

void *fz_malloc(fz_context *ctx, size_t size);
void fz_free(fz_context *ctx, void *ptr);
void fz_throw(fz_context *ctx, int error, const char *message);
int tiff_getcomp(unsigned char *src, int pos, int bits);