#include <stdint.h>
#include <string.h>
#include <inttypes.h>

typedef struct {
    char member_name[256];
    uint64_t member_type_id;
    int32_t discriminator;
    uint64_t union_type_id;
} union_member_mapping;

typedef struct {
    unsigned int flags;
    char member_name[256];
    uint64_t type_id;
} dissection_element;

typedef struct {
    // Add necessary fields here
} dissection_info;

extern int ett_rtps_type_enum_constant;
extern int hf_rtps_type_object_union_label;
extern void* union_member_mappings;

#define PID_LIST_END 0x80000000
#define HASHMAP_DISCRIMINATOR_CONSTANT 0

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef int gboolean;
typedef struct _proto_tree proto_tree;
typedef struct _tvbuff_t tvbuff_t;
typedef struct _proto_item proto_item;

gint rtps_util_add_type_member(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, void *null, dissection_element *object);
void rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, guint encoding, guint32 *member_id, guint32 *member_length);
guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding);
proto_item* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint offset, guint length, int ett, void *null, const char *format, ...);
void* wmem_new(void *scope, size_t size);
void* wmem_file_scope(void);
size_t g_strlcpy(char *dest, const char *src, size_t dest_size);
void wmem_map_insert(void *map, const void *key, void *value);
void proto_item_append_text(proto_item *item, const char *format, ...);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint encoding);

#define _U_

#define wmem_new(scope, type) ((type*)malloc(sizeof(type)))