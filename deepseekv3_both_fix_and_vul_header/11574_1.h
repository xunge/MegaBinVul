#include <stdint.h>
#include <stddef.h>

#define MAX_SPS_CNT 32
#define USER_DATA_MAX 256

#define SEI_BUFFERING_PERIOD 0
#define SEI_PICTURE_TIMING 1
#define SEI_TIME_CODE 2
#define SEI_MASTERING_DISPLAY_COLOUR_VOLUME 3
#define SEI_USER_DATA_REGISTERED_ITU_T_T35 4

#define NAL_PREFIX_SEI 1

typedef int32_t WORD32;
typedef int8_t WORD8;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;

typedef struct bitstrm_t {
    int dummy;
} bitstrm_t;

typedef struct sps_t {
    WORD8 i1_sps_valid;
} sps_t;

typedef struct sei_params_t {
    WORD8 i1_sei_parameters_present_flag;
    WORD32 i4_sei_mastering_disp_colour_vol_params_present_flags;
    WORD32 i4_sei_user_data_cnt;
} sei_params_t;

typedef struct parse_ctxt_t {
    bitstrm_t s_bitstrm;
    sei_params_t s_sei_params;
} parse_ctxt_t;

typedef struct codec_t {
    parse_ctxt_t s_parse;
    sps_t *ps_sps_base;
} codec_t;

#define UNUSED(x) (void)(x)
#define BITS_PARSE(str, var, bitstrm, bits) (var) = 0