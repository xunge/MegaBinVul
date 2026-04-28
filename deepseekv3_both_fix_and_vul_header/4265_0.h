#include <stdint.h>

#define WORD32 int32_t
#define UWORD32 uint32_t
#define UWORD16 uint16_t
#define OK 0
#define ERROR_DBP_MANAGER_T -1
#define ERROR_INV_RANGE_QP_T -2
#define ERROR_INV_SLICE_HDR_T -3
#define SLICE_BOUNDARY_DBLK_DISABLED 2
#define MIN_DBLK_FIL_OFF -6
#define MAX_DBLK_FIL_OFF 6

typedef struct dec_bitstrm_t {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
} dec_bitstrm_t;

typedef struct dec_dpb_commands_t {
    UWORD32 u1_dpb_commands_read;
} dec_dpb_commands_t;

typedef struct dec_pic_params_t {
    int8_t u1_pic_init_qp;
    uint8_t u1_deblocking_filter_parameters_present_flag;
    uint8_t u1_entropy_coding_mode;
} dec_pic_params_t;

typedef struct dec_slice_params_t {
    uint8_t u1_nal_ref_idc;
    int8_t u1_slice_qp;
    uint8_t u1_disable_dblk_filter_idc;
    int8_t i1_slice_alpha_c0_offset;
    int8_t i1_slice_beta_offset;
    uint8_t u1_mbaff_frame_flag;
} dec_slice_params_t;

typedef struct dec_struct_t {
    dec_pic_params_t *ps_cur_pps;
    dec_slice_params_t *ps_cur_slice;
    dec_bitstrm_t *ps_bitstrm;
    dec_dpb_commands_t *ps_dpb_cmds;
    uint32_t u4_bitoffset;
    uint16_t u2_mv_2mb[2];
    uint8_t u1_slice_header_done;
    void (*pf_get_mb_info)(void);
} dec_struct_t;

#define COPYTHECONTEXT(s, v) 
#define SWITCHOFFTRACE 
#define SWITCHONTRACE 
#define SWITCHOFFTRACECABAC 
#define SWITCHONTRACECABAC 

int ih264d_sev(UWORD32 *pu4_bitstrm_ofst, UWORD32 *pu4_bitstrm_buf);
int ih264d_uev(UWORD32 *pu4_bitstrm_ofst, UWORD32 *pu4_bitstrm_buf);
int ih264d_read_mmco_commands(dec_struct_t *ps_dec);
int ih264d_parse_islice_data_cabac(dec_struct_t *ps_dec, dec_slice_params_t *ps_slice, UWORD16 u2_first_mb_in_slice);
int ih264d_parse_islice_data_cavlc(dec_struct_t *ps_dec, dec_slice_params_t *ps_slice, UWORD16 u2_first_mb_in_slice);
void ih264d_get_mb_info_cabac_mbaff(void);
void ih264d_get_mb_info_cabac_nonmbaff(void);
void ih264d_get_mb_info_cavlc_mbaff(void);
void ih264d_get_mb_info_cavlc_nonmbaff(void);