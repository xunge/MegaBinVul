#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define _U_ __attribute__((unused))

extern int hf_bzr_bytes;
extern int hf_bzr_bytes_length;
extern int hf_bzr_bytes_data;
extern int ett_prefixed_bytes;

guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *ti, int ett);