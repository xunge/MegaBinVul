#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef unsigned int guint;
typedef int gboolean;
#define FALSE 0
#define TRUE 1
#define ENC_BIG_ENDIAN 0
#define COL_INFO 0
#define RLC_LI_7BITS 7

typedef struct fp_info {
    guint8 release;
    guint8 hsdsch_macflowd_id;
    guint32 com_context_id;
} fp_info;

typedef struct umts_mac_info {
    guint8 content[31];
    guint8 lchid[31];
    guint8 macdflow_id[31];
    gboolean ctmux[31];
} umts_mac_info;

typedef struct rlc_info {
    guint8 mode[31];
    guint8 li_size[31];
    gboolean ciphered[31];
    gboolean deciphered[31];
    guint8 rbid[31];
    guint32 urnti[31];
} rlc_info;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _proto_node proto_node;

extern gboolean preferences_header_checksum;
extern int proto_rlc;
extern int proto_umts_mac;
extern int hf_fp_header_crc;
extern int hf_fp_ft;
extern int hf_fp_frame_seq_nr;
extern int hf_fp_cmch_pi;
extern int hf_fp_total_pdu_blocks;
extern int hf_fp_flush;
extern int hf_fp_fsn_drt_reset;
extern int hf_fp_drt_indicator;
extern int hf_fp_fach_indicator;
extern int hf_fp_user_buffer_size;
extern int hf_fp_hsdsch_pdu_block_header;
extern int hf_fp_pdu_length_in_block;
extern int hf_fp_pdus_in_block;
extern int hf_fp_lchid;
extern int hf_fp_drt;
extern int hf_fp_hrnti;
extern int hf_fp_rach_measurement_result;
extern int ett_fp_hsdsch_pdu_block_header;
extern guint8* lchId_type_table;
extern guint8* lchId_rlc_map;

guint8 tvb_get_bits8(tvbuff_t *tvb, int bit_offset, int no_of_bits);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void col_append_str(void *cinfo, int column, const char *str);
void col_append_fstr(void *cinfo, int column, const char *format, ...);
proto_item* proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *str, const char *format);
proto_tree* proto_item_add_subtree(proto_item *ti, int ett);
void proto_tree_add_bits_ret_val(proto_tree *tree, int hfindex, tvbuff_t *tvb, int bit_offset, int no_of_bits, guint64 *retval, int encoding);
void proto_item_append_text(proto_item *ti, const char *format, ...);
void proto_item_set_len(proto_item *ti, int length);
void* p_get_proto_data(void *scope, packet_info *pinfo, int proto, int index);
void* wmem_file_scope(void);
void* wmem_packet_scope(void);
void* wmem_new0(void *scope, size_t size);

void dissect_common_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, struct fp_info *p_fp_info);
void verify_control_frame_crc(tvbuff_t *tvb, packet_info *pinfo, proto_item *header_crc_pi, guint16 header_crc);
int dissect_macd_pdu_data_type_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 pdu_length, guint16 no_of_pdus, struct fp_info *p_fp_info, void *data);
void verify_header_crc(tvbuff_t *tvb, packet_info *pinfo, proto_item *header_crc_pi, guint16 header_crc, guint16 header_length);
void dissect_spare_extension_and_crc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int spare_extension_length, int offset, int header_length);

#define wmem_new0(scope, type) ((type *)wmem_new0_impl(scope, sizeof(type)))
void* wmem_new0_impl(void *scope, size_t size);