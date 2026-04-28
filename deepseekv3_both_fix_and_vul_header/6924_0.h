#include <stdint.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef struct {
    int last_parsed_vps_id;
    int last_parsed_sps_id;
    int last_parsed_pps_id;
    struct {
        int slice_type;
    } s_info;
} HEVCState;

typedef struct {
    u8 *bs_r;
    HEVCState *hevc_state;
    u32 nb_nalus;
    char *log_name;
    Bool nosvc;
    Bool novpsext;
    Bool nosei;
    Bool is_playing;
    u32 nb_sei;
    u32 nb_p;
    u32 nb_i;
    u32 nb_b;
    u32 nb_e_p;
    u32 nb_e_i;
    u32 nb_e_b;
    u32 last_layer_id;
    u32 last_temporal_id;
    u32 nb_aud;
    Bool audelim;
    u32 opid;
    Bool has_initial_aud;
    u8 init_aud[3];
    u32 dv_mode;
    u32 nb_dv_rpu;
    u32 nb_dv_el;
    u32 max_temporal_id[16];
    u32 min_layer_id;
    struct {
        u32 layer_id_plus_one;
        u32 max_temporal_id;
        u32 min_temporal_id;
    } linf[16];
} GF_NALUDmxCtx;

#define GF_HEVC_NALU_VID_PARAM 32
#define GF_HEVC_NALU_SEQ_PARAM 33
#define GF_HEVC_NALU_PIC_PARAM 34
#define GF_HEVC_NALU_SEI_PREFIX 39
#define GF_HEVC_NALU_SEI_SUFFIX 40
#define GF_HEVC_NALU_SLICE_STSA_N 0
#define GF_HEVC_NALU_SLICE_STSA_R 1
#define GF_HEVC_NALU_SLICE_RADL_R 2
#define GF_HEVC_NALU_SLICE_RASL_R 3
#define GF_HEVC_NALU_SLICE_RADL_N 4
#define GF_HEVC_NALU_SLICE_RASL_N 5
#define GF_HEVC_NALU_SLICE_TRAIL_N 6
#define GF_HEVC_NALU_SLICE_TRAIL_R 7
#define GF_HEVC_NALU_SLICE_TSA_N 8
#define GF_HEVC_NALU_SLICE_TSA_R 9
#define GF_HEVC_NALU_SLICE_BLA_W_LP 16
#define GF_HEVC_NALU_SLICE_BLA_W_DLP 17
#define GF_HEVC_NALU_SLICE_BLA_N_LP 18
#define GF_HEVC_NALU_SLICE_IDR_W_DLP 19
#define GF_HEVC_NALU_SLICE_IDR_N_LP 20
#define GF_HEVC_NALU_SLICE_CRA 21
#define GF_HEVC_NALU_ACCESS_UNIT 35
#define GF_HEVC_NALU_FILLER_DATA 38
#define GF_HEVC_NALU_END_OF_SEQ 36
#define GF_HEVC_NALU_END_OF_STREAM 37
#define GF_HEVC_NALU_DV_RPU 62
#define GF_HEVC_NALU_DV_EL 63

#define GF_HEVC_SLICE_TYPE_P 0
#define GF_HEVC_SLICE_TYPE_I 1
#define GF_HEVC_SLICE_TYPE_B 2

#define DVMODE_CLEAN 0
#define DVMODE_SINGLE 1

#define GPAC_DISABLE_HEVC 0

void gf_bs_reassign_buffer(u8 *bs, char *data, u32 size);
int gf_hevc_parse_nalu_bs(u8 *bs, HEVCState *state, u8 *nal_unit_type, u8 *temporal_id, u8 *layer_id);
int gf_hevc_read_vps_ex(char *data, u32 *size, HEVCState *state, Bool flag);
void gf_hevc_parse_sei(char *data, u32 size, HEVCState *state);
void naludmx_queue_param_set(GF_NALUDmxCtx *ctx, char *data, u32 size, u32 type, s32 idx, u8 temporal_id, u8 layer_id);
void naludmx_push_prefix(GF_NALUDmxCtx *ctx, char *data, u32 size, Bool flag);
void naludmx_set_dolby_vision(GF_NALUDmxCtx *ctx);

enum {
    GF_LOG_ERROR,
    GF_LOG_WARNING,
    GF_LOG_MEDIA
};
void GF_LOG(int level, int category, const char *fmt, ...);