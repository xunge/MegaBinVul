#include <stdint.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef int32_t WORD32;

enum {
    Y_LUMA = 0,
    U_CHROMA = 1,
    V_CHROMA = 2
};

typedef enum {
    FORW,
    BACK,
    BIDIRECT
} e_pred_direction_t;

typedef struct stream_t {
    uint8_t *pu1_buf;
    uint32_t u4_offset;
} stream_t;

typedef struct {
    uint16_t s_mb_type;
    WORD32 (*pf_func_mb_params)(struct dec_state_t*);
} dec_mb_params_t;

typedef struct dec_state_t {
    uint16_t u2_mb_x;
    uint16_t u2_first_mb;
    uint16_t u2_num_horiz_mb;
    uint16_t u2_is_mpeg2;
    uint16_t u2_motion_type;
    uint16_t u2_read_motion_type;
    uint16_t u2_read_dct_type;
    uint16_t u2_q_scale_type;
    uint8_t u1_quant_scale;
    uint16_t u2_coded_mb;
    uint16_t u2_prev_intra_mb;
    uint16_t u2_cbp;
    uint16_t u2_intra_dc_precision;
    uint16_t u2_def_dc_pred[3];
    uint16_t u2_field_dct;
    uint16_t *pu2_mb_type;
    e_pred_direction_t e_mb_pred;
    uint16_t s_mb_type;
    dec_mb_params_t *ps_func_bi_direct;
    dec_mb_params_t *ps_func_forw_or_back;
    stream_t s_bit_stream;
} dec_state_t;

#define MB_FORW_OR_BACK 0x1
#define MB_BIDRECT 0x2
#define MB_CODED 0x4
#define MB_QUANT 0x8
#define MB_TYPE_INTRA 0x10
#define MB_MV_FORW 0x20

#define MB_MOTION_TYPE_LEN 2
#define MB_DCT_TYPE_LEN 1
#define MB_QUANT_SCALE_CODE_LEN 5
#define MB_CBP_LEN 6

#define BITS(val, start, end) (((val) >> (15 - (end))) & ((1 << ((end) - (start) + 1)) - 1))
#define BIT(val, pos) (((val) >> (15 - (pos))) & 0x1)
#define LSW(val) ((val) & 0xFFFF)

extern uint8_t gau1_impeg2_non_linear_quant_scale[];
extern uint16_t gau2_impeg2d_cbp_code[];

WORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, uint16_t u2_num_bits);
void impeg2d_bit_stream_flush(stream_t *ps_stream, uint16_t u2_num_bits);
UWORD16 impeg2d_get_mb_addr_incr(stream_t *ps_stream);
void impeg2d_dec_skip_mbs(dec_state_t *ps_dec, UWORD16 u2_num_mbs);
void impeg2d_dec_intra_mb(dec_state_t *ps_dec);
void impeg2d_dec_0mv_coded_mb(dec_state_t *ps_dec);