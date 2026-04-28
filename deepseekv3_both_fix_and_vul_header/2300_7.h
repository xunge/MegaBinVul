#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint32_t guint32;

#define ENC_LITTLE_ENDIAN 0

struct mbim_pair_list {
    uint32_t offset;
    uint32_t size;
};

extern int hf_mbim_device_services_info_device_services_count;
extern int hf_mbim_device_services_info_max_dss_sessions;
extern int hf_mbim_device_services_info_device_services_offset;
extern int hf_mbim_device_services_info_device_services_size;
extern int ett_mbim_pair_list;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct wmem_array_t wmem_array_t;

void* wmem_packet_scope(void);
wmem_array_t* wmem_array_sized_new(void* scope, size_t elem_size, size_t count);
void wmem_array_append_one(wmem_array_t* array, const void* elem);
void* wmem_array_index(wmem_array_t* array, size_t index);

void proto_tree_add_item_ret_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding, guint32* retval);
void proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding);
proto_tree* proto_tree_add_subtree(proto_tree* tree, tvbuff_t* tvb, int start, int length, int ett, void* data, const char* text);
proto_tree* proto_tree_add_subtree_format(proto_tree* tree, tvbuff_t* tvb, int start, int length, int ett, void* data, const char* format, ...);

void mbim_dissect_device_service_element(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset);

#define wmem_array_append_one(array, item) wmem_array_append_one((array), &(item))