#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;

typedef struct packet_info {
    int dummy; 
} packet_info;

typedef struct proto_item {
    int dummy;
} proto_item;

typedef struct proto_tree {
    int dummy;
} proto_tree;

typedef struct dissector_handle_t {
    int dummy;
} dissector_handle_t;

typedef struct value_string_ext {
    int dummy;
} value_string_ext;

extern int ett_ui;
extern value_string_ext xid_param_type_str_ext;
extern dissector_handle_t* sndcp_xid_handle;
extern int hf_llcgprs_xid_xl;
extern int hf_llcgprs_xid_type;
extern int hf_llcgprs_xid_len1;
extern int hf_llcgprs_xid_len2;
extern int hf_llcgprs_xid_spare;
extern int hf_llcgprs_xid_byte;

guint16 tvb_reported_length(tvbuff_t *tvb);
proto_tree* proto_tree_add_subtree_format(proto_tree *parent, tvbuff_t *tvb, int start, int length, int ett, int *idx, const char *label, ...);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
proto_tree* proto_tree_add_subtree(proto_tree *parent, tvbuff_t *tvb, int start, int length, int ett, int *idx, const char *label);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
tvbuff_t* tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
void call_dissector(dissector_handle_t *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
const char* val_to_str_ext_const(guint32 value, const value_string_ext *vs, const char *default_str);