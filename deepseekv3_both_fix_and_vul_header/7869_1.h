#include <stdint.h>

typedef int32_t gint;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;

extern int ett_mask_assignment_data_element;
extern int dissect_wccp2_mask_value_set_list(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *tree, wccp_address_table* addr_table);
extern int dissect_wccp2_assignment_weight_and_status_element(tvbuff_t *tvb, int offset, gint length, packet_info *pinfo, proto_tree *tree);
#define NOTE_EATEN_LENGTH(length)