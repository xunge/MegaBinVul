#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct jas_image_t {
    void* cmprof_;
} jas_image_t;

typedef struct jas_stream_t jas_stream_t;

typedef struct jp2_boxinfo_t {
    char* name;
} jp2_boxinfo_t;

typedef struct jp2_cdefchan_t {
    uint16_t channo;
    uint16_t type;
    uint16_t assoc;
} jp2_cdefchan_t;

typedef struct jp2_cmapent_t {
    uint16_t cmptno;
    uint8_t map;
    uint8_t pcol;
} jp2_cmapent_t;

typedef struct jp2_cmap_t {
    uint32_t numchans;
    jp2_cmapent_t* ents;
} jp2_cmap_t;

typedef struct jp2_pclr_t {
    uint32_t numlutents;
    uint32_t numchans;
    uint8_t* bpc;
    int_fast32_t* lutdata;
} jp2_pclr_t;

typedef struct jp2_cdef_t {
    uint32_t numchans;
    jp2_cdefchan_t* ents;
} jp2_cdef_t;

typedef struct jp2_colr_t {
    uint8_t method;
    uint8_t* iccp;
    uint32_t iccplen;
} jp2_colr_t;

typedef struct jp2_box_t {
    uint32_t type;
    union {
        struct {
            uint32_t magic;
        } jp;
        struct {
            uint32_t numcmpts;
            uint8_t bpc;
            uint8_t comptype;
        } ihdr;
        struct {
            uint32_t numcmpts;
            uint8_t* bpcs;
        } bpcc;
        struct {
            uint32_t numchans;
            jp2_cdefchan_t* ents;
        } cdef;
        struct {
            uint32_t numlutents;
            uint32_t numchans;
            uint8_t* bpc;
            int_fast32_t* lutdata;
        } pclr;
        struct {
            uint32_t numchans;
            jp2_cmapent_t* ents;
        } cmap;
        jp2_colr_t colr;
    } data;
    jp2_boxinfo_t* info;
} jp2_box_t;

typedef struct jp2_dec_t {
    jas_image_t* image;
    jp2_box_t* ihdr;
    jp2_box_t* bpcc;
    jp2_box_t* cdef;
    jp2_box_t* pclr;
    jp2_box_t* cmap;
    jp2_box_t* colr;
    uint_fast16_t* chantocmptlut;
    uint32_t numchans;
} jp2_dec_t;

typedef struct jas_icchdr_t {
    uint32_t colorspc;
} jas_icchdr_t;

typedef struct jas_iccprof_t jas_iccprof_t;

#define JAS_DBGLOG(level, msg)
#define JAS_CAST(type, val) ((type)(val))
#define JAS_IMAGE_CT_UNKNOWN 0
#define JP2_BOX_JP 0x6a502020
#define JP2_BOX_FTYP 0x66747970
#define JP2_BOX_JP2C 0x6a703263
#define JP2_BOX_IHDR 0x69686472
#define JP2_BOX_BPCC 0x62706363
#define JP2_BOX_CDEF 0x63646566
#define JP2_BOX_PCLR 0x70636c72
#define JP2_BOX_CMAP 0x636d6170
#define JP2_BOX_COLR 0x636f6c72
#define JP2_JP_MAGIC 0x0d0a870a
#define JP2_IHDR_COMPTYPE 7
#define JP2_IHDR_BPCNULL 255
#define JP2_COLR_ENUM 1
#define JP2_COLR_ICC 2
#define JP2_CMAP_DIRECT 0
#define JP2_CMAP_PALETTE 1

typedef unsigned int jas_uint;

jp2_box_t* jp2_box_get(jas_stream_t* in);
void jp2_box_destroy(jp2_box_t* box);
jp2_dec_t* jp2_dec_create(void);
void jp2_dec_destroy(jp2_dec_t* dec);
jas_image_t* jpc_decode(jas_stream_t* in, const char* optstr);
int jas_image_numcmpts(jas_image_t* image);
int jas_image_cmptdtype(jas_image_t* image, int cmptno);
int jas_image_cmpttype(jas_image_t* image, int cmptno);
int jas_image_clrspc(jas_image_t* image);
void jas_image_setclrspc(jas_image_t* image, int clrspc);
void jas_image_setcmpttype(jas_image_t* image, int cmptno, int type);
void jas_image_delcmpt(jas_image_t* image, int cmptno);
void jas_image_depalettize(jas_image_t* image, int cmptno, int numlutents, int_fast32_t* lutents, int dtype, int newcmptno);
jas_iccprof_t* jas_iccprof_createfrombuf(unsigned char* buf, int len);
void jas_iccprof_gethdr(jas_iccprof_t* prof, jas_icchdr_t* hdr);
void jas_iccprof_destroy(jas_iccprof_t* prof);
void* jas_alloc2(size_t num_elements, size_t element_size);
void jas_free(void* ptr);
void* jas_cmprof_createfromiccprof(jas_iccprof_t* iccprof);
int jp2_getcs(jp2_colr_t* colr);
int fromiccpcs(int colorspc);
int JP2_DTYPETOBPC(int dtype);
int JP2_BPCTODTYPE(int bpc);
int jp2_getct(int clrspc, int type, int assoc);
void jas_eprintf(const char* format, ...);
int jas_getdbglevel(void);