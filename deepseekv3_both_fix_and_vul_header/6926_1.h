#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;

#define GF_FALSE 0
#define GF_TRUE 1

#define GF_LOG_ERROR 0
#define GF_LOG_MEDIA 0
#define GF_LOG_WARNING 0

enum {
    GF_VVC_NALU_VID_PARAM = 32,
    GF_VVC_NALU_SEQ_PARAM = 33,
    GF_VVC_NALU_PIC_PARAM = 34,
    GF_VVC_NALU_DEC_PARAM = 35,
    GF_VVC_NALU_OPI = 36,
    GF_VVC_NALU_APS_PREFIX = 37,
    GF_VVC_NALU_SEI_PREFIX = 38,
    GF_VVC_NALU_SEI_SUFFIX = 39,
    GF_VVC_NALU_PIC_HEADER = 40,
    GF_VVC_NALU_SLICE_TRAIL = 41,
    GF_VVC_NALU_SLICE_STSA = 42,
    GF_VVC_NALU_SLICE_RADL = 43,
    GF_VVC_NALU_SLICE_RASL = 44,
    GF_VVC_NALU_SLICE_IDR_W_RADL = 45,
    GF_VVC_NALU_SLICE_IDR_N_LP = 46,
    GF_VVC_NALU_SLICE_CRA = 47,
    GF_VVC_NALU_SLICE_GDR = 48,
    GF_VVC_NALU_ACCESS_UNIT = 49,
    GF_VVC_NALU_FILLER_DATA = 50,
    GF_VVC_NALU_END_OF_SEQ = 51,
    GF_VVC_NALU_END_OF_STREAM = 52
};

enum {
    GF_VVC_SLICE_TYPE_P = 0,
    GF_VVC_SLICE_TYPE_I = 1,
    GF_VVC_SLICE_TYPE_B = 2,
    GF_VVC_SLICE_TYPE_UNKNOWN = 3
};

typedef struct {
    int last_parsed_vps_id;
    int last_parsed_sps_id;
    int last_parsed_pps_id;
    int last_parsed_aps_id;
    struct {
        int slice_type;
    } s_info;
} GF_VVCState;

typedef struct {
    u32 max_temporal_id;
    u32 min_temporal_id;
    u32 layer_id_plus_one;
} LayerInfo;

typedef struct {
    void* bs_r;
    GF_VVCState* vvc_state;
    char* log_name;
    u32 nb_nalus;
    u32 nb_sei;
    u32 nb_aud;
    u32 nb_p;
    u32 nb_i;
    u32 nb_b;
    u32 nb_e_p;
    u32 nb_e_i;
    u32 nb_e_b;
    u32 last_layer_id;
    u32 last_temporal_id;
    u32 max_temporal_id[256];
    u32 min_layer_id;
    Bool nosvc;
    Bool novpsext;
    Bool nosei;
    Bool is_playing;
    Bool vvc_no_stats;
    Bool has_initial_aud;
    u8 init_aud[3];
    int opid;
    LayerInfo linf[256];
} GF_NALUDmxCtx;

void gf_bs_reassign_buffer(void* bs_r, char* data, u32 size);
int gf_vvc_parse_nalu_bs(void* bs_r, GF_VVCState* vvc_state, u8* nal_unit_type, u8* temporal_id, u8* layer_id);
void GF_LOG(int level, int media, const char* fmt, ...);
void naludmx_queue_param_set(GF_NALUDmxCtx* ctx, char* data, u32 size, int type, int ps_idx, u8 temporal_id, u8 layer_id);
void naludmx_push_prefix(GF_NALUDmxCtx* ctx, char* data, u32 size, Bool flag);
void gf_vvc_parse_sei(char* data, u32 size, GF_VVCState* vvc_state);