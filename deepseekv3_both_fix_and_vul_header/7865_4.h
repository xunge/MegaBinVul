#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint32_t guint;
typedef uint32_t guint32;

static int ett_alternate_mask_value_set;
static int hf_alt_assignment_mask_value_set_list_num_elements;

#define EAT(length) do { offset += (length); } while(0)
#define NOTE_EATEN_LENGTH(length) do { offset += (length); } while(0)

typedef struct tvbuff_t {
    unsigned char* data;
    size_t length;
} tvbuff_t;

typedef struct packet_info {
    // dummy implementation
} packet_info;

typedef struct proto_tree {
    // dummy implementation
} proto_tree;

typedef struct wccp_address_table {
    // dummy implementation
} wccp_address_table;

static inline guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset) {
    return (tvb->data[offset]<<24) | (tvb->data[offset+1]<<16) | 
           (tvb->data[offset+2]<<8) | tvb->data[offset+3];
}

static inline void proto_tree_add_uint(proto_tree *tree, int hfindex, 
                                     tvbuff_t *tvb, int offset, 
                                     int length, guint32 value) {
    // dummy implementation
}

static inline proto_tree* proto_tree_add_subtree(proto_tree *parent, 
                                               tvbuff_t *tvb, int offset, 
                                               int length, int ett, 
                                               void *null, const char *name) {
    // dummy implementation
    return parent;
}

extern gint dissect_wccp2_alternate_mask_value_set_element(tvbuff_t *tvb, int offset, 
                                                          int length, guint i, 
                                                          packet_info *pinfo, 
                                                          proto_tree *list_tree, 
                                                          wccp_address_table* addr_table);