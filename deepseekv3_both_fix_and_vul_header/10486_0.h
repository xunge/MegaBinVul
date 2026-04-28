#include <string.h>

typedef int WORD32;
typedef unsigned char UWORD8;
typedef short WORD16;
typedef unsigned short UWORD16;
typedef unsigned int UWORD32;

typedef enum {
    IV_SUCCESS,
    IV_FAIL,
    IVD_ERROR_NONE,
    IVD_DEC_FRM_BS_BUF_NULL,
    IVD_DEC_REF_BUF_NULL,
    IVD_UNSUPPORTEDPARAM
} IV_API_CALL_STATUS_T;

typedef enum {
    IV_I_FRAME,
    IV_P_FRAME,
    IV_B_FRAME,
    IV_NA_FRAME,
    IV_FRAMETYPE_DEFAULT,
    IV_PROGRESSIVE
} IV_PIC_TYPE_T;

typedef enum {
    IV_YUV_420P,
    IV_YUV_420SP_UV,
    IV_YUV_420SP_VU,
    IV_YUV_422ILE
} IV_COLOR_FORMAT_T;

typedef enum {
    I_PIC,
    P_PIC,
    B_PIC,
    D_PIC
} PIC_TYPE_T;

typedef enum {
    BUF_MGR_REF,
    BUF_MGR_DISP,
    MPEG2_BUF_MGR_DEINT
} BUF_MGR_TYPE_T;

typedef struct {
    UWORD32 u4_size;
    UWORD32 u4_output_present;
    UWORD32 u4_num_bytes_consumed;
    UWORD32 u4_error_code;
    UWORD32 u4_pic_ht;
    UWORD32 u4_pic_wd;
    UWORD32 u4_disp_buf_id;
    UWORD32 u4_ts;
    UWORD32 u4_is_ref_flag;
    UWORD32 u4_progressive_frame_flag;
    IV_PIC_TYPE_T e_pic_type;
    IV_COLOR_FORMAT_T e_output_format;
    struct {
        void *pv_y_buf;
        void *pv_u_buf;
        void *pv_v_buf;
        UWORD32 u4_y_wd;
        UWORD32 u4_y_strd;
        UWORD32 u4_y_ht;
        UWORD32 u4_u_wd;
        UWORD32 u4_u_strd;
        UWORD32 u4_u_ht;
        UWORD32 u4_v_wd;
        UWORD32 u4_v_strd;
        UWORD32 u4_v_ht;
        UWORD32 u4_size;
    } s_disp_frm_buf;
    WORD32 e4_fld_type;
} ivd_video_decode_op_t;

typedef struct {
    UWORD32 u4_size;
    UWORD32 u4_num_Bytes;
    void *pv_stream_buffer;
    struct {
        UWORD8 *pu1_bufs[3];
    } s_out_buffer;
} ivd_video_decode_ip_t;

typedef struct {
    ivd_video_decode_ip_t s_ivd_video_decode_ip_t;
} impeg2d_video_decode_ip_t;

typedef struct {
    ivd_video_decode_op_t s_ivd_video_decode_op_t;
} impeg2d_video_decode_op_t;

typedef struct {
    void *pv_codec_handle;
} iv_obj_t;

typedef struct {
    UWORD8 u1_flushfrm;
    UWORD8 u1_flushcnt;
    UWORD8 u1_first_frame_done;
    UWORD16 u2_header_done;
    UWORD16 u2_decode_header;
    UWORD16 u2_vertical_size;
    UWORD16 u2_horizontal_size;
    UWORD16 u2_progressive_frame;
    UWORD32 u4_frm_buf_stride;
    UWORD32 u4_share_disp_buf;
    UWORD32 u4_deinterlace;
    UWORD32 u4_num_frames_decoded;
    WORD32 i4_chromaFormat;
    WORD32 i4_frame_decoded;
    WORD32 i4_disp_buf_id;
    PIC_TYPE_T e_pic_type;
    struct {
        WORD32 e4_fld_type;
    } s_disp_op;
    struct {
        UWORD8 *pu1_bufs[3];
    } as_disp_buffers[1];
    void *pv_pic_buf_mg;
    struct {
        void *pv_y_buf;
        void *pv_u_buf;
        void *pv_v_buf;
    } *ps_disp_frm_buf;
    struct pic_buf_t *ps_disp_pic;
    struct pic_buf_t *ps_deint_pic;
    struct pic_buf_t *aps_ref_pics[2];
    struct {
        void *pv_handle;
    } s_disp_mgr;
} dec_state_t;

typedef struct {
    dec_state_t *ps_dec_state[1];
} dec_state_multi_core_t;

typedef struct pic_buf_t {
    UWORD8 *pu1_y;
    UWORD8 *pu1_u;
    UWORD8 *pu1_v;
    WORD32 i4_buf_id;
    UWORD32 u4_ts;
    PIC_TYPE_T e_pic_type;
} pic_buf_t;

typedef struct {
    void *pv_y_buf;
    void *pv_u_buf;
    void *pv_v_buf;
} iv_yuv_buf_t;

#define NUM_FRAMES_LIMIT 100
#define IMPEG2D_SAMPLE_VERSION_LIMIT_ERR 0x8000
#define IMPEG2D_ERROR_CODES_T int
#define INSERT_LOGO(y, u, v, stride, width, height, format, disp_width, disp_height)