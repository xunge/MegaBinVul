#include <stdint.h>

#define EAT(x) offset += (x); length -= (x)
#define NOTE_EATEN_LENGTH(x) offset += (x); length -= (x)

#define ROUTER_VIEW_INFO_MIN_LEN 4

typedef int32_t gint;
typedef uint32_t guint32;
typedef unsigned int guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;

extern int hf_router_view_member_change_num;
extern int hf_router_router_num;
extern int hf_router_view_ip_index;
extern int hf_router_view_ipv4;
extern int hf_router_view_ipv6;
extern int hf_wc_view_wc_num;
extern int hf_router_query_info_ip_index;
extern int hf_router_query_info_ipv4;
extern int hf_router_query_info_ipv6;
extern int ett_wc_identity_element;

#define ENC_BIG_ENDIAN 0

gint dissect_wccp2_assignment_key_element(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);
gint dissect_wccp2_web_cache_identity_element(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *element_tree, wccp_address_table* addr_table);
proto_item* wccp_add_ipaddress_item(proto_tree *tree, int index_hf, int ipv4_hf, int ipv6_hf, tvbuff_t *tvb, int offset, int length, wccp_address_table* addr_table);
uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
proto_tree *proto_item_add_subtree(proto_item *item, int tree_type);