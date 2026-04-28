#include <stdlib.h>

typedef struct GF_Filter GF_Filter;
typedef struct GF_NHMLDmxCtx GF_NHMLDmxCtx;
typedef struct FILE GF_FILE;
typedef struct gf_bs_t GF_BitStream;
typedef struct gf_xml_dom GF_XMLDom;

#define GF_FILTER_GET_UDTA(filter) ((GF_NHMLDmxCtx*)filter->udta)
#define gf_fclose(f) fclose(f)
#define gf_free(ptr) free(ptr)
#define gf_bs_del(bs) free(bs)
#define gf_xml_dom_del(dom) free(dom)

#ifndef GPAC_DISABLE_ZLIB
#define ZLIB_BUFFER_SIZE 0
#endif

struct GF_NHMLDmxCtx {
    GF_FILE *mdia;
    GF_XMLDom *parser;
    char *dictionary;
    GF_BitStream *bs_r;
    GF_BitStream *bs_w;
    void *samp_buffer;
    void *zlib_buffer;
    char *media_file;
};