#include <stdint.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define WORD16 int16_t
#define UWORD16 uint16_t
#define WORD8 int8_t
#define UWORD8 uint8_t
#define OK 0
#define IDR_SLICE_NAL 5
#define MAX_FRAMES 16
#define INVALID_FRAME_NUM (-1)
#define ERROR_DBP_MANAGER_T (-1)
#define DO_NOT_DISP 0

typedef struct pocstruct_t {
    int32_t i4_pic_order_cnt_lsb;
    int32_t i4_delta_pic_order_cnt_bottom;
    int32_t i4_delta_pic_order_cnt[2];
} pocstruct_t;

typedef struct dec_slice_params_t {
    uint8_t u1_field_pic_flag;
    uint8_t u1_mmco_equalto5;
    uint16_t u2_frame_num;
} dec_slice_params_t;

typedef struct dec_pic_params_t {
    struct {
        uint8_t u1_pic_order_cnt_type;
        uint8_t u1_num_ref_frames;
    } *ps_sps;
} dec_pic_params_t;

typedef struct dpb_manager_t {
    int32_t ai4_gaps_start_frm_num[MAX_FRAMES];
    int32_t ai4_gaps_end_frm_num[MAX_FRAMES];
    int8_t ai1_gaps_per_seq[MAX_FRAMES];
    int32_t i1_poc_buf_id_entries;
} dpb_manager_t;

typedef struct dec_struct_t {
    dec_slice_params_t *ps_cur_slice;
    uint16_t u2_prev_ref_frame_num;
    struct {
        uint32_t u2_u4_max_pic_num_minus1;
        uint8_t u1_num_ref_frames;
    } *ps_cur_sps;
    uint8_t u1_nal_unit_type;
    pocstruct_t s_prev_pic_poc;
    int32_t i4_max_poc;
    int32_t i4_prev_max_display_seq;
    uint8_t u1_max_dec_frame_buffering;
    dpb_manager_t *ps_dpb_mgr;
    dec_pic_params_t *ps_cur_pps;
} dec_struct_t;