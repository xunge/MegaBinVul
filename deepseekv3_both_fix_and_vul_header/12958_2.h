#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef signed long long s64;
typedef double Double;
typedef int Bool;
typedef int GF_Err;

#define GF_MAX_PATH 1024
#define GF_FILTER_NO_TS 0xFFFFFFFFFFFFFFFFULL
#define GF_FILTER_NO_BO 0xFFFFFFFFFFFFFFFFULL
#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_NOT_SUPPORTED 2
#define GF_OUT_OF_MEM 3
#define GF_URL_ERROR 4
#define GF_TRUE 1
#define GF_FALSE 0
#define LLU "llu"

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_PARSER 3

#define GF_DIMS_UNIT_S (1<<0)
#define GF_DIMS_UNIT_M (1<<1)
#define GF_DIMS_UNIT_I (1<<2)
#define GF_DIMS_UNIT_D (1<<3)
#define GF_DIMS_UNIT_P (1<<4)
#define GF_DIMS_UNIT_C (1<<5)

#define GF_BITSTREAM_WRITE 1

typedef enum {
    GF_FILTER_SAP_NONE,
    GF_FILTER_SAP_1
} GF_FilterSAPType;

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_XMLNode {
    int type;
    char *name;
    void *content;
    void *attributes;
} GF_XMLNode;

typedef struct GF_XMLAttribute {
    char *name;
    char *value;
} GF_XMLAttribute;

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_PropertyValue {
    const void *ptr;
    u32 size;
} GF_PropertyValue;

#define PROP_DATA(ptr, size) ((GF_PropertyValue){ptr, size})

typedef enum {
    GF_PROP_PCK_SUBS
} GF_PropertyTag;

typedef struct GF_NHMLDmxCtx {
    u32 current_child_idx;
    GF_XMLNode *root;
    Bool is_dims;
    char *src_url;
    u32 sample_num;
    u64 last_dts;
    u32 timescale;
    u32 compress_type;
    Bool has_sap;
    u32 samp_buffer_size;
    u32 samp_buffer_alloc;
    char *samp_buffer;
    GF_BitStream *bs_w;
    char *szMedia;
    FILE *mdia;
    u64 media_done;
    u32 dts_inc;
    Bool in_seek;
    u64 start_range;
    Bool use_dict;
    void *dictionary;
    Bool is_img;
    struct {
        u32 num, den;
    } duration;
    GF_FilterPid *opid;
    u32 parsing_state;
} GF_NHMLDmxCtx;

static int stricmp(const char *s1, const char *s2) {
    while (tolower(*s1) == tolower(*s2)) {
        if (*s1 == 0)
            return 0;
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

static void *gf_list_enum(void *list, u32 *index) { return NULL; }
static char *gf_url_concatenate(const char *base, const char *rel) { return NULL; }
static void gf_free(void *ptr) {}
static void *gf_realloc(void *ptr, size_t size) { return NULL; }
static FILE *gf_fopen(const char *path, const char *mode) { return NULL; }
static int gf_fseek(FILE *f, s64 offset, int whence) { return 0; }
static u64 gf_fsize(FILE *f) { return 0; }
static size_t gf_fread(void *ptr, size_t size, FILE *f) { return 0; }
static int gf_fclose(FILE *f) { return 0; }
static u32 gf_base64_decode(const char *in, u32 in_len, void *out, u32 out_size) { return 0; }
static void GF_LOG(u32 level, u32 module, const char *fmt, ...) {}

static GF_Err nhml_sample_from_xml(GF_NHMLDmxCtx *ctx, char *xml_file, char *szXmlFrom, char *szXmlTo) { return GF_OK; }
static char *gf_xml_dom_serialize(GF_XMLNode *node, Bool pretty, Bool xmldecl) { return NULL; }
static void nhml_get_bs(GF_BitStream **bs, void *buffer, u32 size, int mode) {}
static void gf_bs_write_u8(GF_BitStream *bs, u8 val) {}
static void gf_bs_write_u16(GF_BitStream *bs, u16 val) {}
static void gf_bs_write_u32(GF_BitStream *bs, u32 val) {}
static void gf_bs_write_data(GF_BitStream *bs, const void *data, u32 size) {}
static void gf_bs_reassign_buffer(GF_BitStream *bs, void *buffer, u32 size) {}
static void gf_bs_get_content(GF_BitStream *bs, void **buffer, u32 *size) {}
static u32 gf_bs_get_position(GF_BitStream *bs) { return 0; }
static void gf_xml_parse_bit_sequence_bs(GF_XMLNode *node, char *src_url, GF_BitStream *bs) {}
static GF_Err compress_sample_data(GF_NHMLDmxCtx *ctx, u32 compress_type, void *dictionary, u32 offset) { return GF_OK; }
static GF_FilterPacket *gf_filter_pck_new_alloc(GF_FilterPid *pid, u32 size, u8 **data) { return NULL; }
static void gf_filter_pck_set_framing(GF_FilterPacket *pck, Bool start, Bool end) {}
static void gf_filter_pck_set_sap(GF_FilterPacket *pck, GF_FilterSAPType sap) {}
static void gf_filter_pck_set_dts(GF_FilterPacket *pck, u64 dts) {}
static void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts) {}
static void gf_filter_pck_set_dependency_flags(GF_FilterPacket *pck, u32 flags) {}
static void gf_filter_pck_set_duration(GF_FilterPacket *pck, u32 duration) {}
static void gf_filter_pck_set_byte_offset(GF_FilterPacket *pck, u64 offset) {}
static void gf_filter_pck_set_seek_flag(GF_FilterPacket *pck, Bool seek) {}
static void gf_filter_pck_set_property(GF_FilterPacket *pck, GF_PropertyTag tag, GF_PropertyValue *value) {}
static void gf_filter_pck_send(GF_FilterPacket *pck) {}
static Bool gf_filter_pid_would_block(GF_FilterPid *pid) { return GF_FALSE; }