#include <stdint.h>
#include <stddef.h>

typedef uint32_t WORD32;
typedef uint16_t UWORD16;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;

typedef enum {
    Y_LUMA,
    U_CHROMA, 
    V_CHROMA
} chroma_component_t;

typedef enum {
    FORW,
    BACK
} e_pred_direction_t;

typedef struct stream_t {
    // stream implementation details
} stream_t;

typedef struct dec_mb_params_t {
    void (*pf_func_mb_params)(void*);
    int s_mb_type;
} dec_mb_params_t;

typedef struct dec_state_t {
    stream_t s_bit_stream;
    UWORD16 u2_first_mb;
    UWORD16 u2_is_mpeg2;
    UWORD16 u2_mb_x;
    UWORD16 u2_num_horiz_mb;
    UWORD16* pu2_mb_type;
    UWORD16 u2_read_motion_type;
    UWORD16 u2_motion_type;
    UWORD16 u2_read_dct_type;
    UWORD16 u2_field_dct;
    UWORD8 u1_quant_scale;
    UWORD16 u2_q_scale_type;
    UWORD16 u2_coded_mb;
    UWORD16 u2_prev_intra_mb;
    e_pred_direction_t e_mb_pred;
    dec_mb_params_t* ps_func_forw_or_back;
    int s_mb_type;
    UWORD16 u2_cbp;
    UWORD16 u2_intra_dc_precision;
    UWORD16 u2_def_dc_pred[3];
} dec_state_t;

#define BITS(val, hi, lo) (((val) >> (15 - (hi))) & ((1 << ((hi) - (lo) + 1)) - 1))
#define BIT(val, pos) (((val) >> (15 - (pos))) & 0x1)
#define LSW(val) ((val) & 0xFFFF)

#define MB_FORW_OR_BACK 0x1
#define MB_MV_FORW 0x2
#define MB_CODED 0x4
#define MB_QUANT 0x8
#define MB_TYPE_INTRA 0x10

#define MB_MOTION_TYPE_LEN 2
#define MB_DCT_TYPE_LEN 1
#define MB_QUANT_SCALE_CODE_LEN 5
#define MB_CBP_LEN 6

extern const UWORD16 gau2_impeg2d_cbp_code[];
extern const UWORD8 gau1_impeg2_non_linear_quant_scale[];

UWORD16 impeg2d_bit_stream_nxt(stream_t *ps_stream, UWORD16 u2_num_bits);
void impeg2d_bit_stream_flush(stream_t *ps_stream, UWORD16 u2_num_bits);
UWORD16 impeg2d_get_mb_addr_incr(stream_t *ps_stream);
void impeg2d_dec_skip_mbs(dec_state_t *ps_dec, UWORD16 u2_num_mbs);
void impeg2d_dec_intra_mb(dec_state_t *ps_dec);
void impeg2d_dec_0mv_coded_mb(dec_state_t *ps_dec);