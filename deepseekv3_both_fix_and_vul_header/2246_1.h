#include <string.h>
#include <stdint.h>

typedef int16_t WORD16;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int32_t WORD32;

typedef enum {
    IVD_ERROR_NONE,
    IMPEG2D_BITSTREAM_BUFF_EXCEEDED_ERR,
    IMPEG2D_MB_TEX_DECODE_ERR
} IMPEG2D_ERROR_CODES_T;

typedef enum {
    BIDIRECT
} MB_PRED_MODE;

typedef struct {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
} bit_stream_t;

typedef struct {
    uint8_t *pu1_y;
    uint8_t *pu1_u;
    uint8_t *pu1_v;
} yuv_buf_t;

typedef struct {
    uint8_t *pu1_y;
    uint8_t *pu1_u;
    uint8_t *pu1_v;
} dest_buf_t;

typedef struct {
    void (*pf_mc)(void*);
} dec_mb_params_t;

typedef struct {
    yuv_buf_t s_cur_frm_buf;
    int16_t ai2_vld_buf[64];
    int16_t ai2_pred_mv[2];
    int16_t ai2_idct_stg1[64];
    uint16_t u2_prev_intra_mb;
    uint16_t u2_first_mb;
    uint16_t u2_picture_width;
    uint16_t u2_frame_width;
    uint16_t u2_picture_structure;
    uint16_t u2_mb_x;
    uint16_t u2_mb_y;
    uint16_t u2_num_mbs_left;
    uint16_t u2_num_horiz_mb;
    uint16_t u2_field_dct;
    uint16_t u2_cbp;
    uint16_t u2_motion_type;
    uint32_t u4_non_zero_cols;
    uint32_t u4_non_zero_rows;
    int32_t i4_last_value_one;
    bit_stream_t s_bit_stream;
    dest_buf_t s_dest_buf;
    uint8_t *pu1_inv_scan_matrix;
    IMPEG2D_ERROR_CODES_T (*pf_vld_inv_quant)(void*, int16_t*, uint8_t*, uint16_t, int, int);
    void (*pf_idct_recon[4])(int16_t*, int16_t*, uint8_t*, uint8_t*, int, int, int, int, int);
    dec_mb_params_t ps_func_bi_direct[4];
    dec_mb_params_t ps_func_forw_or_back[4];
    int e_pic_type;
    MB_PRED_MODE e_mb_pred;
} dec_state_t;

#define FRAME_PICTURE 0
#define BOTTOM_FIELD 1
#define B_PIC 1
#define NUM_LUMA_BLKS 6
#define BLOCKS_IN_MB 6
#define Y_LUMA 0
#define U_CHROMA 1
#define V_CHROMA 2

extern const int16_t gai2_impeg2_blk_x_off[];
extern const int16_t gai2_impeg2_blk_y_off_frm[];
extern const int16_t gai2_impeg2_blk_y_off_fld[];
extern uint8_t gau1_impeg2_zerobuf[64];

#define IMPEG2D_TRACE_MB_START(x, y)
#define IMPEG2D_IDCT_INP_STATISTICS(a, b, c)
#define PROFILE_DISABLE_MC_IF0
#define PROFILE_DISABLE_IDCT_IF0

IMPEG2D_ERROR_CODES_T impeg2d_dec_pnb_mb_params(dec_state_t *ps_dec);
IMPEG2D_ERROR_CODES_T impeg2d_dec_p_mb_params(dec_state_t *ps_dec);
uint32_t impeg2d_bit_stream_nxt(bit_stream_t *ps_bitstrm, uint32_t u4_num_bits);