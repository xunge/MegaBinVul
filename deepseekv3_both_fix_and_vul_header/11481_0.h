#include <stddef.h>

typedef unsigned char iw_byte;

#define IWBMP_BI_RLE4 2

struct iw_palette_entry {
    iw_byte r;
    iw_byte g;
    iw_byte b;
};

struct iw_palette {
    struct iw_palette_entry *entry;
};

struct iw_image {
    iw_byte *pixels;
    size_t width;
    size_t height;
    size_t bpr;
};

struct iwbmprcontext {
    struct iw_image *img;
    struct iw_palette palette;
    int compression;
};

int iwbmp_read(struct iwbmprcontext *rctx, iw_byte *buf, size_t n);
void iw_zeromem(void *ptr, size_t size);