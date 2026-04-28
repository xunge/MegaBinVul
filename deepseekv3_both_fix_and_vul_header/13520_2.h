extern int proto_ncp;
extern int ett_ncp;
extern int hf_ncp_crc;

typedef unsigned short guint16;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff tvbuff_t;

#define ENC_NA 0
#define _U_

static void dissect_ncp_message_block(tvbuff_t *tvb, proto_tree *tree);
proto_item* proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int length, const char *format);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
tvbuff_t* tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, int encoding);
int tvb_captured_length(tvbuff_t *tvb);