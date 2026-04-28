#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned int u32;

#define GF_FALSE 0
#define GF_TRUE 1

#define TAG_MPEG4_QuantizationParameter 42

typedef enum {
    GF_OK,
    GF_SG_VRML_MFNODE
} GF_Err;

typedef struct {
    u32 fieldIndex;
    u32 fieldType;
    u32 NDTtype;
    char *name;
    void *far_ptr;
} GF_FieldInfo;

typedef struct {
    GF_Err LastError;
    Bool ActiveQP;
    Bool force_keep_qp;
    void *pCurrentProto;
} GF_BifsDecoder;

typedef struct {
    void *bs;
} GF_BitStream;

typedef struct {
    u32 tag;
} GF_Node;

typedef struct {
    GF_Node *node;
} GF_ChildNodeItem;

typedef struct {
    Bool isLocal;
} M_QuantizationParameter;

u32 gf_sg_vrml_get_sf_type(u32 fieldType);
GF_Err gf_sg_vrml_mf_append(void *far_ptr, u32 fieldType, void **sffield_ptr);
GF_Err gf_bifs_dec_sf_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *node, GF_FieldInfo *sffield, Bool flag);
GF_Node *gf_bifs_dec_node(GF_BifsDecoder *codec, GF_BitStream *bs, u32 NDTtype);
GF_Err gf_node_register(GF_Node *new_node, GF_Node *node);
GF_Err gf_bifs_dec_qp_remove(GF_BifsDecoder *codec, Bool initial_qp);
GF_Err gf_bifs_dec_qp_set(GF_BifsDecoder *codec, GF_Node *new_node);
u32 gf_node_get_tag(GF_Node *node);
GF_Err gf_node_list_add_child_last(void *far_ptr, GF_Node *new_node, GF_ChildNodeItem **last);
void gf_node_unregister(GF_Node *new_node, GF_Node *node);
void gf_bifs_dec_qp14_set_length(GF_BifsDecoder *codec, u32 nbF);
u8 gf_bs_read_int(GF_BitStream *bs, u32 bits);