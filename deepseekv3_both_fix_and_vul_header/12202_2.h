#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef signed long long s64;
typedef int Bool;
typedef int GF_Err;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_OK 0
#define GF_EOS 1
#define GF_OUT_OF_MEM 2
#define GF_NON_COMPLIANT_BITSTREAM 3
#define GF_BITSTREAM_READ 0

#define GF_FILTER_NO_TS 0
#define GF_FILTER_NO_BO 0
#define GF_FILTER_SAP_NONE 0
#define GF_FILTER_SAP_1 1

#define GF_LOG_DEBUG 0
#define GF_LOG_ERROR 1
#define GF_LOG_MEDIA 2

#define MIN_HDR_STORE 4

typedef struct {
    u32 num;
    u32 den;
} GF_Fraction;

typedef struct {
    u32 width;
    u32 height;
    u8 VideoPL;
} GF_M4VDecSpecInfo;

typedef struct GF_FilterPacket GF_FilterPacket;

typedef struct {
    GF_Fraction duration;
    GF_Fraction cur_fps;
    u32 timescale;
    u64 cts;
    u64 dts;
    u64 prev_dts;
    u32 width;
    u32 height;
    u32 hdr_store_size;
    u32 hdr_store_alloc;
    char *hdr_store;
    u32 bytes_in_header;
    u32 resume_from;
    Bool is_mpg12;
    Bool notime;
    Bool recompute_cts;
    Bool input_is_au_start;
    Bool input_is_au_end;
    Bool frame_started;
    Bool is_playing;
    Bool in_seek;
    Bool trash_trailer;
    Bool forced_packed;
    Bool b_frames;
    Bool vfr;
    Bool is_vfr;
    Bool is_packed;
    u32 nb_b;
    u32 nb_p;
    u32 nb_i;
    u32 nb_frames;
    u32 max_b;
    u64 last_ref_cts;
    u64 start_range;
    u32 dts_inc;
    void *bs;
    void *vparser;
    void *ipid;
    void *opid;
    GF_FilterPacket *src_pck;
    GF_M4VDecSpecInfo dsi;
} GF_MPGVidDmxCtx;

typedef struct {
    int dummy;
} GF_Filter;

typedef struct {
    int dummy;
} GF_FilterPid;

#define M2V_SEQ_START_CODE 0xB3
#define M2V_EXT_START_CODE 0xB5
#define M2V_PIC_START_CODE 0x00
#define M4V_VOS_START_CODE 0xB0
#define M4V_VOL_START_CODE 0xB3
#define M4V_VOP_START_CODE 0xB6
#define M4V_GOV_START_CODE 0xB5
#define M4V_VO_START_CODE 0xB1
#define M4V_VISOBJ_START_CODE 0xB2

static void mpgviddmx_check_dur(GF_Filter *filter, GF_MPGVidDmxCtx *ctx) {}
static void mpgviddmx_enqueue_or_dispatch(GF_MPGVidDmxCtx *ctx, GF_FilterPacket *pck, Bool flush, Bool is_eos) {}
static void mpgviddmx_check_pid(GF_Filter *filter, GF_MPGVidDmxCtx *ctx, u32 size, char *data) {}
static void mpgviddmx_update_time(GF_MPGVidDmxCtx *ctx) {}
static s32 mpgviddmx_next_start_code(u8 *data, u32 size) { return 0; }

static GF_FilterPacket *gf_filter_pck_new_alloc(void *opid, u32 size, u8 **data) { return NULL; }
static void gf_filter_pck_merge_properties(GF_FilterPacket *src, GF_FilterPacket *dst) {}
static void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts) {}
static void gf_filter_pck_set_dts(GF_FilterPacket *pck, u64 dts) {}
static void gf_filter_pck_set_framing(GF_FilterPacket *pck, Bool is_start, Bool is_end) {}
static void gf_filter_pck_set_byte_offset(GF_FilterPacket *pck, u64 offset) {}
static void gf_filter_pck_set_sap(GF_FilterPacket *pck, int sap) {}
static void gf_filter_pck_set_duration(GF_FilterPacket *pck, u32 duration) {}
static void gf_filter_pck_set_seek_flag(GF_FilterPacket *pck, Bool flag) {}
static void gf_filter_pck_set_carousel_version(GF_FilterPacket *pck, int version) {}
static void gf_filter_pck_unref(GF_FilterPacket *pck) {}
static void gf_filter_pck_ref_props(GF_FilterPacket **pck) {}

static GF_FilterPacket *gf_filter_pid_get_packet(void *ipid) { return NULL; }
static Bool gf_filter_pid_is_eos(void *ipid) { return GF_FALSE; }
static void gf_filter_pid_set_eos(void *opid) {}
static void gf_filter_pid_drop_packet(void *ipid) {}
static Bool gf_filter_pid_would_block(void *opid) { return GF_FALSE; }

static GF_MPGVidDmxCtx *gf_filter_get_udta(GF_Filter *filter) { return NULL; }
static char *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size) { return NULL; }
static u64 gf_filter_pck_get_byte_offset(GF_FilterPacket *pck) { return 0; }
static u64 gf_filter_pck_get_cts(GF_FilterPacket *pck) { return 0; }
static u64 gf_filter_pck_get_dts(GF_FilterPacket *pck) { return 0; }
static void gf_filter_pck_get_framing(GF_FilterPacket *pck, Bool *is_start, Bool *is_end) {}

static void *gf_bs_new(u8 *data, u32 size, int mode) { return NULL; }
static void gf_bs_reassign_buffer(void *bs, u8 *data, u32 size) {}
static u8 gf_bs_read_u8(void *bs) { return 0; }
static u32 gf_bs_read_int(void *bs, int bits) { return 0; }

static void *gf_m4v_parser_bs_new(void *bs, Bool is_mpg12) { return NULL; }
static GF_Err gf_m4v_parse_config(void *parser, GF_M4VDecSpecInfo *dsi) { return GF_OK; }
static u64 gf_m4v_get_object_start(void *parser) { return 0; }
static void gf_m4v_parser_reset(void *parser, int type) {}
static GF_Err gf_m4v_parse_frame(void *parser, GF_M4VDecSpecInfo *dsi, u8 *ftype, u32 *tinc, u64 *size, u64 *fstart, Bool *is_coded) { return GF_OK; }

static void *gf_realloc(void *ptr, size_t size) { return realloc(ptr, size); }
static void GF_LOG(int level, int category, const char *format, ...) {}
static const char *gf_error_to_string(GF_Err e) { return ""; }