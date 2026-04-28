#include <stdint.h>
#include <stddef.h>

#define TAB_MAX 0
#define EID_PARSE_ERROR 0
#define TLV_TYPE 0
#define TLV_LENGTH 0
#define TLV_VALUE 0
#define TAB_RSS_DATA_ARRAY 0
#define EID_RSS_DATA_BLOCK 0
#define TAB_CONFIG_SITE 0
#define EID_SITE_TOPOLOGY_BLOCK 0
#define VNS_CONFIG_BLOCK 0
#define EID_V_COS 0
#define EID_V_RATE_LIMIT_RESOURCE_TBL 0
#define TAB_CONFIG_FILTER 0
#define TAB_FILTER_CONFIG_STRUCT_BLOCK 0
#define EID_V_FILTER_RULES 0
#define EID_FILTER_RULES 0
#define EID_V_SITE_FILTER_RULES 0
#define TAB_SCAN_PROFILE_BLOCK 0
#define EID_CHANNEL_LIST 0
#define TAB_SURVEILLANCE_DATA_BLOCK 0
#define EID_SCAN_RSS_RSSI 0
#define EID_PARAMS 0
#define CONFIG_GLOBAL_BLOCK 0
#define EID_ON_DEMAND_ARRAY 0
#define EID_DYN_ON_DEMAND_ARRAY 0
#define TAB_DETECTED_ROGUE_BLOCK 0
#define EID_DNS_IP_ADDR 0
#define RADIO_CONFIG_BLOCK 0
#define WASSP_RU_Ack 0
#define TAB_RU_ACK_RADIO_CONFIG 0
#define FALSE 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0

typedef uint32_t guint32;
typedef uint16_t guint16;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;

typedef struct {
    char *subtree_name;
} WASSP_SUBTLV_DECODER_INFO_t;

extern WASSP_SUBTLV_DECODER_INFO_t wassp_decr_info[];
extern int hf_wassp_sub_tree;
extern int hf_wassp_tlv_unknown;
extern int hf_wassp_tlv_length;
extern int hf_wassp_tlv_value_octext;
extern int hf_wassp_tlv_invalid;
extern int hf_wassp_tlv_value;
extern int hf_wassp_tlv_type_sub;
extern int hf_wassp_topologykey;
extern int hf_wassp_topology_mode;
extern int hf_wassp_rss;
extern int hf_wassp_rssi;
extern int hf_wassp_threatstate;
extern int hf_wassp_radioparams;
extern int hf_wassp_channelfreq;

#define WASSP_SUBTLV_GET_ETTNUM(x) 0
#define WASSP_SUBTLV_GET_MAXENTRY(x) 0
#define WASSP_SUBTLV_GET_ENTRY_IDX_TYPE(x, y) 0
#define WASSP_SUBTLV_GET_ENTRY_IDX_TABIDX(x, y) 0
#define TLV_TYPE_BLOCK_TLV 0

char* wassp_match_strval(WASSP_SUBTLV_DECODER_INFO_t *decr, guint16 type);
int wassp_type_converter(int type);
void decode_cos_struct(proto_tree *tree, tvbuff_t *tvb, int offset);
void decode_rate_limit_struct(proto_tree *tree, tvbuff_t *tvb, int offset, int length);
void decode_filter_rule_octext_string(proto_tree *tree, tvbuff_t *tvb, int offset, int length);
void decode_Channel_list(proto_tree *tree, tvbuff_t *tvb, int offset, int length);
void decode_mac_list_struct(proto_tree *tree, tvbuff_t *tvb, int offset, int length);
void decode_ipv4_list_struct(proto_tree *tree, tvbuff_t *tvb, int offset, int length);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_item_append_text(proto_item *ti, const char *format, ...);
proto_tree* proto_item_add_subtree(proto_item *ti, int subtree_index);
void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...);