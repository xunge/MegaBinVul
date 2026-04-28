#include <stddef.h>

struct iwbmprcontext {
    size_t infoheader_size;
    int bmpversion;
    int width;
    int height;
    void *ctx;
};

static int iw_get_ui32le(const unsigned char *);
static int iwbmp_read(struct iwbmprcontext *, void *, size_t);
static int decode_v2_header(struct iwbmprcontext *, const unsigned char *);
static int decode_v3_header_fields(struct iwbmprcontext *, const unsigned char *);
static int decode_v4_header_fields(struct iwbmprcontext *, const unsigned char *);
static int decode_v5_header_fields(struct iwbmprcontext *, const unsigned char *);
static int iw_check_image_dimensions(void *, int, int);
static void iw_set_error(void *, const char *);

typedef unsigned char iw_byte;