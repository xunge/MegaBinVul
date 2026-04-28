#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef unsigned int u32;
typedef signed int s32;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct GF_List GF_List;
typedef struct GF_Command GF_Command;
typedef struct GF_Node GF_Node;
typedef struct GF_FieldInfo GF_FieldInfo;
typedef struct GF_CommandField GF_CommandField;
typedef struct GenMFField {
    u32 count;
} GenMFField;

#define GF_NON_COMPLIANT_BITSTREAM 0
#define GF_SG_FIELD_CODING_IN 0
#define GF_SG_INDEXED_REPLACE 0
#define GF_SG_VRML_MFNODE 0
#define GF_SG_VRML_SFNODE 0
#define GF_TRUE 1

struct GF_BifsDecoder {
    GF_Err LastError;
    struct {
        struct {
            u32 NodeIDBits;
        } config;
    } *info;
    GF_Node *current_graph;
};

struct GF_FieldInfo {
    u32 fieldType;
    u32 fieldIndex;
    void *far_ptr;
    u32 NDTtype;
};

struct GF_CommandField {
    u32 fieldType;
    u32 fieldIndex;
    s32 pos;
    void *field_ptr;
    GF_Node *new_node;
};

u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
GF_Node *gf_sg_find_node(GF_Node *graph, u32 NodeID);
u32 gf_get_bit_size(u32 val);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, u32 mode);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 ind, u32 codingMode, u32 *field_ind);
GF_Err gf_node_get_field(GF_Node *node, u32 field_ind, GF_FieldInfo *field);
u32 gf_sg_vrml_is_sf_field(u32 fieldType);
GF_Command *gf_sg_command_new(GF_Node *graph, u32 commandType);
void BM_SetCommandNode(GF_Command *com, GF_Node *node);
GF_CommandField *gf_sg_command_field_new(GF_Command *com);
GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
void gf_node_register(GF_Node *node, void *ptr);
u32 gf_sg_vrml_get_sf_type(u32 fieldType);
void *gf_sg_vrml_field_pointer_new(u32 fieldType);
GF_Err gf_bifs_dec_sf_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field, u32 flag);
void gf_list_add(GF_List *list, void *item);