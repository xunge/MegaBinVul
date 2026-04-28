#include <stdint.h>

typedef enum {
    IVD_ERROR_NONE,
    IMPEG2D_SCALABILITIY_NOT_SUPPORTED
} IMPEG2D_ERROR_CODES_T;

typedef struct {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
} stream_t;

typedef struct {
    stream_t s_bit_stream;
} dec_state_t;

#define START_CODE_LEN 32
#define EXT_ID_LEN 4
#define EXTENSION_START_CODE 0x000001B5
#define USER_DATA_START_CODE 0x000001B2
#define SEQ_DISPLAY_EXT_ID 1
#define SEQ_SCALABLE_EXT_ID 2

typedef uint32_t UWORD32;

UWORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, int len);
void impeg2d_bit_stream_flush(stream_t *ps_stream, int len);
void impeg2d_dec_user_data(dec_state_t *ps_dec);
void impeg2d_dec_seq_disp_ext(dec_state_t *ps_dec);
void impeg2d_peek_next_start_code(dec_state_t *ps_dec);