#include <stddef.h>

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff_t tvbuff_t;
struct _header_field_info {
    int display;
};

typedef struct _header_field_info header_field_info;

#define PROTO_REGISTRAR_GET_NTH(hfindex, hfinfo)
#define ENC_NA 0
#define STR_UNICODE 0
#define DISSECTOR_ASSERT(expr)
#define DISSECTOR_ASSERT_FIELD_TYPE_IS_STRING(hfinfo)
#define CHECK_FOR_NULL_TREE(tree)
#define TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hfinfo)
#define PNODE_FINFO(pi) ((header_field_info*)pi)

typedef int gint;
int g_utf8_validate(const char *str, gint max_len, const char **end);

void get_hfi_length(header_field_info *hfinfo, tvbuff_t *tvb, gint start, gint *length, gint *item_length, int enc);
void test_length(header_field_info *hfinfo, tvbuff_t *tvb, gint start, gint item_length, int enc);
proto_item* proto_tree_add_pi(proto_tree *tree, header_field_info *hfinfo, tvbuff_t *tvb, gint start, gint *length);
void proto_tree_set_string(header_field_info *hfinfo, const char* value);