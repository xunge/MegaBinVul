#include <stdint.h>
#include <stdbool.h>

typedef struct jas_image_s jas_image_t;
typedef struct jas_stream_s jas_stream_t;

typedef struct {
    uint_fast16_t magic;
    uint_fast32_t siz;
    uint_fast16_t reserved1;
    uint_fast16_t reserved2;
    uint_fast32_t off;
} bmp_hdr_t;

typedef struct {
    uint_fast32_t len;
    uint_fast32_t width;
    uint_fast32_t height;
    uint_fast16_t numplanes;
    uint_fast16_t depth;
    uint_fast32_t enctype;
    uint_fast32_t siz;
    uint_fast32_t hres;
    uint_fast32_t vres;
    uint_fast32_t numcolors;
    uint_fast32_t mincolors;
} bmp_info_t;

typedef struct {
    uint_fast32_t tlx;
    uint_fast32_t tly;
    uint_fast32_t hstep;
    uint_fast32_t vstep;
    uint_fast32_t width;
    uint_fast32_t height;
    uint_fast16_t prec;
    bool sgnd;
} jas_image_cmptparm_t;

#define BMP_HDRLEN 14
#define BMP_INFOLEN 40
#define BMP_PALLEN(info) ((info)->numcolors * 3)

#define JAS_CLRSPC_UNKNOWN 0
#define JAS_CLRSPC_SRGB 1
#define JAS_CLRSPC_SGRAY 2
#define JAS_IMAGE_CT_COLOR(x) (x)
#define JAS_CLRSPC_CHANIND_RGB_R 0
#define JAS_CLRSPC_CHANIND_RGB_G 1
#define JAS_CLRSPC_CHANIND_RGB_B 2
#define JAS_CLRSPC_CHANIND_GRAY_Y 0

void jas_eprintf(const char *format, ...);
int bmp_gethdr(jas_stream_t *in, bmp_hdr_t *hdr);
bmp_info_t *bmp_getinfo(jas_stream_t *in);
int bmp_issupported(bmp_hdr_t *hdr, bmp_info_t *info);
void bmp_info_destroy(bmp_info_t *info);
uint_fast16_t bmp_numcmpts(bmp_info_t *info);
int bmp_gobble(jas_stream_t *in, long n);
jas_image_t *jas_image_create(uint_fast16_t numcmpts, jas_image_cmptparm_t *cmptparms, int clrspc);
void jas_image_setclrspc(jas_image_t *image, int clrspc);
void jas_image_setcmpttype(jas_image_t *image, uint_fast16_t cmptno, int type);
int bmp_getdata(jas_stream_t *in, bmp_info_t *info, jas_image_t *image);
void jas_image_destroy(jas_image_t *image);

#define JAS_DBGLOG(level, args)