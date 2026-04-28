#include <stdint.h>

#define TAG_RIC_DESCRIPTOR 0
#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof(arr[0]))
#define ENC_LITTLE_ENDIAN 0

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef uint32_t guint;

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;
typedef struct value_string_ext value_string_ext;

extern int hf_ieee80211_tag_ric_data_id;
extern int hf_ieee80211_tag_ric_data_desc_cnt;
extern int hf_ieee80211_tag_ric_data_status_code;
extern int ett_tag_ric_data_desc_ie;
extern expert_field ei_ieee80211_tag_length;
extern value_string_ext tag_num_vals_ext;

extern void expert_add_info_format(packet_info *pinfo, proto_item *ti, expert_field *ef, const char *fmt, ...);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
extern void proto_item_append_text(proto_item *ti, const char *format, ...);
extern const char *val_to_str_ext(guint32 val, const value_string_ext *vs, const char *fmt);
extern int add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int ftype, ...);