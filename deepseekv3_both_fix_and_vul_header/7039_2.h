#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef char gchar;

#define ENC_ASCII 0

typedef struct {
    int extensibility;
    gchar member_name[256];
    gint type_id;
} dissection_info;

enum {
    EXTENSIBILITY_MUTABLE,
    EXTENSIBILITY_FINAL,
    EXTENSIBILITY_EXTENSIBLE
};

extern int hf_rtps_type_object_flags;
extern int ett_rtps_flags;
extern int hf_rtps_type_object_type_property_name;
extern int ett_rtps_type_annotation_usage_list;

static const int *TYPE_FLAG_FLAGS[] = { NULL };

struct proto_tree;
struct tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

static void* wmem_packet_scope(void) { return NULL; }
static size_t g_strlcpy(char *dest, const char *src, size_t size) { return strlcpy(dest, src, size); }

static gint rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, const guint encoding, guint32 *member_id, guint32 *member_length);
static gint rtps_util_add_type_id(proto_tree *tree, tvbuff_t *tvb, gint offset, const guint encoding, gint base_offset, gint length, proto_tree *parent_tree, gint *type_id);
static void rtps_util_add_string(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_index, const guint encoding);
static gint rtps_util_add_type_annotation_usage(proto_tree *tree, tvbuff_t *tvb, gint offset, const guint encoding, gint base_offset);

static guint16 tvb_get_guint16(tvbuff_t *tvb, gint offset, guint encoding) { return 0; }
static guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding) { return 0; }
static char* tvb_get_string_enc(void *scope, tvbuff_t *tvb, gint offset, guint32 length, int encoding) { return NULL; }
static void proto_tree_add_bitmask_value(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_index, int ett, const int **fields, guint16 value) {}
static void proto_item_append_text(proto_tree *tree, const char *format, ...) {}
static proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint offset, guint32 length, int ett, void *null, const char *format, ...) { return NULL; }