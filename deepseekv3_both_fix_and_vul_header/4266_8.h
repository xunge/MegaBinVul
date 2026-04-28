#include <stdint.h>

#define IDR_SLICE_NAL 5
#define END_OF_MMCO 0
#define MAX_REF_BUFS 16
#define MARK_ST_PICNUM_AS_NONREF 1
#define MARK_LT_INDEX_AS_NONREF 2
#define MARK_ST_PICNUM_AS_LT_INDEX 3
#define SET_MAX_LT_INDEX 4
#define RESET_REF_PICTURES 5
#define SET_LT_INDEX 6

typedef uint32_t UWORD32;
typedef uint8_t UWORD8;
typedef int32_t WORD32;

struct MMCParams {
    UWORD32 u4_mmco;
    UWORD32 u4_diff_pic_num;
    UWORD32 u4_lt_idx;
    UWORD32 u4_max_lt_idx_plus1;
};

struct dec_bit_stream_t {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
};

struct dec_slice_params_t {
    UWORD8 u1_mmco_equalto5;
    UWORD8 u1_no_output_of_prior_pics_flag;
    UWORD8 u1_long_term_reference_flag;
};

struct dpb_commands_t {
    UWORD8 u1_idr_pic;
    UWORD8 u1_no_output_of_prior_pics_flag;
    UWORD8 u1_long_term_reference_flag;
    UWORD8 u1_buf_mode;
    UWORD8 u1_num_of_commands;
    UWORD8 u1_dpb_commands_read;
    UWORD8 u1_dpb_commands_read_slc;
    struct MMCParams as_mmc_params[MAX_REF_BUFS];
};

struct _DecStruct {
    struct dec_bit_stream_t *ps_bitstrm;
    struct dpb_commands_t *ps_dpb_cmds;
    struct dec_slice_params_t *ps_cur_slice;
    UWORD8 u1_nal_unit_type;
};

typedef struct dec_bit_stream_t dec_bit_stream_t;
typedef struct dpb_commands_t dpb_commands_t;
typedef struct dec_slice_params_t dec_slice_params_t;

#define COPYTHECONTEXT(str, val) (void)0
#define ALOGE(...) (void)0
#define android_errorWriteLog(...) (void)0

UWORD8 ih264d_get_bit_h264(dec_bit_stream_t *ps_bitstrm);
UWORD32 ih264d_uev(UWORD32 *pu4_bitstrm_ofst, UWORD32 *pu4_bitstrm_buf);