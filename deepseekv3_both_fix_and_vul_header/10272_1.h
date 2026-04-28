#include <stddef.h>

struct iw_context {
    // placeholder for context structure
};

struct iw_iodescr {
    // placeholder for I/O descriptor structure
};

struct iw_image {
    void *pixels;
    // other image fields as needed
};

struct iwbmprcontext {
    struct iw_context *ctx;
    struct iw_image *img;
    struct iw_iodescr *iodescr;
    void *csdescr;
    int has_fileheader;
    int bitfields_nbytes;
    int palette_entries;
    // other BMP context fields as needed
};

#define IW_IMPL(rettype) rettype
#define IW_VAL_BMP_NO_FILEHEADER 0

void iw_zeromem(void *ptr, size_t size);
void iw_make_srgb_csdescr_2(void *csdescr);
int iw_get_value(struct iw_context *ctx, int val);
int iwbmp_read_file_header(struct iwbmprcontext *rctx);
int iwbmp_read_info_header(struct iwbmprcontext *rctx);
void iwbmp_set_default_bitfields(struct iwbmprcontext *rctx);
int iwbmp_read_bitfields(struct iwbmprcontext *rctx);
int iwbmp_read_palette(struct iwbmprcontext *rctx);
int iwbmp_read_bits(struct iwbmprcontext *rctx);
void iw_set_input_image(struct iw_context *ctx, struct iw_image *img);
void iwbmpr_misc_config(struct iw_context *ctx, struct iwbmprcontext *rctx);
void iw_set_error(struct iw_context *ctx, const char *msg);
void iw_free(struct iw_context *ctx, void *ptr);