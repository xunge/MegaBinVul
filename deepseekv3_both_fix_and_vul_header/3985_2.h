#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Node GF_Node;
typedef struct GF_FieldInfo GF_FieldInfo;
typedef struct GenMFField GenMFField;
typedef struct GF_ChildNodeItem GF_ChildNodeItem;
typedef struct GF_BifsDecoder GF_BifsDecoder;

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_OTHER_ERROR
} GF_Err;

typedef enum {
    GF_SG_FIELD_CODING_IN,
    GF_SG_FIELD_CODING_OUT
} GF_SG_FieldCoding;

typedef enum {
    GF_SG_VRML_SFNODE,
    GF_SG_VRML_MFNODE,
    GF_SG_VRML_SFBOOL,
    GF_SG_VRML_MFBOOL,
    GF_SG_VRML_SFINT32,
    GF_SG_VRML_MFINT32,
    GF_SG_VRML_SFFLOAT,
    GF_SG_VRML_MFFLOAT,
    GF_SG_VRML_SFSTRING,
    GF_SG_VRML_MFSTRING,
    GF_SG_VRML_SFVEC2F,
    GF_SG_VRML_MFVEC2F,
    GF_SG_VRML_SFVEC3F,
    GF_SG_VRML_MFVEC3F,
    GF_SG_VRML_SFROTATION,
    GF_SG_VRML_MFROTATION,
    GF_SG_VRML_SFCOLOR,
    GF_SG_VRML_MFCOLOR,
    GF_SG_VRML_SFTIME,
    GF_SG_VRML_MFTIME,
    GF_SG_VRML_SFIMAGE,
    GF_SG_VRML_MFIMAGE,
    GF_SG_VRML_SFNODETYPE,
    GF_SG_VRML_MFNODETYPE
} GF_SG_VRMLFieldType;

typedef enum {
    GF_FALSE,
    GF_TRUE
} GF_Bool;

struct GenMFField {
    u32 count;
    void *far_ptr;
};

struct GF_FieldInfo {
    GF_SG_VRMLFieldType fieldType;
    u32 NDTtype;
    void *far_ptr;
};

struct GF_BifsDecoder {
    struct {
        struct {
            u32 NodeIDBits;
        } config;
    } *info;
    void *current_graph;
    GF_Err LastError;
};

u32 gf_get_bit_size(u32 val);
u32 gf_node_get_num_fields_in_mode(GF_Node *node, GF_SG_FieldCoding mode);
GF_Node *gf_sg_find_node(void *current_graph, u32 NodeID);
GF_Err gf_bifs_get_field_index(GF_Node *node, u32 ind, GF_SG_FieldCoding coding, u32 *field_ind);
GF_Err gf_node_get_field(GF_Node *node, u32 field_ind, GF_FieldInfo *field);
GF_Bool gf_sg_vrml_is_sf_field(GF_SG_VRMLFieldType fieldType);
GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
GF_Err gf_node_register(GF_Node *node, GF_Node *parent);
GF_Err gf_node_replace_child(GF_Node *node, GF_ChildNodeItem **far_ptr, u32 pos, GF_Node *new_node);
void gf_bifs_check_field_change(GF_Node *node, GF_FieldInfo *field);
GF_Err gf_sg_vrml_mf_get_item(void *far_ptr, GF_SG_VRMLFieldType fieldType, void **item, u32 pos);
GF_Err gf_bifs_dec_sf_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *field, GF_Bool skip);
GF_SG_VRMLFieldType gf_sg_vrml_get_sf_type(GF_SG_VRMLFieldType fieldType);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);