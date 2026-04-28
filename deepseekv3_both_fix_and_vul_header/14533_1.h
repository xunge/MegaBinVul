#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef int32_t GF_Err;

#define GF_NON_COMPLIANT_BITSTREAM (-1)
#define GF_TRUE 1
#define GF_FALSE 0

typedef enum {
    GF_SG_VRML_MFNODE,
} GF_FieldType;

typedef enum {
    GF_SG_FIELD_CODING_IN,
} GF_FieldCodingMode;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Node GF_Node;
typedef struct GF_ChildNodeItem GF_ChildNodeItem;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct GF_FieldInfo GF_FieldInfo;

struct GF_FieldInfo {
    GF_FieldType fieldType;
    void* far_ptr;
};

struct GF_BifsDecoder {
    GF_BitStream* current_graph;
    struct {
        struct {
            u32 NodeIDBits;
        } config;
    } *info;
    int is_com_dec;
};

u32 gf_bs_read_int(GF_BitStream* bs, u32 numBits);
GF_Node* gf_sg_find_node(void* current_graph, u32 NodeID);
u32 gf_get_bit_size(u32 num);
u32 gf_node_get_num_fields_in_mode(GF_Node* node, GF_FieldCodingMode mode);
GF_Err gf_bifs_get_field_index(GF_Node* node, u32 ind, GF_FieldCodingMode coding, u32* field_ind);
GF_Err gf_node_get_field(GF_Node* node, u32 field_ind, GF_FieldInfo* field);
int gf_sg_vrml_is_sf_field(GF_FieldType fieldType);
GF_Err gf_sg_vrml_mf_reset(void* far_ptr, GF_FieldType fieldType);
GF_Err gf_bifs_dec_field(GF_BifsDecoder* codec, GF_BitStream* bs, GF_Node* node, GF_FieldInfo* field, int flag);
void gf_node_unregister_children(GF_Node* node, GF_ChildNodeItem* prev_child);
void gf_bifs_check_field_change(GF_Node* node, GF_FieldInfo* field);