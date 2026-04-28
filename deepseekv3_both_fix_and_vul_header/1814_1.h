#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef enum {
    GF_OK = 0,
    GF_SG_UNKNOWN_NODE,
} GF_Err;

typedef struct {
    u32 NodeIDBits;
} GF_BifsConfig;

typedef struct {
    GF_BifsConfig config;
} GF_BifsDecoderInfo;

typedef struct {
    GF_BifsDecoderInfo *info;
    void *current_graph;
} GF_BifsDecoder;

typedef struct {
    void *ptr;
} GF_BitStream;

typedef struct {
    void *far_ptr;
    u32 fieldType;
    u32 fieldIndex;
    char *name;
} GF_FieldInfo;

typedef struct {
    u32 fieldIndex;
    u32 fieldType;
    void *field_ptr;
    void *new_node;
    void *node_list;
    s32 pos;
} GF_CommandField;

typedef struct {
    u32 fieldIndex;
    u32 toFieldIndex;
    u32 fromFieldIndex;
    u32 child_field;
    s32 ChildNodeTag;
    u32 toNodeID;
    u32 fromNodeID;
    GF_CommandField *field;
} GF_Command;

typedef struct {
    void *far_ptr;
} GF_ChildNodeItem;

typedef struct {
    void *head;
} GF_List;

typedef struct {
    u32 tag;
    void *proto;
} GF_Node;

#define GF_SG_XREPLACE 0
#define GF_SG_FIELD_CODING_IN 0
#define GF_SG_FIELD_CODING_DEF 0
#define TAG_ProtoNode 0
#define GF_SG_VRML_SFNODE 0
#define GF_SG_VRML_MFNODE 0
#define GF_TRUE 1

static u32 gf_get_bit_size(u32 val);
static GF_Node *gf_sg_find_node(void *graph, u32 id);
static GF_Command *gf_sg_command_new(void *graph, u32 type);
static void BM_SetCommandNode(GF_Command *com, GF_Node *target);
static void gf_list_add(GF_List *list, void *item);
static u32 gf_node_get_num_fields_in_mode(GF_Node *node, u32 mode);
static u32 gf_bs_read_int(GF_BitStream *bs, u32 nbBits);
static GF_Err gf_bifs_get_field_index(GF_Node *node, u32 ind, u32 mode, u32 *aind);
static GF_Err gf_node_get_field(GF_Node *node, u32 aind, GF_FieldInfo *field);
static GF_CommandField *gf_sg_command_field_new(GF_Command *com);
static Bool gf_sg_vrml_is_sf_field(u32 fieldType);
static GF_Node *gf_node_list_get_child(GF_ChildNodeItem *item, s32 pos);
static u32 gf_node_get_tag(GF_Node *node);
static void *gf_node_get_proto(GF_Node *node);
static s32 gf_sg_proto_get_id(void *proto);
static u32 gf_sg_vrml_get_sf_type(u32 fieldType);
static void *gf_sg_vrml_field_pointer_new(u32 fieldType);
static GF_Err gf_bifs_dec_sf_field(GF_BifsDecoder *codec, GF_BitStream *bs, GF_Node *target, GF_FieldInfo *field, Bool flag);