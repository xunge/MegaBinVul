#include <stdint.h>

typedef enum {
    IMPEG2D_BITSTREAM_BUFF_EXCEEDED_ERR,
    IVD_ERROR_NONE
} IMPEG2D_ERROR_CODES_T;

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int16_t WORD16;

typedef struct {
    UWORD8 *pu1_y;
    UWORD8 *pu1_u;
    UWORD8 *pu1_v;
} yuv_buf_t;

typedef struct {
    UWORD32 u4_offset;
    UWORD32 u4_max_offset;
} stream_t;

typedef struct {
    yuv_buf_t s_cur_frm_buf;
    stream_t s_bit_stream;
    UWORD16 u2_frame_width;
    UWORD16 u2_picture_structure;
    UWORD16 u2_mb_x;
    UWORD16 u2_mb_y;
    UWORD16 u2_num_mbs_left;
    UWORD16 u2_num_horiz_mb;
    WORD16 u2_def_dc_pred[3];
    void (*pf_memset_8bit_8x8_block)(UWORD8 *, WORD16, UWORD32);
} dec_state_t;

#define FRAME_PICTURE 0
#define BOTTOM_FIELD 1
#define MB_STUFFING_CODE_LEN 8
#define MB_STUFFING_CODE 0x00
#define NUM_LUMA_BLKS 4
#define Y_LUMA 0
#define U_CHROMA 1
#define V_CHROMA 2

extern const UWORD32 gai2_impeg2_blk_x_off[NUM_LUMA_BLKS];
extern const UWORD32 gai2_impeg2_blk_y_off_frm[NUM_LUMA_BLKS];

UWORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, UWORD32 u4_num_bits);
void impeg2d_bit_stream_flush(stream_t *ps_stream, UWORD32 u4_num_bits);
UWORD32 impeg2d_bit_stream_get(stream_t *ps_stream, UWORD32 u4_num_bits);
WORD16 impeg2d_get_luma_dc_diff(stream_t *ps_stream);
WORD16 impeg2d_get_chroma_dc_diff(stream_t *ps_stream);
#define CLIP_U8(x) ((x) < 0 ? 0 : ((x) > 255 ? 255 : (x)))