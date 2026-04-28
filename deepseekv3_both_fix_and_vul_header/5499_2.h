#include <stdint.h>

typedef uint32_t guint32;
typedef int32_t gint;

typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct expert_field expert_field;

struct value_string {
    guint32 value;
    const char *strptr;
};

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define ENC_ASCII 2

extern int proto_tnef;
extern int ett_tnef;
extern int ett_tnef_attribute;
extern int ett_tnef_attribute_tag;
extern int ett_tnef_mapi_props;
extern int ett_tnef_attribute_address;
extern int ett_tnef_attribute_date;

extern int hf_tnef_signature;
extern int hf_tnef_key;
extern int hf_tnef_attribute;
extern int hf_tnef_attribute_lvl;
extern int hf_tnef_attribute_tag;
extern int hf_tnef_attribute_tag_id;
extern int hf_tnef_attribute_tag_type;
extern int hf_tnef_attribute_length;
extern int hf_tnef_oem_codepage;
extern int hf_tnef_version;
extern int hf_tnef_message_class;
extern int hf_tnef_original_message_class;
extern int hf_tnef_mapi_props;
extern int hf_tnef_priority;
extern int hf_tnef_attribute_date;
extern int hf_tnef_attribute_string;
extern int hf_tnef_attribute_value;
extern int hf_tnef_attribute_checksum;
extern int hf_tnef_padding;

extern expert_field ei_tnef_incorrect_signature;

#define TNEF_SIGNATURE 0x223e9f78

enum {
    ATT_OEM_CODEPAGE,
    ATT_TNEF_VERSION,
    ATT_MESSAGE_CLASS,
    ATT_ORIGINAL_MESSAGE_CLASS,
    ATT_MAPI_PROPS,
    ATT_OWNER,
    ATT_SENT_FOR,
    ATT_PRIORITY
};

#define ATP_DATE 0x0003
#define ATP_STRING 0x0001

extern const struct value_string tnef_Attribute_vals[];

proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
guint32 tvb_get_letohl(tvbuff_t *tvb, gint offset);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, const char *fmt, ...);
void proto_item_append_text(proto_item *item, const char *format, ...);
gint tvb_reported_length_remaining(tvbuff_t *tvb, gint offset);
const char* val_to_str(guint32 value, const struct value_string *vs, const char *fmt);
tvbuff_t* tvb_new_subset_length(tvbuff_t *tvb, gint offset, gint length);
const char* tvb_get_string_enc(void *scope, tvbuff_t *tvb, gint offset, gint length, int encoding);
void* wmem_packet_scope(void);
void proto_item_set_len(proto_item *item, gint length);

void dissect_mapiprops(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
int dissect_counted_address(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree);
void dissect_DTR(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);