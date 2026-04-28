#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;

static int ett_alternate_mask_value_set_element;
static int ett_alternate_mv_set_element_list;
static int hf_alt_assignment_mask_value_set_element_num_wc_value_elements;

#define NOTE_EATEN_LENGTH(len)
#define EAT(len)