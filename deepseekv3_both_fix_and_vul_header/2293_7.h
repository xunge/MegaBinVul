#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;

#define ENC_LITTLE_ENDIAN 0

struct mbim_pair_list {
    uint32_t offset;
    uint32_t size;
};

extern int hf_mbim_device_service_subscribe_element_count;
extern int hf_mbim_device_service_subscribe_device_service_offset;
extern int hf_mbim_device_service_subscribe_device_service_size;
extern int ett_mbim_pair_list;

typedef struct wmem_array_t wmem_array_t;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

void* wmem_packet_scope(void);
wmem_array_t* wmem_array_sized_new(void* allocator, size_t element_size, size_t count);
void wmem_array_append_one(wmem_array_t* array, const void* element);
void* wmem_array_index(wmem_array_t* array, size_t index);

proto_tree* proto_tree_add_subtree(proto_tree* tree, tvbuff_t* tvb, gint start, gint length, int idx, void* null, const char* text);
proto_tree* proto_tree_add_subtree_format(proto_tree* tree, tvbuff_t* tvb, gint start, gint length, int idx, void* null, const char* fmt, ...);
void proto_tree_add_item_ret_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, int encoding, guint32* retval);

void mbim_dissect_event_entry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset);

#define wmem_array_append_one(array, item) wmem_array_append_one(array, (const void*)&(item))