#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef bool gboolean;

enum rlc_mode {
    RLC_UM
};

enum {
    ENC_NA,
    ENC_BIG_ENDIAN
};

struct rlc_li {
    guint16 li;
    guint16 len;
};

extern int hf_rlc_li;
extern int hf_rlc_li_value;
extern int hf_rlc_li_ext;
extern int hf_rlc_li_data;
extern int ett_rlc_frag;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff tvbuff_t;

static void add_description(proto_item *root_ti, proto_item *ti, const char *fmt, ...);
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
static proto_tree* proto_item_add_subtree(proto_item *ti, int ett);
static proto_item* proto_tree_add_bits_ret_val(proto_tree *tree, int hfindex, tvbuff_t *tvb, int bit_offset, int no_of_bits, guint64 *retval, int encoding);
static void proto_tree_add_bits_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int bit_offset, int no_of_bits, int encoding);
static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
static void PROTO_ITEM_SET_HIDDEN(proto_item *ti);