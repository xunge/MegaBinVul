#include <stdarg.h>

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;
typedef struct header_field_info header_field_info;
typedef int gint;

extern int hf_text_only;

#define CHECK_FOR_NULL_TREE(tree)
#define TRY_TO_FAKE_THIS_ITEM(tree, hf, hfinfo)
#define TRY_TO_FAKE_THIS_REPR(pi)

proto_item *proto_tree_add_text_node(proto_tree *tree, tvbuff_t *tvb, gint start, gint length);
void proto_tree_set_representation(proto_item *pi, const char *format, va_list ap);