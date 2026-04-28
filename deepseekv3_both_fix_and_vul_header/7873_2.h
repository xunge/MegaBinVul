#include <stdint.h>
#include <stddef.h>

#define ALT_ASSIGNMENT_INFO_MIN_LEN 0
#define WCCP2_HASH_ASSIGNMENT_TYPE 0
#define WCCP2_MASK_ASSIGNMENT_TYPE 1
#define WCCP2r1_ALT_MASK_ASSIGNMENT_TYPE 2

#define ENC_BIG_ENDIAN 0

#define EAT_AND_CHECK(a,b)
#define EAT(a)
#define NOTE_EATEN_LENGTH(a)

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;
typedef struct expert_field expert_field;

extern int hf_alt_assignment_info_assignment_type;
extern int hf_alt_assignment_info_assignment_length;
extern int hf_alt_assignment_info_num_routers;
extern int ett_router_alt_assignment_element;
extern expert_field ei_wccp_assignment_length_bad;

guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
proto_tree* proto_tree_add_subtree_format(proto_tree *parent_tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *format, ...);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, const char *fmt, ...);

gint dissect_wccp2_assignment_key_element(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);
gint dissect_wccp2_router_assignment_element(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);
gint dissect_wccp2_hash_assignment_info(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);
gint dissect_wccp2_mask_value_set_list(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);
gint dissect_wccp2_alternate_mask_value_set_list(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);
char* decode_wccp_encoded_address(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *info_tree, wccp_address_table* addr_table);