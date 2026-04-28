#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef unsigned int u32;
typedef unsigned char Bool;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_List GF_List;

typedef struct GF_Node {
    struct {
        int num_instances;
    } *sgprivate;
    u32 tag;
} GF_Node;

typedef struct GF_Command {
    int type;
} GF_Command;

typedef struct GF_CommandField {
    GF_Node* new_node;
    void* field_ptr;
    int fieldType;
} GF_CommandField;

typedef struct M_QuantizationParameter {
    Bool isLocal;
} M_QuantizationParameter;

typedef struct {
    GF_Node* global_qp;
} GF_SceneGraph;

typedef struct GF_BifsDecoder {
    M_QuantizationParameter* ActiveQP;
    void* current_graph;
    GF_SceneGraph* scenegraph;
} GF_BifsDecoder;

#define TAG_MPEG4_QuantizationParameter 0
#define NDT_SFWorldNode 0
#define GF_SG_GLOBAL_QUANTIZER 0
#define GF_SG_VRML_SFNODE 0

GF_Node* gf_bifs_dec_node(GF_BifsDecoder* codec, GF_BitStream* bs, int type);
void gf_node_unregister(GF_Node* node, void* unused);
u32 gf_node_get_tag(GF_Node* node);
GF_Command* gf_sg_command_new(void* graph, int type);
GF_CommandField* gf_sg_command_field_new(GF_Command* com);
void gf_list_add(GF_List* list, void* item);