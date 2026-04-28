#include <stdint.h>

#define _U_
#define ENC_BIG_ENDIAN 0
typedef uint32_t guint32;

extern int ett_thrift;
extern int hf_thrift_type; 
extern int hf_thrift_num_list_item;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

int dissect_thrift_type_v1(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, proto_item* type_pi, guint32 type, int* offset, int length);
int dissect_thrift_type_v2(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint32 type, int offset, int length);

proto_tree* proto_tree_add_subtree(proto_tree* tree, tvbuff_t* tvb, int offset, int length, int ett, proto_item** ti, const char* text);
proto_item* proto_tree_add_item_ret_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, int offset, int length, int encoding, guint32* retval);
void proto_item_set_len(proto_item* ti, int length);