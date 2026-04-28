#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef int8_t Bool;

#define GF_FALSE 0
#define GF_TRUE 1

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_MEDIA 3

#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 0
#define GF_AVC_NALU_SEQ_PARAM 1
#define GF_AVC_NALU_PIC_PARAM 2
#define GF_AVC_NALU_SEQ_PARAM_EXT 3
#define GF_AVC_NALU_SEI 4
#define GF_AVC_NALU_ACCESS_UNIT 5
#define GF_AVC_NALU_FILLER_DATA 6
#define GF_AVC_NALU_END_OF_SEQ 7
#define GF_AVC_NALU_END_OF_STREAM 8
#define GF_AVC_NALU_NON_IDR_SLICE 9
#define GF_AVC_NALU_DP_A_SLICE 10
#define GF_AVC_NALU_DP_B_SLICE 11
#define GF_AVC_NALU_DP_C_SLICE 12
#define GF_AVC_NALU_IDR_SLICE 13
#define GF_AVC_NALU_SVC_SLICE 14
#define GF_AVC_NALU_SLICE_AUX 15
#define GF_AVC_NALU_DV_RPU 16
#define GF_AVC_NALU_DV_EL 17

#define GF_AVC_TYPE_P 0
#define GF_AVC_TYPE2_P 1
#define GF_AVC_TYPE_I 2
#define GF_AVC_TYPE2_I 3
#define GF_AVC_TYPE_B 4
#define GF_AVC_TYPE2_B 5
#define GF_AVC_TYPE_SP 6
#define GF_AVC_TYPE2_SP 7
#define GF_AVC_TYPE_SI 8
#define GF_AVC_TYPE2_SI 9

#define DVMODE_CLEAN 0
#define DVMODE_SINGLE 1

typedef struct {
    int last_ps_idx;
    int sps_active_idx;
    struct {
        int profile_idc;
    } sps[16];
    struct {
        int slice_type;
        int poc;
        struct {
            int id;
            int nb_ep;
            int nb_ei;
            int nb_eb;
        } *sps;
        struct {
            int id;
        } *pps;
    } s_info;
} GF_AVCState;

typedef struct {
    int id;
} GF_NALUFFParam;

typedef struct {
    void *bs_r;
    GF_AVCState *avc_state;
    char *log_name;
    u32 nb_nalus;
    u32 nb_sei;
    u32 nb_aud;
    u32 nb_p;
    u32 nb_i;
    u32 nb_b;
    u32 nb_sp;
    u32 nb_si;
    u32 nb_dv_rpu;
    u32 nb_dv_el;
    u32 sei_buffer_size;
    u32 last_poc;
    Bool nosei;
    Bool audelim;
    Bool opid;
    Bool has_initial_aud;
    Bool is_mvc;
    Bool explicit;
    Bool ps_modified;
    int dv_mode;
    char init_aud[2];
    void *pps;
    void *pps_svc;
} GF_NALUDmxCtx;

void gf_bs_reassign_buffer(void *bs, char *data, u32 size);
int gf_avc_parse_nalu(void *bs, GF_AVCState *state);
void GF_LOG(int level, int category, const char *fmt, ...);
void naludmx_queue_param_set(GF_NALUDmxCtx *ctx, char *data, u32 size, u32 type, s32 idx, u32 flags, u32 flags2);
void naludmx_push_prefix(GF_NALUDmxCtx *ctx, char *data, u32 size, Bool flag);
void naludmx_set_dolby_vision(GF_NALUDmxCtx *ctx);