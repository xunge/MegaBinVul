#include <stdint.h>
#include <stddef.h>

#define START_CODE_LEN 24
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int16_t WORD16;

typedef enum {
    IV_SUCCESS,
    IV_FAIL
} IV_API_CALL_STATUS_T;

typedef enum {
    CMD_PROCESS,
    CMD_FMTCONV
} IMPEG2D_CMD_T;

typedef enum {
    IV_YUV_420P
} IMPEG2D_CHROMA_FORMAT_T;

typedef enum {
    IVD_ERROR_NONE,
    IVD_RES_CHANGED,
    IVD_MEM_ALLOC_FAILED,
    IVD_DISP_FRM_ZERO_OP_BUF_SIZE
} IMPEG2D_ERROR_CODES_T;

typedef struct {
    WORD32 i4_cmd;
    WORD16 i2_start_mb_y;
    WORD16 i2_end_mb_y;
    WORD32 i4_bistream_ofst;
} job_t;

typedef struct {
    UWORD8 *pu1_buf;
    UWORD32 u4_buf_len;
} bit_stream_t;

typedef struct {
    void *pv_jobq;
    UWORD8 *pu1_inp_bits_buf;
    UWORD32 u4_num_inp_bytes;
    WORD32 i4_num_cores;
    UWORD16 u2_mb_x;
    UWORD16 u2_mb_y;
    UWORD16 u2_num_horiz_mb;
    UWORD16 u2_num_vert_mb;
    UWORD16 u2_vertical_size;
    WORD32 i4_start_mb_y;
    WORD32 i4_end_mb_y;
    UWORD16 u2_num_mbs_left;
    UWORD32 u4_share_disp_buf;
    IMPEG2D_CHROMA_FORMAT_T i4_chromaFormat;
    void *ps_disp_pic;
    void *ps_disp_frm_buf;
    bit_stream_t s_bit_stream;
} dec_state_t;