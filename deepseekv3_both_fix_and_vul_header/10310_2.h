#include <stdlib.h>
#include <string.h>

#define IW_IMPL(return_type) return_type

struct iw_context;
struct iw_iodescr;
struct iw_image {
    void *pixels;
};
struct iw_csdescr {
    int dummy;  // Placeholder for actual color space description fields
};
struct iwgifrcontext {
    struct iw_context *ctx;
    struct iw_iodescr *iodescr;
    struct iw_image *img;
    struct iw_csdescr csdescr;
    int page;
    int include_screen;
    void *row_pointers;
};

int iw_get_value(struct iw_context *ctx, int val);
void iw_set_error(struct iw_context *ctx, const char *msg);
void iw_set_input_image(struct iw_context *ctx, struct iw_image *img);
void iw_set_input_colorspace(struct iw_context *ctx, struct iw_csdescr *csdescr);
void iw_make_srgb_csdescr_2(struct iw_csdescr *csdescr);
void* iw_mallocz(struct iw_context *ctx, size_t size);
void iw_free(struct iw_context *ctx, void *ptr);
void iw_zeromem(void *ptr, size_t size);
int iwgif_read_main(struct iwgifrcontext *rctx);

enum {
    IW_VAL_PAGE_TO_READ,
    IW_VAL_INCLUDE_SCREEN
};