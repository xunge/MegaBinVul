#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define _U_ __attribute__((unused))

enum {
    COL_PROTOCOL,
    COL_INFO
};

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct {
        int COL_PROTOCOL;
        int COL_INFO;
    } *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct value_string_ext value_string_ext;
typedef struct expert_field expert_field;

extern int proto_ieee1905;
extern int ett_ieee1905;
extern int ett_ieee1905_flags;
extern int ett_tlv;
extern int hf_ieee1905_message_version;
extern int hf_ieee1905_message_reserved;
extern int hf_ieee1905_message_type;
extern int hf_ieee1905_message_id;
extern int hf_ieee1905_fragment_id;
extern int hf_ieee1905_flags;
extern int hf_ieee1905_last_fragment;
extern int hf_ieee1905_relay_indicator;
extern int hf_ieee1905_tlv_types;
extern int hf_ieee1905_tlv_len;
extern int hf_ieee1905_data;
extern expert_field ei_ieee1905_extraneous_data_after_eom;
extern value_string_ext ieee1905_message_type_vals_ext;
extern value_string_ext ieee1905_tlv_types_vals_ext;

#define EOM_TLV 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

void col_set_str(void*, int, const char*);
void col_clear(void*, int);
const char* val_to_str_ext(guint16, const value_string_ext*, const char*);
proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
proto_tree* proto_item_add_subtree(proto_item*, int);
void proto_tree_add_bitmask(proto_tree*, tvbuff_t*, int, int, int, const int**, int);
proto_tree* proto_tree_add_subtree(proto_tree*, tvbuff_t*, int, int, int, void*, const char*);
void expert_add_info(packet_info*, proto_item*, expert_field*);

guint16 tvb_get_ntohs(tvbuff_t*, int);
guint8 tvb_get_guint8(tvbuff_t*, int);
int tvb_reported_length_remaining(tvbuff_t*, int);
int tvb_captured_length(tvbuff_t*);

static int dissect_ieee1905_tlv_data(tvbuff_t*, packet_info*, proto_tree*, guint, guint8, guint16);