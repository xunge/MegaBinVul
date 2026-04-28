#include <stdlib.h>
#include <stddef.h>

typedef unsigned char iw_byte;

struct iw_image {
    int width;
    int height;
    int imgtype;
    int bit_depth;
    size_t bpr;
    iw_byte *pixels;
};

struct iw_compress_module {
    void (*inflate_end)(void*);
};

struct iwmiffrcontext {
    struct iw_image *img;
    int miff_bitdepth;
    void *ctx;
    void *zctx;
    struct iw_compress_module *zmod;
    void *cbuf;
};

void *iw_mallocz(void *ctx, size_t size);
void *iw_malloc_large(void *ctx, size_t size, int height);
void iw_free(void *ctx, void *ptr);
int iw_imgtype_num_channels(int imgtype);
int iwmiff_read_and_uncompress_row(struct iwmiffrcontext *rctx, iw_byte *tmprow, size_t tmprowsize);
void iwmiffr_convert_row64_32(struct iwmiffrcontext *rctx, iw_byte *src, iw_byte *dst, int samples_per_row);
void iwmiffr_convert_row32(struct iwmiffrcontext *rctx, iw_byte *src, iw_byte *dst, int samples_per_row);