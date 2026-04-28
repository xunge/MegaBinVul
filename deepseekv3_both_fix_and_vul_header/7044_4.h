#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct dissection_info dissection_info;

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;

extern int hf_rtps_type_object_element_shared;
extern int hf_rtps_type_object_bound;
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint encoding);

extern int rtps_util_add_type_library_type(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, dissection_info *info);
extern void rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, guint encoding, guint32 *member_id, guint32 *member_length);
extern void rtps_util_add_type_id(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, gint zero_alignment, gint length, const char *prefix, const char *suffix);