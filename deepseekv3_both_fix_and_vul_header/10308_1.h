#include <stdlib.h>

#define IW_IMPL(return_type) return_type

struct iw_context;
struct iw_iodescr;
struct iw_image {
    int width;
    int height;
};
struct iwpnmrcontext {
    struct iw_context *ctx;
    struct iw_image *img;
    struct iw_iodescr *iodescr;
};

int iw_check_image_dimensions(struct iw_context *ctx, int width, int height);
void iw_free(struct iw_context *ctx, void *ptr);
void *iw_mallocz(struct iw_context *ctx, size_t size);
int iwpnm_read_header(struct iwpnmrcontext *rctx);
int iwpnm_read_pnm_bitmap(struct iwpnmrcontext *rctx);
void iw_set_input_image(struct iw_context *ctx, struct iw_image *img);