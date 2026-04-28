#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

typedef struct GF_BitStream GF_BitStream;

typedef struct {
    int poc_type;
} AVCSPS;

typedef struct {
    u8 nal_unit_type;
    u8 nal_ref_idc;
    u32 frame_num;
    u32 poc;
    u32 poc_lsb;
    u32 poc_msb;
    u32 poc_lsb_prev;
    u32 poc_msb_prev;
    u32 frame_num_prev;
    u32 frame_num_offset;
    u32 frame_num_offset_prev;
    u8 field_pic_flag;
    u8 bottom_field_flag;
    u8 idr_pic_id;
    s32 delta_poc[2];
    s32 delta_poc_bottom;
    AVCSPS *sps;
    void *NalHeader;
} AVCSliceInfo;

typedef struct {
    AVCSliceInfo s_info;
    s32 last_nal_type_parsed;
    s32 last_ps_idx;
} AVCState;

#define GF_EXPORT
#define GF_TRUE 1
#define GF_AVC_NALU_ACCESS_UNIT 1
#define GF_AVC_NALU_END_OF_SEQ 2
#define GF_AVC_NALU_END_OF_STREAM 3
#define GF_AVC_NALU_SVC_SLICE 4
#define GF_AVC_NALU_SVC_PREFIX_NALU 5
#define GF_AVC_NALU_IDR_SLICE 6
#define GF_AVC_NALU_NON_IDR_SLICE 7
#define GF_AVC_NALU_DP_A_SLICE 8
#define GF_AVC_NALU_DP_B_SLICE 9
#define GF_AVC_NALU_DP_C_SLICE 10
#define GF_AVC_NALU_SEQ_PARAM 11
#define GF_AVC_NALU_PIC_PARAM 12
#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 13
#define GF_AVC_NALU_SEQ_PARAM_EXT 14
#define GF_AVC_NALU_SEI 15
#define GF_AVC_NALU_FILLER_DATA 16

void gf_bs_enable_emulation_byte_removal(GF_BitStream *bs, int flag);
u8 gf_bs_read_u8(GF_BitStream *bs);
void SVC_ReadNal_header_extension(GF_BitStream *bs, void *nalHeader);
int svc_parse_slice(GF_BitStream *bs, AVCState *avc, AVCSliceInfo *n_state);
void avc_compute_poc(AVCSliceInfo *n_state);
int avc_parse_slice(GF_BitStream *bs, AVCState *avc, u8 idr_flag, AVCSliceInfo *n_state);
int gf_avc_read_sps_bs_internal(GF_BitStream *bs, AVCState *avc, int flag, void *ptr, u32 nal_hdr);
int gf_avc_read_pps_bs_internal(GF_BitStream *bs, AVCState *avc, u32 nal_hdr);
s32 gf_bs_read_ue(GF_BitStream *bs);