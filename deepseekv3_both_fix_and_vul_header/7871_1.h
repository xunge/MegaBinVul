#include <stdint.h>

typedef int gint;
typedef unsigned int guint;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;

static int ett_mv_set_element;
static int ett_mv_set_value_list;
static int hf_mask_value_set_element_value_element_num;

#define NOTE_EATEN_LENGTH(length)
#define EAT(length)