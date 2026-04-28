#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;

#define ENC_LITTLE_ENDIAN 0

struct mbim_pair_list {
    guint32 offset;
    guint32 size;
};

extern int hf_mbim_providers_elem_count;
extern int hf_mbim_providers_provider_offset;
extern int hf_mbim_providers_provider_size;
extern int ett_mbim_pair_list;

typedef struct wmem_array_t wmem_array_t;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

void* wmem_packet_scope(void);
wmem_array_t* wmem_array_sized_new(void* allocator, size_t elem_size, size_t init_size);
void wmem_array_append_one(wmem_array_t* array, const struct mbim_pair_list elem);
void* wmem_array_index(wmem_array_t* array, size_t index);

void proto_tree_add_item_ret_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding, guint32* retval);
proto_tree* proto_tree_add_subtree(proto_tree* parent_tree, tvbuff_t* tvb, int start, int length, int idx, const char* text, const char* name);
proto_tree* proto_tree_add_subtree_format(proto_tree* parent_tree, tvbuff_t* tvb, int start, int length, int idx, const char* text, const char* format, ...);

void mbim_dissect_provider(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, gint offset);