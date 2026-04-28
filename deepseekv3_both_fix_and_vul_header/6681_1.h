#include <stdint.h>

typedef enum {
    MPEG_1_VIDEO,
    MPEG_2_VIDEO
} e_video_type_t;

typedef enum {
    FRAME_PICTURE,
    TOP_FIELD,
    BOTTOM_FIELD
} PICTURE_STRUCTURE_T;

typedef enum {
    VERTICAL_SCAN
} SCAN_TYPE_T;

typedef enum {
    IVD_ERROR_NONE,
    IMPEG2D_PIC_SIZE_NOT_SUPPORTED
} IMPEG2D_ERROR_CODES_T;

typedef uint32_t UWORD32;
typedef uint8_t UWORD8;
typedef uint16_t UWORD16;

typedef struct {
    UWORD16 u2_is_mpeg2;
    UWORD16 u2_progressive_sequence;
    UWORD16 u2_intra_dc_precision;
    UWORD16 u2_picture_structure;
    UWORD16 u2_frame_pred_frame_dct;
    UWORD16 u2_concealment_motion_vectors;
    UWORD16 u2_q_scale_type;
    UWORD16 u2_intra_vlc_format;
    UWORD16 u2_alternate_scan;
    UWORD16 u2_repeat_first_field;
    UWORD16 u2_progressive_frame;
    UWORD16 u2_frame_rate_extension_n;
    UWORD16 u2_frame_rate_extension_d;
    UWORD16 u2_full_pel_forw_vector;
    UWORD16 u2_forw_f_code;
    UWORD16 u2_full_pel_back_vector;
    UWORD16 u2_back_f_code;
    UWORD16 u2_frame_height;
    UWORD16 u2_frame_width;
    UWORD16 u2_horizontal_size;
    UWORD16 u2_vertical_size;
    UWORD16 u2_create_max_height;
    UWORD16 u2_create_max_width;
    UWORD16 u2_num_horiz_mb;
    UWORD16 u2_num_flds_decoded;
    UWORD16 u2_frame_rate_code;
    UWORD32 u2_framePeriod;
    UWORD8* pu1_inv_scan_matrix;
    void (*pf_vld_inv_quant)(void);
} dec_state_t;

#define ALIGN16(x) (((x) + 15) & ~15)

extern const UWORD16 gau2_impeg2_frm_rate_code[][2];
extern const UWORD8 gau1_impeg2_inv_scan_zig_zag[];
extern const UWORD8 gau1_impeg2_inv_scan_vertical[];

void impeg2d_init_function_ptr(dec_state_t *ps_dec);
void impeg2d_vld_inv_quant_mpeg1(void);
void impeg2d_vld_inv_quant_mpeg2(void);