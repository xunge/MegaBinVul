#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef guint32 guint;
typedef char gchar;

#define ENC_ASCII 0

typedef struct {
    guint32 extensibility;
    gchar member_name[256];
    gint type_id;
} dissection_info;

enum {
    EXTENSIBILITY_MUTABLE,
    EXTENSIBILITY_FINAL,
    EXTENSIBILITY_EXTENSIBLE
};

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

extern int hf_rtps_type_object_flags;
extern int ett_rtps_flags;
extern int ett_rtps_type_annotation_usage_list;
extern int hf_rtps_type_object_type_property_name;

static const int *TYPE_FLAG_FLAGS[] = { NULL };

static gint rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, guint encoding, guint32 *member_id, guint32 *member_length);
static gint rtps_util_add_type_id(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, gint base_offset, gint hf_index, proto_tree *parent_tree, gint *type_id);
static void rtps_util_add_string(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_index, guint encoding);
static gint rtps_util_add_type_annotation_usage(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, gint base_offset);
static gint check_offset_addition(gint offset, guint32 length, proto_tree *tree, void *item, tvbuff_t *tvb);

void *wmem_packet_scope();
gchar *tvb_get_string_enc(void *scope, tvbuff_t *tvb, gint offset, gint length, int enc);
guint16 tvb_get_guint16(tvbuff_t *tvb, gint offset, guint encoding);
guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding);
void proto_tree_add_bitmask_value(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_index, int ett, const int *const *fields, guint16 value);
proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, int ett, void *null, const char *format, ...);
void proto_item_append_text(void *tree, const char *format, ...);
size_t g_strlcpy(gchar *dest, const gchar *src, size_t dest_size);