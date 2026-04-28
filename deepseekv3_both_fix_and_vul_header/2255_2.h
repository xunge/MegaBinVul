#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define UWORD8 uint8_t
#define WORD16 int16_t
#define UWORD16 uint16_t
#define IHEVCD_ERROR_T int32_t
#define IVD_RES_CHANGED 1
#define IVD_STREAM_WIDTH_HEIGHT_NOT_SUPPORTED 2
#define IV_SUCCESS 0
#define IV_FAIL 1
#define IHEVCD_SUCCESS 0
#define IHEVCD_SLICE_IN_HEADER_MODE 1
#define IHEVCD_IGNORE_SLICE 2
#define NUM_FRAMES_LIMIT 100
#define MIN_START_CODE_LEN 4
#define MAX_SLICE_HDR_CNT 32
#define LOGO_WD 32
#define LOGO_HT 32
#define IVD_FATALERROR 0
#define IVD_UNSUPPORTEDPARAM 1
#define IHEVCD_INIT_NOT_DONE 1
#define IHEVCD_NUM_FRAMES_LIMIT_REACHED 2
#define IVD_DEC_FRM_BS_BUF_NULL 3
#define IVD_DEC_NUMBYTES_INV 4
#define IVD_DISP_FRM_ZERO_OP_BUFS 5
#define IVD_DISP_FRM_OP_BUF_NULL 6
#define IVD_DISP_FRM_ZERO_OP_BUF_SIZE 7
#define IVD_DEC_REF_BUF_NULL 8
#define IVD_MEM_ALLOC_FAILED 9
#define BUF_MGR_REF 0
#define BUF_MGR_DISP 1
#define CMD_PROCESS 0
#define CMD_FMTCONV 1
#define IV_YUV_420P 0

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define RETURN_IF(cond, ret) if (cond) return ret
#define BREAK_AFTER_SLICE_NAL()
#define INSERT_LOGO(y, u, v, stride, xpos, ypos, chroma_fmt, width, height)
#define DEBUG_DUMP_MV_MAP(codec)
#define DEBUG_DUMP_PIC_PU(codec)
#define DEBUG_DUMP_PIC_BUFFERS(codec)
#define DEBUG_VALIDATE_PADDED_REGION(proc)

typedef struct {
    uint8_t *pu1_bitsbuf;
    uint32_t u4_bitsbuf_size;
} bitstrm_t;

typedef struct {
    int32_t i4_error_code;
    int32_t i4_init_done;
    uint32_t u4_pic_cnt;
    int32_t i4_reset_flag;
    int32_t i4_flush_mode;
    int32_t i4_share_disp_buf;
    int32_t i4_header_mode;
    int32_t i4_wd;
    int32_t i4_ht;
    uint8_t *mb_map;
    int32_t mb_count;
    int32_t i4_disp_wd;
    int32_t i4_disp_ht;
    int32_t i4_disp_strd;
    int32_t e_chroma_fmt;
    void *pv_disp_buf_mgr;
    void *pv_pic_buf_mgr;
    void *pv_mv_buf_mgr;
    void *pv_dpb_mgr;
    int32_t i4_num_cores;
    int32_t ai4_process_thread_created[4];
    pthread_t apv_process_thread_handle[4];
    uint32_t u4_ts;
    int32_t i4_bytes_remaining;
    uint8_t *pu1_inp_bitsbuf;
    int32_t i4_nal_ofst;
    int32_t i4_nal_len;
    int32_t i4_num_emln_bytes;
    uint8_t *pu1_bitsbuf;
    uint32_t u4_bitsbuf_size;
    uint8_t *pu1_bitsbuf_dynamic;
    uint32_t u4_bitsbuf_size_dynamic;
    uint8_t *pu1_bitsbuf_static;
    uint32_t u4_bitsbuf_size_static;
    int32_t i4_pic_present;
    int32_t i4_slice_error;
    int32_t i4_first_pic_done;
    int32_t u4_allocate_dynamic_done;
    int32_t i4_sps_done;
    int32_t i4_disp_buf_id;
    int32_t u4_enable_fmt_conv_ahead;
    int32_t i4_header_in_slice_mode;
    void *ps_out_buffer;
    void *ps_disp_buf;
    struct {
        int32_t i4_end_of_frame;
        int32_t i4_cur_slice_idx;
        int32_t i4_next_ctb_indx;
        void *ps_slice_hdr_base;
        struct sps_t *ps_sps;
        void *pv_proc_jobq;
        bitstrm_t s_bitstrm;
    } s_parse;
    struct {
        int32_t i4_cur_row;
        int32_t i4_num_rows;
    } s_fmt_conv;
    struct {
        int32_t i4_init_done;
        int32_t i4_cur_pic_buf_id;
        int32_t i4_cur_mv_bank_buf_id;
        void *ps_cur_pic;
        int32_t i4_ctb_cnt;
        int32_t i4_ctb_x;
        int32_t i4_ctb_y;
        int32_t i4_cur_slice_idx;
        void *pv_proc_jobq;
    } as_process[4];
    void *pv_codec_handle;
} codec_t;

typedef struct {
    void *pv_codec_handle;
} iv_obj_t;

typedef struct {
    uint32_t u4_size;
    uint32_t u4_error_code;
    uint32_t u4_pic_wd;
    uint32_t u4_pic_ht;
    uint32_t u4_new_seq;
    uint32_t u4_num_bytes_consumed;
    uint32_t u4_output_present;
} ivd_video_decode_op_t;

typedef struct {
    void *pv_stream_buffer;
    uint32_t u4_num_Bytes;
    uint32_t u4_ts;
    struct {
        uint32_t u4_num_bufs;
        uint8_t *pu1_bufs[3];
        uint32_t u4_min_out_buf_size[3];
    } s_out_buffer;
} ivd_video_decode_ip_t;

typedef struct {
    int32_t i2_ctb_x;
    int32_t i2_ctb_y;
} slice_header_t;

typedef struct sps_t {
    int32_t i1_log2_ctb_size;
    int32_t i2_pic_wd_in_ctb;
    int32_t i2_pic_ht_in_ctb;
    int32_t i4_pic_size_in_ctb;
} sps_t;

typedef struct {
    int32_t i4_cmd;
    int32_t i2_ctb_cnt;
    int32_t i2_ctb_x;
    int32_t i2_ctb_y;
    int32_t i2_slice_idx;
    int32_t i4_tu_coeff_data_ofst;
} proc_job_t;

typedef struct {
    void *pv_proc_jobq;
} jobq_t;

typedef struct {
    void *pv_pic_buf_mgr;
} buf_mgr_t;

typedef struct {
    void *pv_dpb_mgr;
} dpb_mgr_t;

typedef struct {
    void *pv_disp_buf_mgr;
} disp_mgr_t;

typedef struct {
    int32_t i4_disp_buf_id;
} pic_buf_t;

typedef struct {
    int32_t i4_init_done;
    int32_t i4_cur_pic_buf_id;
    int32_t i4_cur_mv_bank_buf_id;
    void *ps_cur_pic;
    int32_t i4_ctb_cnt;
    int32_t i4_ctb_x;
    int32_t i4_ctb_y;
    int32_t i4_cur_slice_idx;
    void *pv_proc_jobq;
} process_ctxt_t;

/* Function prototypes */
void* ihevc_disp_mgr_get(disp_mgr_t *ps_disp_mgr, int32_t *pi4_buf_id);
void ihevcd_init_proc_ctxt(process_ctxt_t *ps_proc, int32_t i4_coeff_ofst);
int32_t ihevcd_check_out_buf_size(codec_t *ps_codec);
int32_t ihevcd_fmt_conv(codec_t *ps_codec, process_ctxt_t *ps_proc, 
                       uint8_t *pu1_y, uint8_t *pu1_u, uint8_t *pu1_v, 
                       int32_t i4_row, int32_t i4_num_rows);
void ihevc_buf_mgr_release(buf_mgr_t *ps_buf_mgr, int32_t i4_buf_id, int32_t i4_status);
void ihevcd_fill_outargs(codec_t *ps_codec, ivd_video_decode_ip_t *ps_dec_ip, 
                        ivd_video_decode_op_t *ps_dec_op);
void ihevcd_init(codec_t *ps_codec);
int32_t ihevc_buf_mgr_check_free(buf_mgr_t *ps_buf_mgr);
void ithread_set_affinity(int32_t i4_core_id);
int32_t ihevcd_nal_search_start_code(uint8_t *pu1_bitsbuf, int32_t i4_bytes_remaining);
void ihevcd_nal_remv_emuln_bytes(uint8_t *pu1_src, uint8_t *pu1_dest, 
                                int32_t i4_src_len, int32_t *pi4_nal_len, 
                                int32_t *pi4_bits_len);
void ihevcd_bits_init(bitstrm_t *ps_bitstrm, uint8_t *pu1_bitsbuf, int32_t i4_bits_len);
int32_t ihevcd_nal_unit(codec_t *ps_codec);
int32_t ihevcd_allocate_dynamic_bufs(codec_t *ps_codec);
void ihevcd_free_dynamic_bufs(codec_t *ps_codec);
int32_t ihevcd_jobq_queue(jobq_t *ps_jobq, proc_job_t *ps_job, int32_t i4_size, int32_t i4_blocking);
int32_t ihevcd_jobq_terminate(jobq_t *ps_jobq);
int32_t ihevcd_jobq_dequeue(jobq_t *ps_jobq, proc_job_t *ps_job, int32_t i4_size, int32_t i4_blocking);
void ihevcd_process(process_ctxt_t *ps_proc);
void ihevc_buf_mgr_set_status(buf_mgr_t *ps_buf_mgr, int32_t i4_buf_id, int32_t i4_status);
void ihevc_dpb_mgr_insert_ref(dpb_mgr_t *ps_dpb_mgr, void *ps_pic, int32_t i4_buf_id);
int ithread_join(pthread_t thread, void **retval);