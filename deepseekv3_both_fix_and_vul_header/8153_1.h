#include <stdint.h>
#include <pthread.h>

#define WORD32 int32_t
#define UWORD8 uint8_t
#define UWORD16 uint16_t
#define OK 0
#define ERROR_NEW_FRAME_EXPECTED -1
#define REJECT_CUR_PIC 0x1

typedef struct dec_slice_params_t {
    uint8_t u1_nal_ref_idc;
    uint16_t u2_frame_num;
    uint8_t u1_mmco_equalto5;
} dec_slice_params_t;

typedef struct dec_err_status_t {
    uint8_t u1_err_flag;
} dec_err_status_t;

typedef struct pocstruct_t {
    int32_t i4_prev_frame_num_ofst;
    uint16_t u2_frame_num;
    uint8_t u1_mmco_equalto5;
    int32_t i4_pic_order_cnt_lsb;
    int32_t i4_pic_order_cnt_msb;
    int32_t i4_delta_pic_order_cnt_bottom;
    int32_t i4_delta_pic_order_cnt[2];
    uint8_t u1_bot_field;
} pocstruct_t;

typedef struct dec_sps_t {
    uint8_t u1_gaps_in_frame_num_value_allowed_flag;
} dec_sps_t;

typedef struct dec_struct_t {
    dec_slice_params_t *ps_cur_slice;
    uint8_t u1_first_pb_nal_in_pic;
    uint16_t u2_mbx;
    uint16_t u2_mby;
    dec_err_status_t *ps_dec_err_status;
    pthread_mutex_t process_disp_mutex;
    uint16_t u2_total_mbs_coded;
    uint16_t u2_prev_ref_frame_num;
    dec_sps_t *ps_cur_sps;
    pocstruct_t s_prev_pic_poc;
    pocstruct_t s_cur_pic_poc;
} dec_struct_t;

#define H264_MUTEX_LOCK(x) pthread_mutex_lock(x)
#define H264_MUTEX_UNLOCK(x) pthread_mutex_unlock(x)