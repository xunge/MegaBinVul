#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;

static gint ett_alternate_mask_value_set_element;
static gint ett_alternate_mv_set_element_list;
static gint hf_alt_assignment_mask_value_set_element_num_wc_value_elements;

#define NOTE_EATEN_LENGTH(length)
#define EAT(length)