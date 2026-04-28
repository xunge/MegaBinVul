#include <stddef.h>

struct iw_context;
struct iw_iodescr;

struct iw_colorspace_descr {
    int dummy;  // placeholder for actual colorspace description fields
};

struct iw_image {
    int sampletype;
    int bit_depth;
    int width;
    int height;
    int imgtype;
    int native_grayscale;
    double density_x;
    double density_y;
    int density_code;
};

struct iwmiffrcontext {
    struct iw_context *ctx;
    int host_endian;
    struct iw_iodescr *iodescr;
    struct iw_image *img;
    int compression;
    void *zmod;
    struct iw_colorspace_descr csdescr;
    int is_grayscale;
    int has_alpha;
    int density_known;
    int density_units;
    double density_x;
    double density_y;
};

#define IW_IMPL(x) x
#define IW_COMPRESSION_NONE 0
#define IW_SAMPLETYPE_FLOATINGPOINT 0
#define IW_IMGTYPE_GRAYA 0
#define IW_IMGTYPE_GRAY 0
#define IW_IMGTYPE_RGBA 0
#define IW_IMGTYPE_RGB 0
#define IW_DENSITY_UNITS_PER_METER 0

void iw_zeromem(void *ptr, size_t size);
int iw_get_host_endianness(void);
void* iw_get_zlib_module(struct iw_context *ctx);
void iw_make_srgb_csdescr_2(struct iw_colorspace_descr *csdescr);
int iwmiff_read_header(struct iwmiffrcontext *rctx);
int iw_check_image_dimensions(struct iw_context *ctx, int width, int height);
int iwmiff_read_icc_profile(struct iwmiffrcontext *rctx);
int iwmiff_read_pixels(struct iwmiffrcontext *rctx);
void iw_set_input_image(struct iw_context *ctx, struct iw_image *img);
void iw_set_input_colorspace(struct iw_context *ctx, struct iw_colorspace_descr *csdescr);
void iw_set_error(struct iw_context *ctx, const char *msg);