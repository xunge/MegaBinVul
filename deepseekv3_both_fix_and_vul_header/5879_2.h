#include <stdint.h>

typedef struct ptvcursor_t {
    void *tree;
    void *tvb;
    int offset;
} ptvcursor_t;

typedef struct field_info field_info;
typedef struct proto_item proto_item;

typedef struct header_field_info {
    int type;
} header_field_info;

typedef int gint;
typedef uint32_t guint32;
typedef unsigned int guint;

enum {
    FT_UINT_BYTES,
    FT_UINT_STRING
};

extern void PROTO_REGISTRAR_GET_NTH(int hfindex, header_field_info *hfinfo);
extern void get_hfi_length(header_field_info *hfinfo, void *tvb, int offset, gint *length, gint *item_length);
extern guint32 get_uint_value(void *tree, void *tvb, int offset, int length, const guint encoding);
extern field_info *new_field_info(void *tree, header_field_info *hfinfo, void *tvb, int offset, int item_length);
extern proto_item *proto_tree_new_item(field_info *new_fi, void *tree, void *tvb, int offset, int length, const guint encoding);
extern void TRY_TO_FAKE_THIS_ITEM(void *tree, int hfindex, header_field_info *hfinfo);