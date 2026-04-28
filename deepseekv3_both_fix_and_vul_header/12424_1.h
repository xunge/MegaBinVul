#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GF_NHMLDumpCtx GF_NHMLDumpCtx;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_PropertyValue GF_PropertyValue;
typedef struct __tag_bitstream GF_BitStream;

#define GF_STREAM_VISUAL 1
#define GF_STREAM_SCENE 2
#define GF_CODECID_LAST_MPEG4_MAPPING 0
#define GF_CODECID_DIMS 0
#define GF_PROP_PID_ID 0
#define GF_PROP_PID_TIMESCALE 0
#define GF_PROP_PID_IN_IOD 0
#define GF_PROP_PID_SUBTYPE 0
#define GF_PROP_PID_ISOM_SUBTYPE 0
#define GF_PROP_PID_CODECID 0
#define GF_PROP_PID_BIT_DEPTH_Y 0
#define GF_PROP_PID_AUDIO_FORMAT 0

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_LOG_ERROR 0
#define GF_LOG_AUTHOR 0

#define NHML_PRINT_UINT(a,b,c)
#define NHML_PRINT_4CC(a,b,c) 
#define NHML_PRINT_STRING(a,b,c)

struct GF_NHMLDumpCtx {
    const char *szRootName;
    int dims;
    FILE *filep;
    GF_BitStream *bs_w;
    GF_FilterPacket *ipid;
    u32 oti;
    u32 streamtype;
    u32 w;
    u32 h;
    u32 sr;
    u32 chan;
    u32 codecid;
    GF_FilterPacket *opid_info;
    char *info_file;
    u8 *dcfg;
    u32 dcfg_size;
    GF_FilterPacket *opid_mdia;
    GF_FilterPacket *opid_nhml;
    char *media_file;
    u8 *nhml_buffer;
    u32 nhml_buffer_size;
    int uncompress;
};

struct GF_PropertyValue {
    union {
        u32 uint;
        int boolean;
        char *string;
    } value;
};

extern const char *gf_4cc_to_str(u32 fourcc);
extern u32 gf_audio_fmt_bit_depth(u32 fmt);
extern const char *gf_file_basename(const char *path);
extern void gf_bs_write_data(GF_BitStream *bs, const char *data, u32 size);
extern void gf_bs_get_content_no_truncate(GF_BitStream *bs, u8 **output, u32 *size, u32 *alloc_size);
extern GF_FilterPacket *gf_filter_pck_new_shared(GF_FilterPacket *pid, const void *data, u32 size, void *udta);
extern GF_FilterPacket *gf_filter_pck_new_alloc(GF_FilterPacket *pid, u32 size, u8 **data);
extern void gf_filter_pck_set_framing(GF_FilterPacket *pck, int start, int end);
extern void gf_filter_pck_set_readonly(GF_FilterPacket *pck);
extern void gf_filter_pck_send(GF_FilterPacket *pck);
extern const GF_PropertyValue *gf_filter_pid_get_property(GF_FilterPacket *pid, u32 prop);
extern const GF_PropertyValue *gf_filter_pid_get_property_str(GF_FilterPacket *pid, const char *prop);
extern void GF_LOG(int level, int author, const char *fmt, ...);
extern size_t gf_fwrite(const void *ptr, size_t size, FILE *stream);