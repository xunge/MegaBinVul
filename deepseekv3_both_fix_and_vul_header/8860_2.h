#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define UWORD8 uint8_t
#define WORD8 int8_t
#define IV_SUCCESS 0
#define IV_FAIL 1
#define IVD_RES_CHANGED 2
#define IVD_MEM_ALLOC_FAILED 3
#define IVD_FATALERROR 4
#define IVD_UNSUPPORTEDPARAM 5
#define IHEVCD_INIT_NOT_DONE 6
#define IHEVCD_NUM_FRAMES_LIMIT_REACHED 7
#define IVD_DEC_FRM_BS_BUF_NULL 8
#define IVD_DEC_NUMBYTES_INV 9
#define IVD_DISP_FRM_ZERO_OP_BUFS 10
#define IVD_DISP_FRM_OP_BUF_NULL 11
#define IVD_DISP_FRM_ZERO_OP_BUF_SIZE 12
#define IVD_DEC_REF_BUF_NULL 13
#define IHEVCD_IGNORE_SLICE 14
#define IHEVCD_UNSUPPORTED_DIMENSIONS 15
#define IHEVCD_SLICE_IN_HEADER_MODE 16
#define IHEVCD_SUCCESS 17
#define NUM_FRAMES_LIMIT 100
#define MIN_START_CODE_LEN 4
#define MAX_SLICE_HDR_CNT 32
#define LOGO_WD 32
#define LOGO_HT 32
#define APPLY_CONCEALMENT 1
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define BUF_MGR_REF 1
#define BUF_MGR_DISP 2
#define IV_YUV_420P 1
#define CMD_PROCESS 1
#define CMD_FMTCONV 2

typedef struct {
    uint32_t u4_size;
    uint32_t u4_error_code;
    uint32_t u4_output_present;
    uint32_t u4_pic_wd;
    uint32_t u4_pic_ht;
    uint32_t u4_new_seq;
    uint32_t u4_num_bytes_consumed;
} ivd_video_decode_op_t;

typedef struct {
    void *pv_stream_buffer;
    uint32_t u4_num_Bytes;
    uint32_t u4_ts;
    struct {
        uint32_t u4_num_bufs;
        uint8_t **pu1_bufs;
        uint32_t *u4_min_out_buf_size;
    } s_out_buffer;
} ivd_video_decode_ip_t;

typedef struct {
    void *pv_codec_handle;
} iv_obj_t;

typedef struct {
    int32_t i4_error_code;
    int32_t i4_init_done;
    uint32_t u4_pic_cnt;
    int32_t i4_reset_flag;
    int32_t i4_flush_mode;
    int32_t i4_wd;
    int32_t i4_ht;
    uint8_t *pu1_inp_bitsbuf;
    int32_t i4_bytes_remaining;
    int32_t i4_share_disp_buf;
    int32_t i4_header_mode;
    int32_t i4_disp_wd;
    int32_t i4_disp_ht;
    int32_t i4_disp_strd;
    int32_t e_chroma_fmt;
    void *pv_disp_buf_mgr;
    void *pv_pic_buf_mgr;
    void *pv_mv_buf_mgr;
    void *pv_dpb_mgr;
    int32_t i4_num_cores;
    int32_t i4_pic_present;
    int32_t i4_slice_error;
    int32_t i4_first_pic_done;
    uint32_t u4_allocate_dynamic_done;
    int32_t i4_sps_done;
    uint8_t *pu1_bitsbuf_dynamic;
    uint32_t u4_bitsbuf_size_dynamic;
    uint8_t *pu1_bitsbuf_static;
    uint32_t u4_bitsbuf_size_static;
    uint8_t *pu1_bitsbuf;
    uint32_t u4_bitsbuf_size;
    int32_t i4_nal_ofst;
    int32_t i4_num_emln_bytes;
    int32_t i4_nal_len;
    int32_t i4_disp_buf_id;
    uint32_t u4_enable_fmt_conv_ahead;
    uint32_t u4_ts;
    uint8_t *mb_map;
    int32_t mb_count;
    struct {
        int32_t i4_end_of_frame;
        int32_t i4_cur_slice_idx;
        int32_t i4_next_ctb_indx;
        void *pv_proc_jobq;
        struct {
            int32_t i2_pic_wd_in_ctb;
            int32_t i2_pic_ht_in_ctb;
            int32_t i4_pic_size_in_ctb;
            int32_t i1_log2_ctb_size;
        } *ps_sps;
        struct {
            int32_t i2_ctb_x;
            int32_t i2_ctb_y;
        } *ps_slice_hdr_base;
        struct {
            uint8_t *pu1_buf;
            uint32_t u4_size;
        } s_bitstrm;
    } s_parse;
    struct {
        int32_t i4_num_rows;
        int32_t i4_cur_row;
    } s_fmt_conv;
    struct {
        int32_t i4_ctb_cnt;
        int32_t i4_ctb_x;
        int32_t i4_ctb_y;
        int32_t i4_cur_slice_idx;
        int32_t i4_cur_pic_buf_id;
        int32_t i4_cur_mv_bank_buf_id;
        int32_t i4_init_done;
        void *pv_proc_jobq;
        void *ps_cur_pic;
    } as_process[2];
    int32_t i4_header_in_slice_mode;
    void *ps_out_buffer;
    void *ps_disp_buf;
    int32_t ai4_process_thread_created[2];
    void *apv_process_thread_handle[2];
} codec_t;

typedef struct {
    int32_t i4_cmd;
    int32_t i2_ctb_cnt;
    int32_t i2_ctb_x;
    int32_t i2_ctb_y;
    int32_t i2_slice_idx;
    int32_t i4_tu_coeff_data_ofst;
} proc_job_t;

typedef struct {
    int32_t i2_ctb_x;
    int32_t i2_ctb_y;
} slice_header_t;

typedef struct {
    int32_t i2_pic_wd_in_ctb;
    int32_t i2_pic_ht_in_ctb;
    int32_t i4_pic_size_in_ctb;
    int32_t i1_log2_ctb_size;
} sps_t;

typedef struct {
    void *pv_proc_jobq;
} jobq_t;

typedef struct {
    void *pv_proc_jobq;
} disp_mgr_t;

typedef struct {
    void *pv_pic_buf_mgr;
} buf_mgr_t;

typedef struct {
    void *pv_dpb_mgr;
} dpb_mgr_t;

typedef struct {
    int32_t i4_disp_buf_id;
} pic_buf_t;

typedef struct {
    uint8_t *pu1_bufs[3];
    int32_t i4_init_done;
    int32_t i4_ctb_cnt;
    int32_t i4_ctb_x;
    int32_t i4_ctb_y;
    int32_t i4_cur_slice_idx;
    int32_t i4_cur_pic_buf_id;
    int32_t i4_cur_mv_bank_buf_id;
    void *pv_proc_jobq;
    void *ps_cur_pic;
} process_ctxt_t;

typedef int32_t IHEVCD_ERROR_T;

#define INSERT_LOGO(y, u, v, stride, xpos, ypos, fmt, wd, ht) 
#define BREAK_AFTER_SLICE_NAL() 
#define DEBUG_DUMP_MV_MAP(ps_codec) 
#define DEBUG_VALIDATE_PADDED_REGION(ps_proc) 
#define DEBUG_DUMP_PIC_PU(ps_codec) 
#define DEBUG_DUMP_PIC_BUFFERS(ps_codec) 

pic_buf_t* ihevc_disp_mgr_get(disp_mgr_t *ps_disp_mgr, int32_t *pi4_disp_buf_id);
void ihevcd_init_proc_ctxt(process_ctxt_t *ps_proc, int32_t i4_init);
int32_t ihevcd_fmt_conv(codec_t *ps_codec, process_ctxt_t *ps_proc, 
                        uint8_t *pu1_y, uint8_t *pu1_u, uint8_t *pu1_v,
                        int32_t i4_start_row, int32_t i4_num_rows);
void ihevc_buf_mgr_release(buf_mgr_t *ps_buf_mgr, int32_t i4_buf_id, int32_t i4_status);
void ihevcd_fill_outargs(codec_t *ps_codec, ivd_video_decode_ip_t *ps_dec_ip, 
                         ivd_video_decode_op_t *ps_dec_op);
void ihevcd_init(codec_t *ps_codec);
int32_t ihevc_buf_mgr_check_free(buf_mgr_t *ps_buf_mgr);
void ithread_set_affinity(int32_t i4_core);
int32_t ihevcd_nal_search_start_code(uint8_t *pu1_buf, int32_t i4_size);
void ihevcd_nal_remv_emuln_bytes(uint8_t *pu1_src, uint8_t *pu1_dst, 
                                 int32_t i4_src_size, int32_t *pi4_nal_len, 
                                 int32_t *pi4_bits_len);
void ihevcd_bits_init(void *ps_bitstrm, uint8_t *pu1_buf, int32_t i4_size);
int32_t ihevcd_nal_unit(codec_t *ps_codec);
int32_t ihevcd_allocate_dynamic_bufs(codec_t *ps_codec);
void ihevcd_free_dynamic_bufs(codec_t *ps_codec);
int32_t ihevcd_jobq_queue(jobq_t *ps_jobq, proc_job_t *ps_job, int32_t i4_size, int32_t i4_block);
int32_t ihevcd_jobq_terminate(jobq_t *ps_jobq);
int32_t ihevcd_jobq_dequeue(jobq_t *ps_jobq, proc_job_t *ps_job, int32_t i4_size, int32_t i4_block);
void ihevcd_process(process_ctxt_t *ps_proc);
void ihevc_buf_mgr_set_status(buf_mgr_t *ps_buf_mgr, int32_t i4_buf_id, int32_t i4_status);
void ihevc_dpb_mgr_insert_ref(dpb_mgr_t *ps_dpb_mgr, void *ps_pic, int32_t i4_buf_id);
void ithread_join(void *pv_handle, void **ppv_ret);