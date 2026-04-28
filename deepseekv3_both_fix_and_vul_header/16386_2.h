#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff tvbuff_t;

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef uint64_t guint64;
typedef int32_t gint32;
typedef int64_t gint64;
typedef unsigned int guint;
typedef int gint;
typedef bool gboolean;

#define TRUE true
#define FALSE false

typedef struct {
    const char *abbrev;
    const char *name;
    int type;
    guint32 bitmask;
    void *strings;
} header_field_info;

typedef struct {
    const char *true_string;
    const char *false_string;
} true_false_string;

#define ITEM_LABEL_LENGTH 256
#define PROTO_REGISTRAR_GET_NTH(hfindex, hf_field)
#define REPORT_DISSECTOR_BUG(msg, ...)
#define CHECK_FOR_NULL_TREE(tree)
#define TRY_TO_FAKE_THIS_ITEM(tree, hfindex, hf_field)
#define PITEM_FINFO(pi) ((header_field_info *)pi)

enum {
    FT_BOOLEAN,
    FT_CHAR,
    FT_UINT8,
    FT_UINT16,
    FT_UINT24,
    FT_UINT32,
    FT_INT8,
    FT_INT16,
    FT_INT24,
    FT_INT32,
    FT_UINT40,
    FT_UINT48,
    FT_UINT56,
    FT_UINT64,
    FT_INT40,
    FT_INT48,
    FT_INT56,
    FT_INT64,
    FT_BYTES
};

extern const true_false_string tfs_true_false;

guint64 tvb_get_bits64(tvbuff_t *tvb, guint bit_offset, gint no_of_bits, guint encoding);
guint8 *tvb_get_bits_array(void *ptr, tvbuff_t *tvb, guint bit_offset, gint no_of_bits, size_t *bytes_length);
char *decode_bits_in_field(guint bit_offset, gint no_of_bits, guint64 value);
void fill_label_char(header_field_info *hfinfo, char *label_str);
void fill_label_number(header_field_info *hfinfo, char *label_str, gboolean is_signed);
void fill_label_number64(header_field_info *hfinfo, char *label_str, gboolean is_signed);
void proto_item_fill_label(header_field_info *hfinfo, char *label_str);
void proto_item_set_text(proto_item *pi, const char *format, ...);
const char *tfs_get_string(gboolean value, const true_false_string *tfstring);
const char *ftype_name(int ftype);
guint64 ws_sign_ext64(guint64 value, gint no_of_bits);
proto_item *proto_tree_add_boolean_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, guint length, guint32 value, const char *format, ...);
proto_item *proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, guint length, guint32 value);
proto_item *proto_tree_add_int(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, guint length, gint32 value);
proto_item *proto_tree_add_uint64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, guint length, guint64 value);
proto_item *proto_tree_add_int64(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, guint length, gint64 value);
proto_item *proto_tree_add_bytes_with_length(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, guint length, guint8 *bytes, gint bytes_length);