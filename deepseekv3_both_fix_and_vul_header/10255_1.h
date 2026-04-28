#include <stdint.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;

typedef enum {
    IHEVCD_SUCCESS,
    IHEVCD_INVALID_PARAMETER
} IHEVCD_ERROR_T;

typedef struct {
    int32_t i1_log2_max_transform_block_size;
    int32_t i1_log2_min_transform_block_size;
    int32_t i1_max_transform_hierarchy_depth_inter;
    int32_t i1_log2_ctb_size;
    int32_t i1_bit_depth_luma_minus8;
} sps_t;

typedef struct {
    int32_t i1_cu_qp_delta_enabled_flag;
} pps_t;

typedef struct {
    int32_t i4_max_trafo_depth;
    int32_t i4_intra_split_flag;
    int32_t i4_pred_mode;
    int32_t i4_part_mode;
    int32_t ai1_cbf_cr[4];
    int32_t ai1_cbf_cb[4];
    int32_t i1_cbf_luma;
    int32_t i4_cu_transquant_bypass;
    int32_t i4_intra_chroma_pred_mode_idx;
    int32_t ai4_intra_luma_pred_mode[4];
    int32_t i4_cu_qp_delta;
    int32_t i4_pos_x;
    int32_t i4_pos_y;
    int32_t i4_tu_cnt;
} cu_t;

typedef struct {
    int32_t u4_range;
} cab_ctxt_t;

typedef struct {
    int32_t dummy;
} bitstrm_t;

typedef struct {
    int32_t b1_cb_cbf;
    int32_t b1_cr_cbf;
    int32_t b1_y_cbf;
    int32_t b4_pos_x;
    int32_t b4_pos_y;
    int32_t b1_transquant_bypass;
    int32_t b3_size;
    int32_t b7_qp;
    int32_t b6_luma_intra_mode;
    int32_t b3_chroma_intra_mode_idx;
    int32_t b1_first_tu_in_cu;
} tu_t;

typedef struct {
    bitstrm_t s_bitstrm;
    cab_ctxt_t s_cabac;
    sps_t *ps_sps;
    pps_t *ps_pps;
    cu_t s_cu;
    tu_t *ps_tu;
    int32_t i4_ctb_x;
    int32_t i4_ctb_y;
    int32_t u4_qp;
    int32_t i4_is_cu_qp_delta_coded;
    int32_t i4_pic_tu_idx;
} parse_t;

typedef struct {
    parse_t s_parse;
} codec_t;

#define IHEVC_CAB_SPLIT_TFM 0
#define IHEVC_CAB_CBCR_IDX 0
#define IHEVC_CAB_CBF_LUMA_IDX 0
#define IHEVC_CAB_QP_DELTA_ABS 0
#define CTXT_MAX_QP_DELTA_ABS 0
#define TU_MAX_QP_DELTA_ABS 0
#define PRED_MODE_INTER 0
#define PRED_MODE_INTRA 1
#define PART_2Nx2N 0
#define INTRA_ANGULAR(x) (x)
#define INTRA_PRED_CHROMA_IDX_NONE 0
#define MIN_CU_QP_DELTA_ABS(x) 0
#define MAX_CU_QP_DELTA_ABS(x) 0

#define TRACE_CABAC_CTXT(x, y, z)
#define AEV_TRACE(x, y, z)

static const int32_t gau1_intra_pred_chroma_modes[] = {0};

int32_t ihevcd_cabac_decode_bin(cab_ctxt_t *ps_cabac, bitstrm_t *ps_bitstrm, int32_t ctxt_idx);
int32_t ihevcd_cabac_decode_bins_tunary(cab_ctxt_t *ps_cabac, bitstrm_t *ps_bitstrm, int32_t c_max, int32_t ctxt_inc, int32_t bypass_flag, int32_t ctxt_inc_max);
int32_t ihevcd_cabac_decode_bypass_bins_egk(cab_ctxt_t *ps_cabac, bitstrm_t *ps_bitstrm, int32_t k);
int32_t ihevcd_cabac_decode_bypass_bin(cab_ctxt_t *ps_cabac, bitstrm_t *ps_bitstrm);
void ihevcd_parse_residual_coding(codec_t *ps_codec, int32_t x0, int32_t y0, int32_t log2_trafo_size, int32_t chroma_mode, int32_t intra_pred_mode);