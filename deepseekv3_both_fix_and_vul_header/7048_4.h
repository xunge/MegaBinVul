#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;

typedef struct dissection_info {
    int32_t base_type_id;
    int32_t bound;
    int32_t num_elements;
} dissection_info;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

extern int hf_rtps_type_object_element_shared;
extern int hf_rtps_type_object_bound;
extern int ett_rtps_type_bound_list;

extern gint rtps_util_add_type_library_type(proto_tree *tree, tvbuff_t *tvb, gint offset, const guint encoding, dissection_info *info);
extern void rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, const guint encoding, guint32 *member_id, guint32 *member_length);
extern void rtps_util_add_type_id(proto_tree *tree, tvbuff_t *tvb, gint offset, const guint encoding, gint zero_alignment, gint array_size, const char *label, int32_t *base_type_id);
extern guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding);
extern int32_t tvb_get_gint32(tvbuff_t *tvb, gint offset, guint encoding);
extern proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, int ett, void *null, const char *format, ...);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, gint length, guint encoding);

#define _U_