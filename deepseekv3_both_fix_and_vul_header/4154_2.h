#include <stdint.h>

#define OK 0
#define ERROR_MB_ADDRESS_T -1
#define ERROR_MB_TYPE -2

#define P_SLICE 0
#define B_SLICE 1
#define P_MB 0
#define B_MB 1
#define D_INTER_MB 0
#define D_B_SLICE 1
#define D_INTRA_MB 2
#define I_PCM_MB 3
#define MB_SKIP 4
#define PRED_16x16 5
#define PART_DIRECT_16x16 6
#define CAVLC 7

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int32_t WORD32;
typedef int16_t WORD16;
typedef int8_t WORD8;

typedef struct dec_bit_stream_t {
    UWORD32* pu4_buffer;
    UWORD32 u4_ofst;
    UWORD32 u4_max_ofst;
} dec_bit_stream_t;

typedef struct dec_mb_info_t {
    UWORD8 u1_Mux;
    UWORD8 u1_end_of_slice;
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_mc_mode;
    UWORD8 u1_cbp;
    UWORD8 u1_topmb;
    struct {
        UWORD8 u1_mb_type;
    } *ps_curmb;
} dec_mb_info_t;

typedef struct deblk_mb_t {
    UWORD8 u1_mb_type;
    UWORD8 u1_mb_qp;
} deblk_mb_t;

typedef struct parse_pmbarams_t {
    UWORD8 u1_num_part;
    UWORD8 u1_isI_mb;
} parse_pmbarams_t;

typedef struct parse_part_params_t {
    UWORD8 u1_is_direct;
    UWORD8 u1_sub_mb_num;
} parse_part_params_t;

typedef struct dec_slice_params_t {
    UWORD8 u1_slice_type;
    UWORD8 u1_slice_qp;
    UWORD8 u1_mbaff_frame_flag;
} dec_slice_params_t;

typedef struct dec_struct_t {
    UWORD16 u2_frm_wd_in_mbs;
    dec_bit_stream_t* ps_bitstrm;
    UWORD8 u1_qp;
    UWORD8 u1_mb_idx;
    struct {
        UWORD16 u2_max_mb_addr;
    } *ps_cur_sps;
    dec_mb_info_t* ps_nmb_info;
    UWORD32 u4_num_mbs_cur_nmb;
    UWORD32 u4_num_pmbair;
    deblk_mb_t* ps_deblk_mbn;
    void* pv_prev_mb_parse_tu_coeff_data;
    void* pv_parse_tu_coeff_data;
    parse_pmbarams_t* ps_parse_mb_data;
    UWORD8 u4_app_disable_deblk_frm;
    UWORD8 u1_mb_ngbr_availablity;
    UWORD8 u1_cur_mb_fld_dec_flag;
    WORD8 i1_prev_mb_qp_delta;
    UWORD8 u1_sub_mb_num;
    parse_part_params_t* ps_part;
    UWORD16 u2_mbx;
    UWORD16 u2_mby;
    UWORD8 u1_recon_mb_grp;
    UWORD16 u2_total_mbs_coded;
    UWORD8 u1_separate_parse;
    parse_part_params_t* ps_parse_part_params;
    struct {
        UWORD32 u4_mbs_in_slice;
    } *ps_cur_slice;
    WORD32 (*pf_get_mb_info)(struct dec_struct_t*, WORD32, dec_mb_info_t*, UWORD32);
    WORD32 (*pf_parse_inter_mb)(struct dec_struct_t*, dec_mb_info_t*, UWORD32, UWORD32);
    void (*pf_mvpred_ref_tfr_nby2mb)(struct dec_struct_t*, UWORD32, UWORD32);
} dec_struct_t;

#define CLZ(x) __builtin_clz(x)
#define NEXTBITS_32(val, offset, buf) val = *(buf + (offset >> 5)) << (offset & 0x1F)
#define GETBITS(val, offset, buf, numbits) val = (*(buf + (offset >> 5)) >> (32 - (offset & 0x1F) - numbits)) & ((1 << numbits) - 1)
#define MORE_RBSP_DATA(bitstrm) ((bitstrm)->u4_ofst < ((bitstrm)->u4_max_ofst - 1))
#define COPYTHECONTEXT(str, val) (void)0

/* Function declarations */
WORD32 ih264d_update_qp(dec_struct_t *ps_dec, WORD32 i_qp);
WORD32 ih264d_set_deblocking_parameters(deblk_mb_t *ps_cur_deblk_mb, 
                                       dec_slice_params_t *ps_slice,
                                       UWORD8 u1_mb_ngbr_availablity,
                                       UWORD8 u1_cur_mb_fld_dec_flag);
WORD32 ih264d_update_nnz_for_skipmb(dec_struct_t *ps_dec, 
                                   dec_mb_info_t *ps_cur_mb_info,
                                   UWORD8 u1_cavlc);
WORD32 ih264d_parse_ipcm_mb(dec_struct_t *ps_dec, 
                           dec_mb_info_t *ps_cur_mb_info,
                           UWORD32 u1_num_mbs);
WORD32 ih264d_parse_imb_cavlc(dec_struct_t *ps_dec,
                             dec_mb_info_t *ps_cur_mb_info,
                             UWORD32 u1_num_mbs,
                             UWORD8 u1_mb_type);
WORD32 ih264d_update_mbaff_left_nnz(dec_struct_t *ps_dec,
                                   dec_mb_info_t *ps_cur_mb_info);
WORD32 ih264d_parse_tfr_nmb(dec_struct_t *ps_dec,
                           UWORD32 u1_mb_idx,
                           UWORD32 u1_num_mbs,
                           UWORD32 u1_num_mbs_next,
                           UWORD32 u1_tfr_n_mb,
                           UWORD32 u1_end_of_row);
WORD32 ih264d_decode_recon_tfr_nmb(dec_struct_t *ps_dec,
                                  UWORD32 u1_mb_idx,
                                  UWORD32 u1_num_mbs,
                                  UWORD32 u1_num_mbs_next,
                                  UWORD32 u1_tfr_n_mb,
                                  UWORD32 u1_end_of_row);