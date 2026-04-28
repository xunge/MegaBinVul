#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef int Bool;

#define GF_FALSE 0
#define GF_TRUE 1

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_PARSER 3

#define GF_BITSTREAM_WRITE 1

#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 1
#define GF_AVC_NALU_SEQ_PARAM 2
#define GF_AVC_NALU_PIC_PARAM 3
#define GF_AVC_NALU_SEQ_PARAM_EXT 4
#define GF_AVC_NALU_SEI 5
#define GF_AVC_NALU_ACCESS_UNIT 6
#define GF_AVC_NALU_FILLER_DATA 7
#define GF_AVC_NALU_END_OF_SEQ 8
#define GF_AVC_NALU_END_OF_STREAM 9
#define GF_AVC_NALU_NON_IDR_SLICE 10
#define GF_AVC_NALU_DP_A_SLICE 11
#define GF_AVC_NALU_DP_B_SLICE 12
#define GF_AVC_NALU_DP_C_SLICE 13
#define GF_AVC_NALU_IDR_SLICE 14
#define GF_AVC_NALU_SVC_SLICE 15
#define GF_AVC_NALU_SLICE_AUX 16

#define GF_AVC_TYPE_P 1
#define GF_AVC_TYPE2_P 2
#define GF_AVC_TYPE_I 3
#define GF_AVC_TYPE2_I 4
#define GF_AVC_TYPE_B 5
#define GF_AVC_TYPE2_B 6
#define GF_AVC_TYPE_SP 7
#define GF_AVC_TYPE2_SP 8
#define GF_AVC_TYPE_SI 9
#define GF_AVC_TYPE2_SI 10

typedef struct {
    int poc;
    int slice_type;
    struct {
        int id;
    } *pps;
    struct {
        int nb_ep;
        int nb_ei;
        int nb_eb;
    } *sps;
} GF_AVCSliceInfo;

typedef struct {
    int last_ps_idx;
    struct {
        int profile_idc;
    } sps[1];
    GF_AVCSliceInfo s_info;
    int sps_active_idx;
} GF_AVCState;

typedef struct {
    int id;
} GF_NALUFFParam;

typedef struct {
    void *bs_r;
    void *bs_w;
    GF_AVCState *avc_state;
    char *log_name;
    u32 nb_nalus;
    u32 nb_aud;
    u32 sei_buffer_alloc;
    u32 sei_buffer_size;
    char *sei_buffer;
    u32 nal_length;
    int seirw;
    int nosei;
    u32 nb_sei;
    int audelim;
    int opid;
    int has_initial_aud;
    char init_aud[2];
    int is_mvc;
    int last_poc;
    int explicit;
    void *pps;
    void *pps_svc;
    int ps_modified;
    u32 nb_p;
    u32 nb_i;
    u32 nb_b;
    u32 nb_sp;
    u32 nb_si;
} GF_NALUDmxCtx;

void gf_bs_reassign_buffer(void *bs, char *data, u32 size);
int gf_avc_parse_nalu(void *bs, GF_AVCState *state);
void GF_LOG(int level, int category, const char *format, ...);
void naludmx_queue_param_set(GF_NALUDmxCtx *ctx, char *data, u32 size, u32 type, s32 idx);
void *gf_bs_new(void *data, u32 size, int mode);
void gf_bs_seek(void *bs, u32 pos);
void gf_bs_write_int(void *bs, u32 value, u32 bits);
u32 gf_media_avc_reformat_sei(char *data, u32 size, int seirw, GF_AVCState *state);
void *gf_realloc(void *ptr, u32 size);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_rem(void *list, u32 index);
void *gf_list_new(void *list);
void gf_list_add(void *list, void *item);