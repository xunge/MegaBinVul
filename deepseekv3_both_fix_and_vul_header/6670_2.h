#include <stdint.h>

#define IDR_SLICE_NAL 5
#define END_OF_MMCO 0
#define MAX_REF_BUFS 16

#define MARK_ST_PICNUM_AS_NONREF 0
#define MARK_LT_INDEX_AS_NONREF 1
#define MARK_ST_PICNUM_AS_LT_INDEX 2
#define SET_MAX_LT_INDEX 3
#define RESET_REF_PICTURES 4
#define SET_LT_INDEX 5

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;

struct dec_bit_stream_t {
    UWORD32* pu4_buffer;
    UWORD32 u4_ofst;
};

struct MMCParams {
    UWORD32 u4_mmco;
    UWORD32 u4_diff_pic_num;
    UWORD32 u4_lt_idx;
    UWORD32 u4_max_lt_idx_plus1;
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

struct dec_slice_params_t {
    UWORD8 u1_mmco_equalto5;
    UWORD8 u1_no_output_of_prior_pics_flag;
    UWORD8 u1_long_term_reference_flag;
};

struct _DecStruct {
    struct dec_bit_stream_t* ps_bitstrm;
    struct dpb_commands_t s_dpb_cmds_scratch;
    struct dpb_commands_t* ps_dpb_cmds;
    struct dec_slice_params_t* ps_cur_slice;
    UWORD8 u1_nal_unit_type;
};

UWORD8 ih264d_get_bit_h264(struct dec_bit_stream_t* ps_bitstrm);
UWORD32 ih264d_uev(UWORD32* pu4_bitstrm_ofst, UWORD32* pu4_bitstrm_buf);
#define COPYTHECONTEXT(str, val) ((void)0)

typedef struct dec_bit_stream_t dec_bit_stream_t;
typedef struct dpb_commands_t dpb_commands_t;
typedef struct dec_slice_params_t dec_slice_params_t;