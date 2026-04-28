#include <stdlib.h>
#include <stdio.h>

typedef int GF_Err;
typedef unsigned int u32;

#define GF_BITSTREAM_READ 0
#define GF_SG_VRML_SFCOMMANDBUFFER 1
#define GF_OK 0

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_SceneGraph GF_SceneGraph;
typedef struct GF_List GF_List;
typedef struct GF_Node GF_Node;
typedef struct GF_CommandBuffer GF_CommandBuffer;
typedef struct GF_Command GF_Command;
typedef struct GF_CommandField GF_CommandField;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct CommandBufferItem CommandBufferItem;

struct GF_BifsDecoder {
    GF_SceneGraph *current_graph;
    GF_List *command_buffers;
    GF_Err LastError;
};

struct CommandBufferItem {
    GF_Node *node;
    GF_CommandBuffer *cb;
};

struct GF_CommandBuffer {
    char *buffer;
    u32 bufferSize;
    GF_List *commandList;
};

struct GF_CommandField {
    int fieldType;
    void *field_ptr;
};

struct GF_Command {
    GF_List *command_fields;
};

GF_List *gf_list_new();
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void gf_list_rem(GF_List *list, u32 index);
void gf_list_add(GF_List *list, void *item);
void gf_list_del(GF_List *list);
GF_SceneGraph *gf_node_get_graph(GF_Node *node);
GF_BitStream *gf_bs_new(char *buffer, u32 size, int mode);
void gf_bs_set_eos_callback(GF_BitStream *bs, void *callback, void *par);
void gf_bs_del(GF_BitStream *bs);
void gf_free(void *ptr);
GF_Err BM_ParseCommand(GF_BifsDecoder *codec, GF_BitStream *bs, GF_List *commandList);
void BM_EndOfStream(void *par);
void gf_sg_command_del(GF_Command *com);