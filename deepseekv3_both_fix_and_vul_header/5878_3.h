#include <stdint.h>
#include <stddef.h>

typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;

typedef struct field_info {
    int dummy;
} field_info;

typedef struct header_field_info {
    int type;
} header_field_info;

typedef struct ptvcursor_t {
    proto_tree *tree;
    tvbuff_t *tvb;
    int offset;
} ptvcursor_t;

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;

#define FT_UINT_BYTES 1
#define FT_UINT_STRING 2

#define PROTO_REGISTRAR_GET_NTH(x, y) (y = NULL)
#define TRY_TO_FAKE_THIS_ITEM(a, b, c) 
#define get_hfi_length(a, b, c, d, e) 
#define get_uint_value(a, b, c, d, e) 0
#define test_length(a, b, c, d) 
#define new_field_info(a, b, c, d, e) NULL
#define proto_tree_new_item(a, b, c, d, e, f) NULL