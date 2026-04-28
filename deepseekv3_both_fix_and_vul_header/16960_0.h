#include <stdint.h>
#include <inttypes.h>

#define CBOR_TYPE_BYTE_STRING 2
#define G_MAXINT32 2147483647
#define TRUE 1
#define FALSE 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0
#define CBOR_MAX_RECURSION_DEPTH 64
#define DISSECTOR_ASSERT_NOT_REACHED() 

typedef int gboolean;
typedef int gint;
typedef uint8_t guint8;
typedef uint64_t guint64;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_cbor_item_byte_string;
extern int hf_cbor_item_major_type;
extern int hf_cbor_item_length5;
extern int hf_cbor_item_length_size;
extern int hf_cbor_item_length;
extern int hf_cbor_type_byte_string_indef;
extern int hf_cbor_type_byte_string;
extern int ett_cbor_byte_string;
extern int ett_cbor_byte_string_indef;
extern expert_field ei_cbor_invalid_element;
extern expert_field ei_cbor_invalid_minor_type;
extern expert_field ei_cbor_too_long_length;
extern expert_field ei_cbor_max_recursion_depth_reached;
extern int proto_cbor;

extern gboolean dissect_cbor_float_simple_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset, guint8 type_minor);
extern proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_tree* proto_item_add_subtree(proto_item *item, int ett);
extern void proto_tree_add_item_ret_uint64(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, guint64 *retval);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern void expert_add_info_format(packet_info *pinfo, proto_tree *tree, expert_field *expert, const char *format, ...);
extern const char *plurality(guint64 count, const char *singular, const char *plural);
extern void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *expert, tvbuff_t *tvb, int start, int length);
extern unsigned p_get_proto_depth(packet_info *pinfo, int proto);
extern void p_set_proto_depth(packet_info *pinfo, int proto, unsigned depth);