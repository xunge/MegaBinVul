#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int GF_Err;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_List GF_List;
typedef struct GF_Node GF_Node;
typedef struct GF_Proto GF_Proto;
typedef struct GF_ProtoFieldInterface GF_ProtoFieldInterface;
typedef struct GF_SceneGraph {
    GF_List* protos;
} GF_SceneGraph;
typedef struct GF_FieldInfo {
    void* far_ptr;
    u32 fieldType;
    const char* name;
    u32 eventType;
} GF_FieldInfo;
typedef struct GF_BifsDecoder {
    GF_SceneGraph* current_graph;
    GF_Proto* pCurrentProto;
    GF_List* command_buffers;
    struct {
        struct {
            u32 ProtoIDBits;
            u32 UsePredictiveMFField;
        } config;
    }* info;
    u32 UseName;
    GF_Err LastError;
} GF_BifsDecoder;
typedef struct CommandBufferItem {
    GF_Node* node;
} CommandBufferItem;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_SG_EVENT_EXPOSED_FIELD 0
#define GF_SG_EVENT_FIELD 1
#define GF_SG_EVENT_IN 2
#define QC_LINEAR_SCALAR 0
#define NDT_SFWorldNode 0
#define GF_SG_VRML_SFINT32 0
#define GF_SG_VRML_SFTIME 1
#define GF_SG_VRML_SFFLOAT 2
#define GF_SG_VRML_MFURL 3

u32 gf_list_count(GF_List* list);
u32 gf_bs_read_int(GF_BitStream* bs, u32 numBits);
void gf_bifs_dec_name(GF_BitStream* bs, char* name, u32 size);
GF_Proto* gf_sg_proto_new(GF_SceneGraph* sg, u32 ID, const char* name, u32 isExtern);
void gf_list_add(GF_List* list, void* item);
GF_SceneGraph* gf_sg_proto_get_graph(GF_Proto* proto);
GF_ProtoFieldInterface* gf_sg_proto_field_new(GF_Proto* proto, u32 field_type, u32 event_type, const char* name);
void gf_sg_proto_field_get_field(GF_ProtoFieldInterface* proto_field, GF_FieldInfo* field);
u32 gf_sg_vrml_is_sf_field(u32 field_type);
GF_Err gf_bifs_dec_sf_field(GF_BifsDecoder* codec, GF_BitStream* bs, void* node, GF_FieldInfo* field, u32 isExtern);
GF_Err BD_DecMFFieldList(GF_BifsDecoder* codec, GF_BitStream* bs, void* node, GF_FieldInfo* field);
GF_Err BD_DecMFFieldVec(GF_BifsDecoder* codec, GF_BitStream* bs, void* node, GF_FieldInfo* field);
void* gf_sg_proto_get_extern_url(GF_Proto* proto);
GF_Node* gf_bifs_dec_node(GF_BifsDecoder* codec, GF_BitStream* bs, u32 node_type);
GF_Err gf_node_register(GF_Node* node, void* user);
void gf_bifs_flush_command_list(GF_BifsDecoder* codec);
void gf_sg_proto_add_node_code(GF_Proto* proto, GF_Node* node);
GF_Err gf_bifs_dec_route(GF_BifsDecoder* codec, GF_BitStream* bs, u32 isExtern);
u32 gf_sg_proto_get_field_count(GF_Proto* proto);
GF_ProtoFieldInterface* gf_sg_proto_field_find(GF_Proto* proto, u32 index);
u32 gf_sg_vrml_get_sf_type(u32 field_type);
void* gf_sg_vrml_field_pointer_new(u32 field_type);
GF_Err gf_bifs_proto_field_set_aq_info(GF_ProtoFieldInterface* proto_field, u32 QP_Type, u32 hasMinMax, u32 qpsftype, void* qp_min_value, void* qp_max_value, u32 NumBits);
void gf_sg_vrml_field_pointer_del(void* ptr, u32 field_type);
void gf_list_del_item(GF_List* list, void* item);
void* gf_list_pop_back(GF_List* list);
void gf_node_unregister(GF_Node* node, void* user);
void gf_free(void* ptr);
void gf_sg_proto_del(GF_Proto* proto);