#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define CBOR_TYPE_TEXT_STRING 3
#define CBOR_MAX_RECURSION_DEPTH 64
#define G_MAXINT32 2147483647
#define TRUE true
#define FALSE false
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ENC_UTF_8 2

typedef bool gboolean;
typedef int8_t gint8;
typedef uint8_t guint8;
typedef int32_t gint;
typedef int32_t gint32;
typedef uint64_t guint64;

typedef struct tvbuff_t {
    unsigned char *data;
    size_t length;
} tvbuff_t;

typedef struct packet_info {
    void *pool;
} packet_info;

typedef struct proto_tree {
    int dummy;
} proto_tree;

typedef struct proto_item {
    int dummy;
} proto_item;

typedef struct expert_field {
    int dummy;
} expert_field;

extern int proto_cbor;
extern int hf_cbor_item_text_string;
extern int hf_cbor_item_major_type;
extern int hf_cbor_item_length5;
extern int hf_cbor_item_length_size;
extern int hf_cbor_item_length;
extern int hf_cbor_type_text_string_indef;
extern int hf_cbor_type_text_string;
extern int ett_cbor_text_string;
extern int ett_cbor_text_string_indef;
extern expert_field ei_cbor_invalid_element;
extern expert_field ei_cbor_invalid_minor_type;
extern expert_field ei_cbor_too_long_length;
extern expert_field ei_cbor_max_recursion_depth_reached;

static int proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding);
static proto_tree* proto_item_add_subtree(proto_item *item, int ett);
static int proto_tree_add_item_ret_uint64(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding, guint64 *retval);
static void proto_item_append_text(proto_item *item, const char *format, ...);
static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
static void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);
static void expert_add_info_format(packet_info *pinfo, proto_tree *tree, expert_field *ei, const char *format, ...);
static void DISSECTOR_ASSERT_NOT_REACHED(void);
static int proto_tree_add_item_ret_string(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding, void *pool, const guint8 **retval);
static unsigned p_get_proto_depth(packet_info *pinfo, int proto);
static void p_set_proto_depth(packet_info *pinfo, int proto, unsigned depth);
static gboolean dissect_cbor_float_simple_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset, guint8 type_minor);