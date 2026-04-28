#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wccp_address_table wccp_address_table;

extern int ett_mv_set_list;
extern int hf_mask_value_set_list_num_elements;

#define EAT(x) offset += (x)
#define NOTE_EATEN_LENGTH(x) { length -= (x); offset += (x); }

enum {
    ENC_BIG_ENDIAN
};