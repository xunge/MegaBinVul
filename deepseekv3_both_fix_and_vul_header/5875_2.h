#include <stdint.h>
#include <stddef.h>

#define PAYLOAD_TYPE_DATA 0
#define PAYLOAD_TYPE_RESERVED 3
#define RLCMAC_CS1 0
#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_BIG_ENDIAN 0

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint64_t guint64;
typedef int gint;

typedef struct {
    int bit_offset;
} csnStream_t;

typedef struct {
    guint8 TI;
    guint8 PI;
    guint64 E;
} UL_Data_Block_GPRS_t;

typedef struct {
    guint8 block_format;
    union {
        UL_Data_Block_GPRS_t UL_Data_Block_GPRS;
    } u;
} RlcMacUplink_t;

typedef struct {
    int cinfo;
} packet_info;

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff tvbuff_t;

extern int proto_gsm_rlcmac;
extern int ett_gsm_rlcmac;
extern int hf_tlli;
extern int hf_pfi;
extern int hf_e;
extern int ei_gsm_rlcmac_unexpected_header_extension;
extern int ei_gsm_rlcmac_coding_scheme_invalid;

typedef struct {
    guint8 value;
} length_indicator_t;

void csnStreamInit(csnStream_t *ar, int init_val, guint16 bit_length);
void csnStreamDissector(proto_tree *tree, csnStream_t *ar, const char *desc, tvbuff_t *tvb, void *data, int ett);
guint8 tvb_get_bits8(tvbuff_t *tvb, int bit_offset, int no_of_bits);
guint16 tvb_reported_length(tvbuff_t *tvb);
void col_set_str(int cinfo, int col, const char *str);
void col_append_sep_str(int cinfo, int col, const char *sep, const char *str);
proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int length, const char *format, ...);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
void proto_tree_add_bits_item(proto_tree *tree, int hf, tvbuff_t *tvb, int bit_offset, int no_of_bits, int encoding);
void proto_tree_add_bits_ret_val(proto_tree *tree, int hf, tvbuff_t *tvb, int bit_offset, int no_of_bits, guint64 *retval, int encoding);
void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, int *ei, tvbuff_t *tvb, int offset, int length);
void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, int *ei, tvbuff_t *tvb, int offset, int length, const char *format, ...);
int construct_gprs_data_segment_li_array(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint8 *li_count, length_indicator_t *li_array, guint64 *e);
void dissect_gprs_data_segments(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int length, guint8 li_count, length_indicator_t *li_array);
void dissect_ul_rlc_control_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacUplink_t *data, guint16 bit_length);

#define array_length(arr) (sizeof(arr)/sizeof(arr[0]))
#define CSNDESCR(type) #type