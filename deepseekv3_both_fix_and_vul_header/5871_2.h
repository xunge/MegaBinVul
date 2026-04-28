#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct _proto_node proto_node;

typedef struct {
    uint8_t flags;
} RlcMacUplink_t;

typedef struct {
    uint16_t bsn1;
    uint16_t bsn2;
    uint8_t pi;
} egprs_ul_header_info_t;

typedef struct {
    uint8_t value;
} length_indicator_t;

typedef int gint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint64_t guint64;

#define COL_INFO 0
#define ENC_BIG_ENDIAN 0

extern proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
extern proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int length, const char *format, ...);
extern void proto_tree_add_bits_item(proto_tree *tree, int hf, tvbuff_t *tvb, int bit_offset, int no_of_bits, int encoding);
extern void proto_tree_add_bits_ret_val(proto_tree *tree, int hf, tvbuff_t *tvb, int bit_offset, int no_of_bits, guint64 *retval, int encoding);
extern void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, void *ei, tvbuff_t *tvb, int offset, int length);
extern void col_append_sep_str(void *cinfo, int column, const char *sep, const char *str);
extern int tvb_reported_length(tvbuff_t *tvb);

extern int proto_gsm_rlcmac;
extern int ett_gsm_rlcmac_data;
extern int hf_ti;
extern int hf_e;
extern int hf_tlli;
extern int hf_pfi;
extern void *ei_gsm_rlcmac_unexpected_header_extension;

#define GSM_RLC_MAC_EGPRS_BLOCK2 0x01

#define array_length(arr) (sizeof(arr) / sizeof((arr)[0]))

extern int construct_egprs_data_segment_li_array(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint8 *li_count, length_indicator_t *li_array, guint64 *e);
extern void dissect_egprs_data_segments(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int length, guint8 li_count, length_indicator_t *li_array);