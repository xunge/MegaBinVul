#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef int Bool;

typedef enum {
    GF_OK = 0,
    GF_EOS,
    GF_OUT_OF_MEM
} GF_Err;

#define GF_FALSE 0
#define GF_TRUE 1

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;

typedef enum {
    GF_CODECID_AVC,
    GF_CODECID_HEVC,
    GF_CODECID_VVC
} GF_CodecID;

typedef enum {
    GF_FILTER_SAP_NONE,
    GF_FILTER_SAP_1,
    GF_FILTER_SAP_3
} GF_FilterSAPType;

typedef struct {
    u32 num;
    u32 den;
} GF_Fraction;

typedef struct {
    u32 max_sub_layers;
    u32 vps_id;
} HEVC_VPS;

typedef struct {
    HEVC_VPS *vps;
    struct {
        u32 vps_id;
        u32 nal_unit_type;
        u32 poc;
        u32 slice_type;
        Bool field_pic_flag;
        Bool bottom_field_flag;
        Bool redundant_pic_cnt;
        struct {
            u32 vps_id;
        } *sps;
    } s_info;
    struct {
        struct {
            Bool valid;
            u32 frame_cnt;
        } recovery_point;
    } sei;
} HEVC_State;

typedef struct {
    struct {
        Bool non_ref_pic;
        Bool recovery_point_valid;
        u32 gdr_recovery_count;
        u32 nal_unit_type;
        u32 poc;
        u32 slice_type;
        Bool irap_or_gdr_pic;
        Bool gdr_pic;
    } s_info;
} VVC_State;

typedef struct {
    struct {
        u32 nal_unit_type;
        u32 poc;
        u32 slice_type;
        Bool field_pic_flag;
        Bool bottom_field_flag;
        Bool redundant_pic_cnt;
    } s_info;
    struct {
        struct {
            Bool valid;
            u32 frame_cnt;
        } recovery_point;
    } sei;
} AVC_State;

typedef struct {
    char *log_name;
    u32 nb_nalus;
    u32 nb_i;
    u32 nb_p;
    u32 nb_b;
    u32 nb_sei;
    u32 width;
    u32 height;
    u32 max_nalu_size;
    u32 min_layer_id;
    u32 max_temporal_id;
    GF_CodecID codecid;
    Bool file_loaded;
    Bool is_playing;
    Bool first_pck_in_au;
    Bool first_slice_in_au;
    Bool has_islice;
    Bool in_seek;
    Bool is_mvc;
    Bool is_paff;
    Bool force_sync;
    Bool use_opengop_gdr;
    Bool full_au_source;
    Bool analyze;
    Bool strict_poc;
    Bool has_ref_slices;
    Bool has_redundant;
    Bool last_frame_is_idr;
    Bool poc_probe_done;
    Bool subsamples;
    Bool bottom_field_flag;
    GF_FilterSAPType au_sap;
    s32 poc_diff;
    s32 last_poc;
    s32 max_last_poc;
    s32 max_last_b_poc;
    s32 poc_shift;
    s32 sei_recovery_frame_count;
    u64 start_range;
    u64 cts;
    u32 dts_inc;
    GF_Fraction cur_fps;
    u32 nb_frames;
    u32 nb_idr;
    u32 nal_length;
    u8 *init_aud;
    Bool has_initial_aud;
    u8 *nal_store;
    u32 nal_store_size;
    u32 nal_store_alloc;
    u32 resume_from;
    u8 *svc_prefix_buffer;
    u32 svc_prefix_buffer_size;
    u32 svc_prefix_buffer_alloc;
    u32 svc_nalu_prefix_reserved;
    u8 svc_nalu_prefix_priority;
    u8 *sei_buffer;
    u32 sei_buffer_size;
    GF_FilterPacket *src_pck;
    GF_FilterPid *ipid;
    GF_FilterPid *opid;
    void *bs_r;
    void *bsdbg;
    void *pck_queue;
    void *deps;
    HEVC_State *hevc_state;
    VVC_State *vvc_state;
    AVC_State *avc_state;
} GF_NALUDmxCtx;

#define GF_FILTER_NO_BO 0
#define GF_FILTER_NO_TS 0
#define PROP_UINT(x) x
#define GPAC_DISABLE_HEVC 0
#define GPAC_DISABLE_LOG 0
#define GF_LOG_DEBUG 0
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 0
#define GF_LOG_PARSER 0
#define GF_LOG_CODING 0
#define GF_AVC_TYPE_B 0
#define GF_AVC_TYPE2_B 1
#define GF_AVC_NALU_IDR_SLICE 5
#define GF_AVC_NALU_SVC_PREFIX_NALU 14
#define GF_AVC_NALU_SVC_SLICE 20
#define GF_HEVC_NALU_VID_PARAM 32
#define GF_HEVC_NALU_SEQ_PARAM 33
#define GF_HEVC_NALU_PIC_PARAM 34
#define GF_HEVC_NALU_SEI_PREFIX 39
#define GF_HEVC_NALU_SEI_SUFFIX 40
#define GF_HEVC_NALU_SLICE_TRAIL_N 0
#define GF_HEVC_NALU_SLICE_TSA_N 2
#define GF_HEVC_NALU_SLICE_STSA_N 3
#define GF_HEVC_NALU_SLICE_RADL_N 4
#define GF_HEVC_NALU_SLICE_RASL_N 5
#define GF_HEVC_NALU_SLICE_RSV_VCL_N10 10
#define GF_HEVC_NALU_SLICE_RSV_VCL_N12 12
#define GF_HEVC_NALU_SLICE_RSV_VCL_N14 14
#define GF_HEVC_NALU_SLICE_BLA_W_LP 16
#define GF_HEVC_NALU_SLICE_BLA_W_DLP 17
#define GF_HEVC_NALU_SLICE_BLA_N_LP 18
#define GF_HEVC_NALU_SLICE_CRA 21
#define GF_VVC_NALU_OPI 0
#define GF_VVC_NALU_DEC_PARAM 1
#define GF_VVC_NALU_VID_PARAM 2
#define GF_VVC_NALU_SEQ_PARAM 3
#define GF_VVC_NALU_PIC_PARAM 4
#define GF_VVC_NALU_SEI_PREFIX 5
#define GF_VVC_NALU_SEI_SUFFIX 6
#define GF_VVC_NALU_APS_PREFIX 7
#define GF_VVC_NALU_APS_SUFFIX 8
#define GF_VVC_NALU_PIC_HEADER 9
#define GF_VVC_NALU_SLICE_TRAIL 10
#define GF_VVC_NALU_SLICE_STSA 11
#define GF_VVC_NALU_SLICE_RADL 12
#define GF_VVC_NALU_SLICE_RASL 13
#define GF_VVC_NALU_SLICE_IDR_W_RADL 14
#define GF_VVC_NALU_SLICE_IDR_N_LP 15
#define GF_VVC_NALU_SLICE_CRA 16
#define GF_VVC_NALU_SLICE_GDR 17
#define STRICT_POC_OFF 0
#define GF_BITSTREAM_READ 0
#define GF_PROP_PID_MAX_NALU_SIZE 0
#define LLU "%llu"

#define ABS(x) ((x) < 0 ? -(x) : (x))

static GF_Err naludmx_check_dur(GF_Filter *filter, GF_NALUDmxCtx *ctx) { return GF_OK; }
static GF_Err naludmx_finalize_au_flags(GF_NALUDmxCtx *ctx) { return GF_OK; }
static GF_Err naludmx_enqueue_or_dispatch(GF_NALUDmxCtx *ctx, void *pck, Bool flush) { return GF_OK; }
static GF_Err naludmx_check_pid(GF_Filter *filter, GF_NALUDmxCtx *ctx) { return GF_OK; }
static GF_Err naludmx_set_hevc_oinf(GF_NALUDmxCtx *ctx, u32 max_temporal_id) { return GF_OK; }
static GF_Err naludmx_set_hevc_linf(GF_NALUDmxCtx *ctx) { return GF_OK; }
static GF_Err naldmx_switch_timestamps(GF_NALUDmxCtx *ctx, GF_FilterPacket *pck) { return GF_OK; }
static GF_Err naldmx_check_timestamp_switch(GF_NALUDmxCtx *ctx, u32 *nalu_store_before, u32 size, Bool *drop_packet, GF_FilterPacket *pck) { return GF_OK; }
static GF_Err naludmx_realloc_last_pck(GF_NALUDmxCtx *ctx, u32 size, u8 **p_data) { return GF_OK; }
static GF_Err naludmx_parse_nal_hevc(GF_NALUDmxCtx *ctx, u8 *data, u32 size, Bool *skip_nal, Bool *is_slice, Bool *is_islice) { return GF_OK; }
static GF_Err naludmx_parse_nal_vvc(GF_NALUDmxCtx *ctx, u8 *data, u32 size, Bool *skip_nal, Bool *is_slice, Bool *is_islice) { return GF_OK; }
static GF_Err naludmx_parse_nal_avc(GF_NALUDmxCtx *ctx, u8 *data, u32 size, u32 nal_type, Bool *skip_nal, Bool *is_slice, Bool *is_islice) { return GF_OK; }
static GF_Err naludmx_start_nalu(GF_NALUDmxCtx *ctx, u32 size, Bool is_sei, Bool *au_start, u8 **p_data) { return GF_OK; }
static GF_Err naludmx_add_subsample(GF_NALUDmxCtx *ctx, u32 size, u8 priority, u32 reserved) { return GF_OK; }
static Bool gf_media_nalu_next_start_code(u8 *data, u32 size, u32 *sc_size) { return GF_FALSE; }
static Bool gf_hevc_slice_is_IDR(HEVC_State *state) { return GF_FALSE; }
static Bool gf_hevc_slice_is_intra(HEVC_State *state) { return GF_FALSE; }
static Bool gf_media_vvc_slice_is_ref(VVC_State *state) { return GF_FALSE; }
static Bool gf_media_avc_slice_is_intra(AVC_State *state) { return GF_FALSE; }
static void gf_filter_pid_drop_packet(GF_FilterPid *pid) {}
static void gf_filter_pck_unref(GF_FilterPacket *pck) {}
static void gf_filter_pid_set_info(GF_FilterPid *pid, u32 prop, void *value) {}
static void gf_filter_pid_set_info_str(GF_FilterPid *pid, const char *prop, void *value) {}
static void gf_filter_pid_set_eos(GF_FilterPid *pid) {}
static GF_FilterPacket *gf_filter_pid_get_packet(GF_FilterPid *pid) { return NULL; }
static Bool gf_filter_pid_is_eos(GF_FilterPid *pid) { return GF_FALSE; }
static const u8 *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size) { return NULL; }
static u64 gf_filter_pck_get_byte_offset(GF_FilterPacket *pck) { return 0; }
static Bool gf_filter_pid_would_block(GF_FilterPid *pid) { return GF_FALSE; }
static void *gf_bs_new(u8 *data, u32 size, u32 mode) { return NULL; }
static void gf_bs_reassign_buffer(void *bs, u8 *data, u32 size) {}
static u32 gf_list_count(void *list) { return 0; }
static void *gf_list_get(void *list, u32 idx) { return NULL; }
static u64 gf_filter_pck_get_dts(GF_FilterPacket *pck) { return 0; }
static u64 gf_filter_pck_get_cts(GF_FilterPacket *pck) { return 0; }
static void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts) {}
static void GF_LOG(u32 level, u32 tool, const char *fmt, ...) {}
static Bool gf_filter_reporting_enabled(GF_Filter *filter) { return GF_FALSE; }
static void gf_filter_update_status(GF_Filter *filter, s32 progress, const char *status) {}
static void *gf_realloc(void *ptr, size_t size) { return realloc(ptr, size); }
static GF_NALUDmxCtx *gf_filter_get_udta(GF_Filter *filter) { return NULL; }