#include <stdint.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define OK 0

typedef struct dec_struct_t dec_struct_t;
typedef struct dec_bit_stream_t {
    uint32_t u4_ofst;
    uint32_t u4_max_ofst;
} dec_bit_stream_t;

#define H264_DEC_DEBUG_PRINT(msg)

UWORD32 ih264d_get_bits_h264(dec_bit_stream_t *ps_bitstrm, UWORD32 num_bits);
UWORD32 ih264d_get_bit_h264(dec_bit_stream_t *ps_bitstrm);
WORD32 ih264d_parse_sei_payload(dec_bit_stream_t *ps_bitstrm, UWORD32 ui4_payload_type, UWORD32 ui4_payload_size, dec_struct_t *ps_dec);
WORD32 ih264d_check_byte_aligned(dec_bit_stream_t *ps_bitstrm);