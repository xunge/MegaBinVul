#include <stdint.h>

typedef int32_t WORD32;
typedef uint8_t UWORD8;
typedef uint16_t UWORD16;
typedef uint32_t UWORD32;

typedef enum {
    IHEVCD_SUCCESS,
    IHEVCD_INSUFFICIENT_MEM_MVBANK,
    IHEVCD_BUF_MGR_ERROR
} IHEVCD_ERROR_T;

#define MIN_PU_SIZE 4
#define MIN_CTB_SIZE 64
#define ALIGN64(x) (((x) + 63) & ~63)
#define ALIGN4(x) (((x) + 3) & ~3)

typedef struct sps_t {
    int8_t ai1_sps_max_dec_pic_buffering[8];
    int8_t i1_sps_max_sub_layers;
    int16_t i2_pic_width_in_luma_samples;
    int16_t i2_pic_height_in_luma_samples;
} sps_t;

typedef struct pu_t {
    // PU structure definition
} pu_t;

typedef struct mv_buf_t {
    UWORD32* pu4_pic_pu_idx;
    UWORD8* pu1_pic_pu_map;
    UWORD16* pu1_pic_slice_map;
    pu_t* ps_pic_pu;
} mv_buf_t;

typedef struct buf_mgr_t {
    // Buffer manager structure definition
} buf_mgr_t;

typedef struct parse_t {
    sps_t* ps_sps;
    int32_t i4_error_code;
} parse_t;

typedef struct codec_t {
    void* pv_mv_bank_buf_base;
    mv_buf_t* ps_mv_buf;
    int32_t i4_total_mv_bank_size;
    int32_t i4_max_dpb_size;
    void* pv_mv_buf_mgr;
    parse_t s_parse;
} codec_t;

int ihevcd_get_pic_mv_bank_size(int size);
int ihevc_buf_mgr_add(buf_mgr_t* pv_mv_buf_mgr, mv_buf_t* ps_mv_buf, int index);