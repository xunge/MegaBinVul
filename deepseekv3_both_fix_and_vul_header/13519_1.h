#include <stdint.h>

#define XRA_BURST_INFO_BURST_ID_REFERENCE 0
#define XRA_US_CHANNEL_ID 1
#define XRA_SID 2
#define XRA_IUC 3

extern int hf_xra_tlv_burst_info;
extern int hf_xra_tlv_burst_info_burst_id_reference;
extern int hf_xra_tlv_us_channel_id;
extern int hf_xra_tlv_sid;
extern int hf_xra_tlv_iuc;
extern int hf_xra_unknown;
extern int ett_xra_tlv_burst_info;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint8_t guint8;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define _U_ 

int tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
int proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, int encoding);
proto_item* proto_item_add_subtree(proto_item *it, int ett);
int tvb_captured_length(tvbuff_t *tvb);