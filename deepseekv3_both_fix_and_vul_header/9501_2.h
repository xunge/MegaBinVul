#include <stdint.h>
#include <stddef.h>

typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;
typedef int gint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;

#define ENC_BIG_ENDIAN 0
#define ENC_EBCDIC 0
#define ENC_NA 0

typedef struct {
    int* hf_ptr;
    int ett;
    int length;
    const int** flags;
    int encoding;
} hf_items;

extern proto_tree *tn5250_tree;
extern int hf_tn5250_sf_length;
extern int hf_tn5250_sf_class;
extern int hf_tn5250_sf_type;
extern int hf_tn5250_wsf_qss_flag1_0;
extern int hf_tn5250_wsf_qss_flag1_reserved;
extern int hf_tn5250_wsf_qss_flag2_reserved;
extern int hf_tn5250_wsf_qss_flag2_7;
extern int hf_tn5250_wsf_qss_flag1;
extern int hf_tn5250_wsf_qss_flag2;
extern int ett_tn5250_wsf_qss_mask;
extern int hf_tn5250_dawt_length;
extern int hf_tn5250_dawt_char;
extern int hf_tn5250_dckf_length;
extern int hf_tn5250_dckf_key_code;
extern int hf_tn5250_dckf_function_code;
extern int hf_tn5250_rts_flag1_0;
extern int hf_tn5250_rts_flag1_reserved;
extern int hf_tn5250_rts_partition;
extern int hf_tn5250_rts_flag1;
extern int ett_tn5250_wsf_rts_mask;
extern int hf_tn5250_reserved;
extern int hf_tn5250_dpo_flag1_0;
extern int hf_tn5250_dpo_flag1_1;
extern int hf_tn5250_dpo_flag1_2;
extern int hf_tn5250_dpo_flag1_3;
extern int hf_tn5250_dpo_flag1_4;
extern int hf_tn5250_dpo_flag1_5;
extern int hf_tn5250_dpo_flag1_6;
extern int hf_tn5250_dpo_flag1_7;
extern int hf_tn5250_dpo_flag2_0;
extern int hf_tn5250_dpo_flag2_reserved;
extern int hf_tn5250_dpo_partition;
extern int hf_tn5250_dpo_flag1;
extern int hf_tn5250_dpo_flag2;
extern int ett_tn5250_wsf_dpo_mask;
extern int hf_tn5250_dpo_displace_characters;
extern int hf_tn5250_dpo_start_location_row;
extern int hf_tn5250_dpo_start_location_col;
extern int hf_tn5250_dtsf_flag1_0;
extern int hf_tn5250_dtsf_flag1_1;
extern int hf_tn5250_dtsf_flag1_2;
extern int hf_tn5250_dtsf_flag1_3;
extern int hf_tn5250_dtsf_flag1_4;
extern int hf_tn5250_dtsf_flag1_5;
extern int hf_tn5250_dtsf_flag1_6;
extern int hf_tn5250_dtsf_flag1_7;
extern int hf_tn5250_dtsf_flag2_0;
extern int hf_tn5250_dtsf_flag2_1;
extern int hf_tn5250_dtsf_flag2_2;
extern int hf_tn5250_dtsf_flag2_3;
extern int hf_tn5250_dtsf_flag2_4to7;
extern int hf_tn5250_dtsf_partition;
extern int hf_tn5250_dtsf_flag1;
extern int hf_tn5250_dtsf_flag2;
extern int ett_tn5250_wsf_dtsf_mask;
extern int hf_tn5250_dtsf_text_body_height;
extern int hf_tn5250_dtsf_text_body_width;
extern int hf_tn5250_dtsf_line_cmd_field_size;
extern int hf_tn5250_dtsf_location_of_pitch;
extern int hf_tn5250_dtsf_first_line;
extern int hf_tn5250_dsl_flag1_0;
extern int hf_tn5250_dsl_flag1_1;
extern int hf_tn5250_dsl_flag1_2;
extern int hf_tn5250_dsl_flag1_reserved;
extern int hf_tn5250_dsl_partition;
extern int hf_tn5250_dsl_rtl_offset;
extern int hf_tn5250_dsl_offset;
extern int hf_tn5250_length;
extern int hf_tn5250_dsl_flag1;
extern int ett_tn5250_wsf_dsl_mask;
extern int hf_tn5250_dsl_id;
extern int hf_tn5250_dsl_location;
extern int hf_tn5250_dsl_function;
extern int hf_tn5250_wts_flag1_0;
extern int hf_tn5250_wts_flag1_1;
extern int hf_tn5250_wts_flag1_2;
extern int hf_tn5250_wts_flag1_3;
extern int hf_tn5250_wts_flag1_reserved;
extern int hf_tn5250_wts_flag2_reserved;
extern int hf_tn5250_wts_flag2_6;
extern int hf_tn5250_wts_flag2_reserved2;
extern int hf_tn5250_wts_flag3_0;
extern int hf_tn5250_wts_flag3_1;
extern int hf_tn5250_wts_flag3_2;
extern int hf_tn5250_wts_flag3_3;
extern int hf_tn5250_wts_flag3_4;
extern int hf_tn5250_wts_flag3_5;
extern int hf_tn5250_wts_flag3_6;
extern int hf_tn5250_wts_flag3_7;
extern int hf_tn5250_wts_partition;
extern int hf_tn5250_wts_flag1;
extern int hf_tn5250_wts_flag2;
extern int hf_tn5250_wts_flag3;
extern int ett_tn5250_wts_mask;
extern int hf_tn5250_wts_home_position_row;
extern int hf_tn5250_wts_home_position_col;
extern int hf_tn5250_wts_cld_flag1_0;
extern int hf_tn5250_wts_cld_flag1_1;
extern int hf_tn5250_wts_cld_flag1_2;
extern int hf_tn5250_wts_cld_flag1_3;
extern int hf_tn5250_wts_cld_flag1_4;
extern int hf_tn5250_wts_cld_flag1_5;
extern int hf_tn5250_wts_cld_flag1_6;
extern int hf_tn5250_wts_cld_flag1_7;
extern int hf_tn5250_wts_cld_flag2_0;
extern int hf_tn5250_wts_cld_flag2_1;
extern int hf_tn5250_wts_cld_flag2_2;
extern int hf_tn5250_wts_cld_flag2_3;
extern int hf_tn5250_wts_cld_flag2_4;
extern int hf_tn5250_wts_cld_flag2_line_spacing;
extern int hf_tn5250_wts_cld_flag3_0;
extern int hf_tn5250_wts_cld_flag3_1;
extern int hf_tn5250_wts_cld_flag3_2;
extern int hf_tn5250_wts_cld_flag3_3;
extern int hf_tn5250_wts_cld_flag3_4;
extern int hf_tn5250_wts_cld_flag3_5;
extern int hf_tn5250_wts_cld_flag3_6;
extern int hf_tn5250_wts_cld_flag3_7;
extern int hf_tn5250_wts_cld_flag1;
extern int hf_tn5250_wts_cld_flag2;
extern int hf_tn5250_wts_cld_flag3;
extern int hf_tn5250_wts_cld_row;
extern int hf_tn5250_wts_cld_page_num;
extern int hf_tn5250_wts_cld_lmo;
extern int hf_tn5250_wts_cld_io;
extern int hf_tn5250_wts_cld_sli;
extern int hf_tn5250_wts_cld_li;
extern int hf_tn5250_dsc_partition;
extern int hf_tn5250_dsc_sk;
extern int hf_tn5250_dsc_ev;
extern int hf_tn5250_dorm_length;
extern int hf_tn5250_dorm_ec;
extern int hf_tn5250_dorm_id;
extern int hf_tn5250_dorm_mt;
extern int hf_tn5250_dpt_id;
extern int hf_tn5250_dpt_ec;
extern int hf_tn5250_dfdpck_coreflag_0;
extern int hf_tn5250_dfdpck_coreflag_1;
extern int hf_tn5250_dfdpck_coreflag_2;
extern int hf_tn5250_dfdpck_coreflag_3;
extern int hf_tn5250_dfdpck_coreflag_4;
extern int hf_tn5250_dfdpck_coreflag_5;
extern int hf_tn5250_dfdpck_coreflag_6;
extern int hf_tn5250_dfdpck_coreflag_7;
extern int hf_tn5250_dfdpck_toprowflag1_0;
extern int hf_tn5250_dfdpck_toprowflag1_1;
extern int hf_tn5250_dfdpck_toprowflag1_2;
extern int hf_tn5250_dfdpck_toprowflag1_3;
extern int hf_tn5250_dfdpck_toprowflag1_4;
extern int hf_tn5250_dfdpck_toprowflag1_5;
extern int hf_tn5250_dfdpck_toprowflag1_6;
extern int hf_tn5250_dfdpck_toprowflag1_7;
extern int hf_tn5250_dfdpck_toprowflag2_0;
extern int hf_tn5250_dfdpck_toprowflag2_1;
extern int hf_tn5250_dfdpck_toprowflag2_2;
extern int hf_tn5250_dfdpck_toprowflag2_3;
extern int hf_tn5250_dfdpck_toprowflag2_4;
extern int hf_tn5250_dfdpck_toprowflag2_5;
extern int hf_tn5250_dfdpck_toprowflag2_6;
extern int hf_tn5250_dfdpck_toprowflag2_7;
extern int hf_tn5250_dfdpck_toprowflag3_0;
extern int hf_tn5250_dfdpck_toprowflag3_1;
extern int hf_tn5250_dfdpck_toprowflag3_2;
extern int hf_tn5250_dfdpck_toprowflag3_3;
extern int hf_tn5250_dfdpck_toprowflag3_4;
extern int hf_tn5250_dfdpck_toprowflag3_5;
extern int hf_tn5250_dfdpck_toprowflag3_6;
extern int hf_tn5250_dfdpck_toprowflag3_7;
extern int hf_tn5250_dfdpck_partition;
extern int hf_tn5250_dfdpck_data_field;
extern int hf_tn5250_dfdpck_coreflag;
extern int ett_tn5250_dfdpck_mask;
extern int hf_tn5250_dfdpck_toprowflag1;
extern int hf_tn5250_dfdpck_toprowflag2;
extern int hf_tn5250_dfdpck_toprowflag3;
extern int hf_tn5250_field_data;
extern int hf_tn5250_dawt_id;
extern int hf_tn5250_dawt_message;
extern int hf_tn5250_dckf_id;
extern int hf_tn5250_dckf_prompt_text;

#define PASS_THROUGH 0x00
#define TN5250_QUERY 0x01
#define TN5250_QUERY_STATION_STATE 0x02
#define DEFINE_AUDIT_WINDOW__TABLE 0x03
#define DEFINE_COMMAND_KEY_FUNCTION 0x04
#define READ_TEXT_SCREEN 0x05
#define DEFINE_PENDING_OPERATIONS 0x06
#define DEFINE_TEXT_SCREEN_FORMAT 0x07
#define DEFINE_SCALE_LINE 0x08
#define WRITE_TEXT_SCREEN 0x09
#define DEFINE_SPECIAL_CHARACTERS 0x0A
#define DEFINE_OPERATOR_ERROR_MESSAGES 0x0B
#define DEFINE_PITCH_TABLE 0x0C
#define DEFINE_FAKE_DP_COMMAND_KEY_FUNCTION 0x0D
#define CORE_AREA_COMMAND_KEYS 0x01
#define TOP_ROW_COMMAND_KEYS 0x02

guint32 tn5250_add_hf_items(proto_tree *tree, tvbuff_t *tvb, gint offset, hf_items *items);
guint32 dissect_unknown_data(proto_tree *tree, tvbuff_t *tvb, gint offset, gint start, guint16 length);

static inline guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset) {
    return 0;
}

static inline guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset) {
    return 0;
}

static inline gint tvb_reported_length_remaining(tvbuff_t *tvb, gint offset) {
    return 0;
}

static inline void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, gint offset, gint length, int encoding) {
}