#include <stdarg.h>

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff_t tvbuff_t;
typedef struct _header_field_info header_field_info;
typedef int gint;

#define CHECK_FOR_NULL_TREE(tree)
#define TRY_TO_FAKE_THIS_ITEM(tree, hf_text_only, hfinfo)
#define TRY_TO_FAKE_THIS_REPR(pi)
#define hf_text_only 0

void proto_tree_set_representation(proto_item *pi, const char *format, va_list ap);
proto_item *proto_tree_add_text_node(proto_tree *tree, tvbuff_t *tvb, gint start, gint length);