#include <stdint.h>

typedef enum {
    IVD_ERROR_NONE,
    IMPEG2D_SCALABLITY_NOT_SUP
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
#define QUANT_MATRIX_EXT_ID 0x1
#define COPYRIGHT_EXT_ID 0x2
#define PIC_DISPLAY_EXT_ID 0x7
#define CAMERA_PARAM_EXT_ID 0x3
#define ITU_T_EXT_ID 0x4
#define PIC_SPATIAL_SCALABLE_EXT_ID 0x5
#define PIC_TEMPORAL_SCALABLE_EXT_ID 0x6

typedef uint32_t UWORD32;

UWORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, int len);
void impeg2d_bit_stream_flush(stream_t *ps_stream, int len);
void impeg2d_dec_user_data(dec_state_t *ps_dec);
void impeg2d_dec_quant_matrix_ext(dec_state_t *ps_dec);
void impeg2d_dec_copyright_ext(dec_state_t *ps_dec);
void impeg2d_dec_pic_disp_ext(dec_state_t *ps_dec);
void impeg2d_dec_cam_param_ext(dec_state_t *ps_dec);
void impeg2d_dec_itu_t_ext(dec_state_t *ps_dec);
void impeg2d_next_start_code(dec_state_t *ps_dec);