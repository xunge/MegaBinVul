#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define PID_LIST_END 0x80000000
#define EXTENSIBILITY_INVALID 0

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;
typedef int64_t gint64;
typedef uint64_t guint64;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;

typedef struct dissection_info {
    guint64 base_type_id;
    guint64 type_id;
} dissection_info;

typedef struct mutable_member_mapping {
    guint64 member_type_id;
    const char *member_name;
    guint64 member_id;
} mutable_member_mapping;

extern void* wmem_map_lookup(void* map, const void* key);
extern proto_item* proto_tree_add_subtree_format(proto_tree *parent_tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *format, ...);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern void proto_item_set_hidden(proto_item *item);
extern void rtps_util_dissect_parameter_header(tvbuff_t *tvb, int *offset, guint encoding, guint32 *member_id, guint32 *member_length);
extern void dissect_user_defined(proto_tree *tree, tvbuff_t *tvb, int offset, guint encoding, guint encoding_version, void *data, guint64 type_id, const char *name, int extensibility, int start, int length, guint64 member_id, gboolean show);

extern void* mutable_member_mappings;
extern int ett_rtps_dissection_tree;