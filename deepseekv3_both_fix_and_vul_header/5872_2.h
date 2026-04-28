#include <stdint.h>

typedef int32_t gint;
typedef uint8_t guint8;
typedef uint64_t guint64;

typedef struct {
    guint8 offset;
    guint8 li;
} length_indicator_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

#define ENC_BIG_ENDIAN 0

extern int hf_li;
extern int hf_e;
extern expert_field ei_li;

gint proto_tree_add_bits_item(proto_tree *tree, int hf, tvbuff_t *tvb, int bit_offset, int no_of_bits, int encoding);
gint proto_tree_add_bits_ret_val(proto_tree *tree, int hf, tvbuff_t *tvb, int bit_offset, int no_of_bits, guint64 *retval, int encoding);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);