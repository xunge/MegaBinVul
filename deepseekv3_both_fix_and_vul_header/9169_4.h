#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX_MAC_FRAMES 32
#define MAX_RLC_CHANS 32
#define RLC_LI_7BITS 7
#define ENC_BIG_ENDIAN 0
#define COL_INFO 0
#define TRUE 1
#define FALSE 0

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef bool gboolean;
typedef unsigned int guint;

struct tvbuff;
struct packet_info {
    void *cinfo;
};
struct proto_tree;
struct proto_item;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct fp_info {
    guint8 release;
    guint8 hsdsch_macflowd_id;
    gboolean hsdhsch_macfdlow_is_mux[32];
    gboolean reset_frag;
    gboolean is_uplink;
    guint32 com_context_id;
};

typedef struct {
    guint8 mode[MAX_RLC_CHANS];
    guint8 li_size[MAX_RLC_CHANS];
    gboolean deciphered[MAX_RLC_CHANS];
    gboolean ciphered[MAX_RLC_CHANS];
    guint16 urnti[MAX_RLC_CHANS];
    guint8 rbid[MAX_RLC_CHANS];
} rlc_info;

typedef struct {
    guint16 pdu_len;
    guint8 content[MAX_MAC_FRAMES];
    guint8 lchid[MAX_MAC_FRAMES];
    gboolean fake_chid[MAX_MAC_FRAMES];
    guint8 macdflow_id[MAX_MAC_FRAMES];
    gboolean ctmux[MAX_MAC_FRAMES];
} umts_mac_info;

extern int proto_rlc;
extern int proto_umts_mac;
extern int hf_fp_header_crc;
extern int hf_fp_ft;
extern int hf_fp_frame_seq_nr;
extern int hf_fp_cmch_pi;
extern int hf_fp_mac_d_pdu_len;
extern int hf_fp_flush;
extern int hf_fp_fsn_drt_reset;
extern int hf_fp_num_of_pdu;
extern int hf_fp_user_buffer_size;
extern int hf_fp_hsdsch_new_ie_flags;
extern int hf_fp_hsdsch_new_ie_flag[8];
extern int hf_fp_hsdsch_drt;
extern int ett_fp_hsdsch_new_ie_flags;
extern void (*expert_add_info)(packet_info *pinfo, proto_item *item, void *ei);
extern void *ei_fp_maybe_srb;

extern guint8 hsdsch_macdflow_id_mac_content_map[];
extern guint8 hsdsch_macdflow_id_rlc_map[];
extern guint8 fake_lchid_macd_flow[];

extern gboolean preferences_header_checksum;

extern void *wmem_file_scope();
extern void *p_get_proto_data(void *scope, packet_info *pinfo, int proto, int index);
extern guint8 tvb_get_bits8(tvbuff_t *tvb, int bit_offset, int no_of_bits);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
extern int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_item *proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *str, const char *format);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern void col_append_str(void *cinfo, int column, const char *str);
extern void col_append_fstr(void *cinfo, int column, const char *fmt, ...);
extern void dissect_common_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, struct fp_info *p_fp_info);
extern void verify_control_frame_crc(tvbuff_t *tvb, packet_info *pinfo, proto_item *header_crc_pi, guint16 header_crc);
extern void verify_header_crc(tvbuff_t *tvb, packet_info *pinfo, proto_item *header_crc_pi, guint16 header_crc, guint header_length);
extern void dissect_spare_extension_and_crc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int crc_len, int offset, int header_length);
extern int dissect_macd_pdu_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 pdu_length, guint8 number_of_pdus, struct fp_info *p_fp_info);