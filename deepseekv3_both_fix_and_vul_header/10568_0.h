#include <stddef.h>

#define IW_ENDIAN_LITTLE 0
#define IW_ENDIAN_BIG 1

typedef unsigned char iw_byte;
typedef unsigned int iw_uint32;

struct iw_exif_state {
    const iw_byte *d;
    size_t d_len;
    int endian;
};

struct iwjpegrcontext;

static void iw_zeromem(void *p, size_t n);
static iw_uint32 iw_get_ui32_e(const iw_byte *p, int endian);
static void iwjpeg_scan_exif_ifd(struct iwjpegrcontext *rctx, struct iw_exif_state *e, iw_uint32 ifd);