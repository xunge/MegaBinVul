#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct jas_image_t jas_image_t;
typedef struct jas_stream_t jas_stream_t;
typedef struct jas_iccprof_t jas_iccprof_t;
typedef struct jas_cmprof_t jas_cmprof_t;

typedef struct jp2_ftyp_t {
    uint_fast32_t majver;
    uint_fast32_t minver;
    uint_fast32_t numcompatcodes;
    uint_fast32_t compatcodes[1];
} jp2_ftyp_t;

typedef struct jp2_ihdr_t {
    uint_fast32_t width;
    uint_fast32_t height;
    uint_fast16_t numcmpts;
    uint_fast8_t bpc;
    uint_fast8_t comptype;
    uint_fast8_t csunk;
    uint_fast8_t ipr;
} jp2_ihdr_t;

typedef struct jp2_bpcc_t {
    uint_fast16_t numcmpts;
    uint_fast8_t *bpcs;
} jp2_bpcc_t;

typedef struct jp2_colr_t {
    uint_fast8_t method;
    uint_fast8_t pri;
    uint_fast8_t approx;
    union {
        uint_fast32_t csid;
        struct {
            uint_fast32_t iccplen;
            unsigned char *iccp;
        };
    };
} jp2_colr_t;

typedef struct jp2_cdefchan_t {
    uint_fast16_t channo;
    uint_fast16_t type;
    uint_fast16_t assoc;
} jp2_cdefchan_t;

typedef struct jp2_cdef_t {
    uint_fast16_t numchans;
    jp2_cdefchan_t *ents;
} jp2_cdef_t;

typedef struct jp2_box_t {
    uint_fast32_t len;
    uint_fast32_t type;
    union {
        struct {
            uint_fast32_t magic;
        } jp;
        jp2_ftyp_t ftyp;
        jp2_ihdr_t ihdr;
        jp2_bpcc_t bpcc;
        jp2_colr_t colr;
        jp2_cdef_t cdef;
    } data;
} jp2_box_t;

#define JP2_BOX_JP      0x6a502020
#define JP2_BOX_FTYP    0x66747970
#define JP2_BOX_JP2H    0x6a703268
#define JP2_BOX_IHDR    0x69686472
#define JP2_BOX_BPCC    0x62706363
#define JP2_BOX_COLR    0x636f6c72
#define JP2_BOX_CDEF    0x63646566
#define JP2_BOX_JP2C    0x6a703263

#define JP2_JP_MAGIC    0x0d0a870a
#define JP2_FTYP_MAJVER 0
#define JP2_FTYP_MINVER 0
#define JP2_FTYP_COMPATCODE 0x6a703220

#define JP2_IHDR_COMPTYPE 7
#define JP2_IHDR_BPCNULL 0xff

#define JP2_COLR_ENUM   1
#define JP2_COLR_ICC    2
#define JP2_COLR_PRI    1

#define JAS_CLRSPC_SRGB     1
#define JAS_CLRSPC_SYCBCR   2
#define JAS_CLRSPC_SGRAY    3

#define JAS_CLRSPC_FAM_RGB   1
#define JAS_CLRSPC_FAM_YCBCR 2
#define JAS_CLRSPC_FAM_GRAY  3

#define JAS_IMAGE_CT_COLOR(x) (x)
#define JAS_CLRSPC_CHANIND_RGB_R 0
#define JAS_CLRSPC_CHANIND_RGB_G 1
#define JAS_CLRSPC_CHANIND_RGB_B 2
#define JAS_CLRSPC_CHANIND_YCBCR_Y 0
#define JAS_CLRSPC_CHANIND_YCBCR_CB 1
#define JAS_CLRSPC_CHANIND_YCBCR_CR 2
#define JAS_IMAGE_CT_GRAY_Y 0

#define JP2_BOX_HDRLEN(ext) ((ext) ? 16 : 8)
#define JP2_SPTOBPC(sgnd, prec) (((sgnd) << 7) | ((prec) - 1))

jp2_box_t *jp2_box_create(uint_fast32_t type);
void jp2_box_destroy(jp2_box_t *box);
int jp2_box_put(jp2_box_t *box, jas_stream_t *out);
uint_fast32_t jp2_gettypeasoc(int clrspc, int cmpttype);
uint_fast32_t clrspctojp2(int clrspc);
int jas_image_numcmpts(jas_image_t *image);
int jas_image_width(jas_image_t *image);
int jas_image_height(jas_image_t *image);
int jas_image_cmptsgnd(jas_image_t *image, int cmptno);
int jas_image_cmptprec(jas_image_t *image, int cmptno);
int jas_image_clrspc(jas_image_t *image);
int jas_image_cmpttype(jas_image_t *image, int cmptno);
jas_cmprof_t *jas_image_cmprof(jas_image_t *image);
jas_iccprof_t *jas_iccprof_createfromcmprof(jas_cmprof_t *cmprof);
int jas_iccprof_save(jas_iccprof_t *prof, jas_stream_t *out);
void jas_iccprof_destroy(jas_iccprof_t *prof);
int jas_clrspc_fam(int clrspc);
void jas_eprintf(const char *fmt, ...);
jas_stream_t *jas_stream_memopen(char *buf, int bufsize);
int jas_stream_tell(jas_stream_t *stream);
void jas_stream_rewind(jas_stream_t *stream);
int jas_stream_copy(jas_stream_t *out, jas_stream_t *in, int n);
int jas_stream_read(jas_stream_t *stream, void *buf, int cnt);
void jas_stream_close(jas_stream_t *stream);
long jas_stream_getrwcount(jas_stream_t *stream);
void *jas_alloc2(size_t num_elements, size_t element_size);
void *jas_malloc(size_t size);
int jpc_encode(jas_image_t *image, jas_stream_t *out, const char *optstr);