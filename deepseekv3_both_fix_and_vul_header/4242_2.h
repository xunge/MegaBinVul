#include <stddef.h>

typedef int WORD32;
typedef unsigned int UWORD32;
typedef short WORD16;
typedef unsigned short UWORD16;

#define START_CODE_LEN 24
#define START_CODE_PREFIX 0x000001
#define IV_SUCCESS 0
#define IV_YUV_420P 0
#define CMD_PROCESS 0
#define CMD_FMTCONV 0

typedef struct {
    UWORD32 u4_offset;
    UWORD32 u4_max_offset;
    void *pv_bs_buf;
} stream_t;

typedef struct {
    WORD32 i2_start_mb_y;
    WORD32 i2_end_mb_y;
    WORD32 i4_cmd;
    WORD32 i4_bistream_ofst;
} job_t;

typedef struct dec_state_t {
    WORD32 i4_num_cores;
    UWORD16 u2_num_vert_mb;
    UWORD16 u2_vertical_size;
    void *pv_jobq;
    stream_t s_bit_stream;
    WORD32 u4_share_disp_buf;
    WORD32 i4_chromaFormat;
    void *ps_disp_pic;
    WORD32 i4_bytes_consumed;
    WORD32 i4_start_mb_y;
    WORD32 i4_end_mb_y;
} dec_state_t;

typedef struct {
    dec_state_t *ps_dec_state[4];
} dec_state_multi_core_t;

typedef void jobq_t;

typedef enum {
    IV_API_CALL_STATUS_T_SUCCESS = 0
} IV_API_CALL_STATUS_T;

IV_API_CALL_STATUS_T impeg2_jobq_queue(void *pv_jobq, job_t *ps_job, WORD32 size, WORD32 blocking, WORD32 timeout);
void impeg2_jobq_reset(jobq_t *pv_jobq);
void impeg2_jobq_terminate(void *pv_jobq);
UWORD32 impeg2d_bit_stream_nxt(stream_t *ps_stream, WORD32 num_bits);
void impeg2d_bit_stream_flush(stream_t *ps_stream, WORD32 num_bits);
WORD32 impeg2d_bit_stream_get(stream_t *ps_stream, WORD32 num_bits);