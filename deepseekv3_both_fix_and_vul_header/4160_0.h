#include <stdint.h>

#define START_CODE_LEN 32
#define PICTURE_START_CODE 0x00000100

typedef enum {
    I_PIC,
    P_PIC,
    B_PIC,
    D_PIC
} e_pic_type_t;

typedef enum {
    IMPEG2D_INVALID_PIC_TYPE,
    IVD_ERROR_NONE
} IMPEG2D_ERROR_CODES_T;

typedef struct {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
} stream_t;

typedef struct {
    stream_t s_bit_stream;
    e_pic_type_t e_pic_type;
    uint16_t u2_full_pel_forw_vector;
    uint16_t u2_forw_f_code;
    uint16_t u2_full_pel_back_vector;
    uint16_t u2_back_f_code;
    uint16_t u2_is_mpeg2;
    uint16_t au2_f_code[2][2];
} dec_state_t;

uint32_t impeg2d_bit_stream_flush(stream_t *ps_stream, uint32_t u4_num_bits);
uint32_t impeg2d_bit_stream_get(stream_t *ps_stream, uint32_t u4_num_bits);
uint32_t impeg2d_bit_stream_get_bit(stream_t *ps_stream);
uint32_t impeg2d_bit_stream_nxt(stream_t *ps_stream, uint32_t u4_num_bits);
void impeg2d_next_code(dec_state_t *ps_dec, uint32_t u4_code);
void impeg2d_next_start_code(dec_state_t *ps_dec);