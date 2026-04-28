#include <stdint.h>
#include <stddef.h>

#define MAX_DPB_SIZE 16
#define MAX_DPB_BUFS 16
#define BUF_MGR_MAX_CNT 16
#define UNUSED_FOR_REF 0
#define SHORT_TERM_REF 1
#define LONG_TERM_REF 2
#define PSLICE 0
#define BSLICE 1
#define IHEVCD_SUCCESS 0
#define IHEVCD_REF_PIC_NOT_FOUND 1

#define RETURN_IF_NAL_INFO
#define DEBUG_PRINT_REF_LIST_POCS(...)
#define UNUSED(x) (void)(x)

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef int16_t WORD16;
typedef int8_t WORD8;
typedef uint8_t UWORD8;

typedef struct codec_t codec_t;
typedef struct pps_t pps_t;
typedef struct sps_t sps_t;
typedef struct slice_header_t slice_header_t;
typedef struct pic_buf_t pic_buf_t;
typedef struct mv_buf_t mv_buf_t;
typedef struct dpb_mgr_t dpb_mgr_t;
typedef struct buf_mgr_t buf_mgr_t;

struct pic_buf_t {
    uint8_t u1_used_as_ref;
    int32_t i4_abs_poc;
};

struct mv_buf_t {
    int32_t i4_abs_poc;
};

struct dpb_info_t {
    pic_buf_t *ps_pic_buf;
};

struct dpb_mgr_t {
    struct dpb_info_t as_dpb_info[MAX_DPB_BUFS];
};

struct codec_t {
    void *pv_dpb_mgr;
    void *pv_mv_buf_mgr;
    void *pv_pic_buf_mgr;
    mv_buf_t *ps_mv_buf;
    int32_t i4_pic_present;
    int32_t i4_max_dpb_size;
};

struct pps_t {
    // Placeholder for PPS fields
};

struct sps_t {
    int8_t i1_log2_max_pic_order_cnt_lsb;
    int8_t i1_num_short_term_ref_pic_sets;
    struct {
        int8_t i1_num_neg_pics;
        int8_t i1_num_pos_pics;
        int8_t ai1_used[MAX_DPB_SIZE];
        int16_t ai2_delta_poc[MAX_DPB_SIZE];
    } as_stref_picset[MAX_DPB_SIZE];
};

struct slice_header_t {
    int32_t i4_abs_pic_order_cnt;
    int8_t i1_short_term_ref_pic_set_sps_flag;
    int8_t i1_short_term_ref_pic_set_idx;
    int8_t i1_slice_type;
    int8_t i1_num_ref_idx_l0_active;
    int8_t i1_num_ref_idx_l1_active;
    int8_t i1_num_long_term_sps;
    int8_t i1_num_long_term_pics;
    int32_t ai4_poc_lsb_lt[MAX_DPB_SIZE];
    int8_t ai1_delta_poc_msb_present_flag[MAX_DPB_SIZE];
    int8_t ai1_used_by_curr_pic_lt_flag[MAX_DPB_SIZE];
    int32_t ai1_delta_poc_msb_cycle_lt[MAX_DPB_SIZE];
    int32_t i4_pic_order_cnt_lsb;
    struct {
        int8_t i1_num_neg_pics;
        int8_t i1_num_pos_pics;
        int8_t ai1_used[MAX_DPB_SIZE];
        int16_t ai2_delta_poc[MAX_DPB_SIZE];
    } s_stref_picset;
    struct {
        int8_t i1_ref_pic_list_modification_flag_l0;
        int8_t i1_ref_pic_list_modification_flag_l1;
        int8_t i1_list_entry_l0[MAX_DPB_SIZE];
        int8_t i1_list_entry_l1[MAX_DPB_SIZE];
    } s_rplm;
    struct {
        void *pv_pic_buf;
        void *pv_mv_buf;
    } as_ref_pic_list0[MAX_DPB_SIZE], as_ref_pic_list1[MAX_DPB_SIZE];
};

struct buf_mgr_t {
    // Placeholder for buffer manager fields
};

pic_buf_t* ihevc_dpb_mgr_get_ref_by_poc_lsb(dpb_mgr_t *ps_dpb_mgr, int32_t poc);
pic_buf_t* ihevc_dpb_mgr_get_ref_by_poc(dpb_mgr_t *ps_dpb_mgr, int32_t poc);
pic_buf_t* ihevc_dpb_mgr_get_ref_by_nearest_poc(dpb_mgr_t *ps_dpb_mgr, int32_t poc);
void ihevc_dpb_mgr_del_ref(dpb_mgr_t *ps_dpb_mgr, buf_mgr_t *ps_buf_mgr, int32_t poc);
mv_buf_t* ihevcd_mv_mgr_get_poc(buf_mgr_t *ps_mv_buf_mgr, int32_t poc);
void ihevc_buf_mgr_release(buf_mgr_t *ps_buf_mgr, int32_t idx, int32_t mode);

#define BUF_MGR_REF 0