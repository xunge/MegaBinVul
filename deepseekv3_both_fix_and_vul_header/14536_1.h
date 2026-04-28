#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Node GF_Node;
typedef struct GF_ChildNodeItem GF_ChildNodeItem;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct GF_FieldInfo GF_FieldInfo;

#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_TRUE 1
#define GF_FALSE 0

enum {
    GF_SG_FIELD_CODING_IN,
    GF_SG_VRML_SFNODE,
    GF_SG_VRML_MFNODE
};

struct GF_InfoConfig {
    u32 NodeIDBits;
};

struct GF_Info {
    struct GF_InfoConfig config;
};

struct GF_BifsDecoder {
    struct GF_Info *info;
    u32 is_com_dec;
    GF_Node *current_graph;
};

struct GF_FieldInfo {
    u32 fieldType;
    void *far_ptr;
};

u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
GF_Node *gf_sg_find_node(GF_Node *graph, u32 NodeID);
u32 gf_get_bit_size(u32 num);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, u32 mode);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 ind, u32 codingMode, u32 *field_ind);
GF_Err gf_node_get_field(GF_Node *node, u32 field_ind, GF_FieldInfo *field);
int gf_sg_vrml_is_sf_field(u32 fieldType);
void gf_sg_vrml_mf_reset(void *ptr, u32 fieldType);
GF_Err gf_bifs_dec_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field, int flag);
GF_Err gf_node_unregister(GF_Node *node, GF_Node *parent);
void gf_node_unregister_children(GF_Node *node, GF_ChildNodeItem *child);
void gf_bifs_check_field_change(GF_Node *node, GF_FieldInfo *field);