#include <stdint.h>
#include <stddef.h>

#define BGP_MARKER_SIZE 16
#define BGP_HEADER_SIZE 19

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint16_t guint16;
typedef int gint;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;

extern int hf_bgp_update_withdrawn_routes_length;
extern int hf_bgp_update_withdrawn_routes;
extern int hf_bgp_nlri_path_id;
extern int hf_bgp_withdrawn_prefix;
extern int hf_bgp_update_total_path_attribute_length;
extern int hf_bgp_update_path_attributes;
extern int hf_bgp_update_nlri;
extern int hf_bgp_nlri_prefix;
extern int ett_bgp_unfeas;
extern int ett_bgp_attrs;
extern int ett_bgp_nlri;

guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *ti, int subtree_index);

int detect_add_path_prefix4(tvbuff_t *tvb, gint o, gint end);
int decode_path_prefix4(proto_tree *subtree, packet_info *pinfo, int hf_path_id, int hf_prefix, tvbuff_t *tvb, gint o, const char *label);
int decode_prefix4(proto_tree *subtree, packet_info *pinfo, void *null, int hf_prefix, tvbuff_t *tvb, gint o, const char *label);
void dissect_bgp_path_attr(proto_tree *subtree, tvbuff_t *tvb, guint16 len, gint o, packet_info *pinfo);