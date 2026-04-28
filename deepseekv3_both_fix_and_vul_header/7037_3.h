#include <stdint.h>
#include <string.h>

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;
typedef char gchar;

#define ENC_ASCII 0

typedef struct {
    guint32 num_elements;
} dissection_info;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct wmem_allocator_t wmem_allocator_t;

extern int hf_rtps_type_object_bound;
extern int hf_rtps_type_object_enum_constant_value;
extern int hf_rtps_type_object_enum_constant_name;
extern int ett_rtps_type_enum_constant;

static int rtps_util_add_type_library_type(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, dissection_info *info);
static void rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, guint encoding, guint32 *member_id, guint32 *member_length);
static gint rtps_util_add_string(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_index, guint encoding);

/* Mock function declarations to satisfy compiler */
static wmem_allocator_t* wmem_packet_scope(void);
static guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding);
static gchar* tvb_get_string_enc(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length, guint encoding);
static void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint encoding);
static proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint start, gint length, int ett, void* data, const char *format, ...);
static void proto_item_set_len(void* item, gint length);