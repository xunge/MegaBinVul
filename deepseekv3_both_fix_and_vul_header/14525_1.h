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
#define GF_LOG_DEBUG 0
#define GF_LOG_ERROR 1
#define GF_LOG_MEDIA 0
#define GF_FILTER_NO_TS 0
#define GF_FILTER_NO_BO 0
#define GF_BITSTREAM_READ 0
#define M2V_SEQ_START_CODE 0
#define M2V_EXT_START_CODE 1
#define M2V_PIC_START_CODE 2
#define M4V_VOS_START_CODE 3
#define M4V_VOL_START_CODE 4
#define M4V_VOP_START_CODE 5
#define M4V_GOV_START_CODE 6
#define M4V_VO_START_CODE 7
#define M4V_VISOBJ_START_CODE 8
#define GF_FILTER_SAP_NONE 0
#define GF_FILTER_SAP_1 1

typedef struct {
    u32 num;
    u32 den;
} GF_Fraction;

typedef struct {
    u8 VideoPL;
} GF_MPEG4VisualDSI;

typedef struct {
    GF_MPEG4VisualDSI dsi;
    u32 hdr_store_size;
    u32 hdr_store_alloc;
    char *hdr_store;
    u32 bytes_in_header;
    u32 resume_from;
    u64 cts;
    u64 dts;
    u64 prev_dts;
    GF_Fraction cur_fps;
    GF_Fraction duration;
    u32 timescale;
    double start_range;
    Bool recompute_cts;
    Bool input_is_au_start;
    Bool input_is_au_end;
    Bool is_mpg12;
    Bool is_playing;
    Bool in_seek;
    Bool frame_started;
    Bool forced_packed;
    Bool is_packed;
    Bool vfr;
    Bool is_vfr;
    u32 b_frames;
    u32 max_b;
    u32 nb_b;
    u32 nb_p;
    u32 nb_i;
    u32 nb_frames;
    u64 last_ref_cts;
    void *ipid;
    void *opid;
    void *src_pck;
    void *bs;
    void *vparser;
} GF_MPGVidDmxCtx;

typedef struct {
} GF_Filter;
typedef struct {
} GF_FilterPacket;
typedef struct {
} GF_FilterPID;

void *gf_filter_get_udta(GF_Filter *filter);
void *gf_filter_pid_get_packet(void *ipid);
Bool gf_filter_pid_is_eos(void *ipid);
void gf_filter_pid_set_eos(void *opid);
void gf_filter_pck_unref(void *src_pck);
char *gf_filter_pck_get_data(void *pck, u32 *pck_size);
u64 gf_filter_pck_get_byte_offset(void *pck);
u64 gf_filter_pck_get_cts(void *pck);
u64 gf_filter_pck_get_dts(void *pck);
void gf_filter_pck_get_framing(void *pck, Bool *input_is_au_start, Bool *input_is_au_end);
void gf_filter_pck_ref_props(void **src_pck);
void *gf_filter_pck_new_alloc(void *opid, u32 size, u8 **pck_data);
void gf_filter_pck_merge_properties(void *src_pck, void *dst_pck);
void gf_filter_pck_set_framing(void *dst_pck, Bool start, Bool end);
void gf_filter_pck_set_cts(void *dst_pck, u64 cts);
void gf_filter_pck_set_dts(void *dst_pck, u64 dts);
void gf_filter_pck_set_byte_offset(void *dst_pck, u64 offset);
void gf_filter_pck_set_carousel_version(void *dst_pck, u32 version);
void gf_filter_pck_set_sap(void *dst_pck, u32 sap);
void gf_filter_pck_set_duration(void *dst_pck, u32 duration);
void gf_filter_pck_set_seek_flag(void *dst_pck, Bool flag);
void gf_filter_pid_drop_packet(void *ipid);
Bool gf_filter_pid_would_block(void *opid);
void *gf_bs_new(u8 *start, s32 remain, u32 mode);
void gf_bs_reassign_buffer(void *bs, u8 *start, s32 remain);
u8 gf_bs_read_int(void *bs, u32 bits);
u8 gf_bs_read_u8(void *bs);
void *gf_m4v_parser_bs_new(void *bs, Bool is_mpg12);
GF_Err gf_m4v_parse_config(void *vparser, GF_MPEG4VisualDSI *dsi);
GF_Err gf_m4v_parse_frame(void *vparser, GF_MPEG4VisualDSI *dsi, u8 *ftype, u32 *tinc, u64 *size, u64 *fstart, Bool *is_coded);
void gf_m4v_parser_reset(void *vparser, u32 type);
u64 gf_m4v_get_object_start(void *vparser);
void *gf_realloc(void *ptr, size_t size);
s32 mpgviddmx_next_start_code(u8 *start, u32 remain);
void mpgviddmx_check_dur(GF_Filter *filter, GF_MPGVidDmxCtx *ctx);
void mpgviddmx_enqueue_or_dispatch(GF_MPGVidDmxCtx *ctx, void *dst_pck, Bool flush, Bool eos);
void mpgviddmx_check_pid(GF_Filter *filter, GF_MPGVidDmxCtx *ctx, u32 vosh_end, char *data);
void mpgviddmx_update_time(GF_MPGVidDmxCtx *ctx);
void GF_LOG(u32 level, u32 module, const char *fmt, ...);
const char *gf_error_to_string(GF_Err e);