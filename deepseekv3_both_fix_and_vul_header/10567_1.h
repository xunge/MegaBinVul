#include <stdint.h>
#include <stddef.h>

#define IWBMP_BI_RLE8 1
#define IWBMP_BI_RLE4 2

#define IW_IMGTYPE_RGBA 1

struct iwbmprcontext {
    int compression;
    int bitcount;
    int topdown;
    int width;
    int height;
    struct iwcontext *ctx;
    struct iwimage *img;
};

struct iwcontext {
    char *error;
};

struct iwimage {
    int imgtype;
    int bit_depth;
    size_t bpr;
    int height;
    uint8_t *pixels;
};

typedef uint8_t iw_byte;

void iw_set_error(struct iwcontext *ctx, const char *msg);
size_t iw_calc_bytesperrow(int width, int bits);
void *iw_malloc_large(struct iwcontext *ctx, size_t bpr, int height);
int bmpr_read_rle_internal(struct iwbmprcontext *rctx);
int bmpr_has_transparency(struct iwimage *img);
void bmpr_strip_alpha(struct iwimage *img);