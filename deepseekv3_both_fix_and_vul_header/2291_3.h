#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;
typedef void tvbuff_t;
typedef void packet_info;
typedef void proto_tree;
typedef void wmem_array_t;

#define ENC_LITTLE_ENDIAN 0

struct mbim_pair_list {
    uint32_t offset;
    uint32_t size;
};

extern int hf_mbim_atds_operators_elem_count;
extern int hf_mbim_atds_operators_operator_offset;
extern int hf_mbim_atds_operators_operator_size;
extern int ett_mbim_pair_list;

void mbim_dissect_atds_operator(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset);
void* wmem_array_sized_new(void* scope, size_t elem_size, size_t count);
void* wmem_packet_scope(void);
void wmem_array_append_one(wmem_array_t* array, struct mbim_pair_list item);
void* wmem_array_index(wmem_array_t* array, size_t index);
proto_tree* proto_tree_add_subtree(proto_tree* tree, tvbuff_t* tvb, int offset, int length, int ett, void* null, const char* name);
proto_tree* proto_tree_add_subtree_format(proto_tree* tree, tvbuff_t* tvb, int offset, int length, int ett, void* null, const char* format, ...);
void proto_tree_add_item_ret_uint(proto_tree* tree, int hf, tvbuff_t* tvb, int offset, int length, int encoding, guint32* retval);