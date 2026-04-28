#include <stdlib.h>
#include <stdio.h>

typedef int GF_Err;
#define GF_OK 0
#define GF_TRUE 1

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_List GF_List;
typedef struct GF_SceneGraph GF_SceneGraph;
typedef struct GF_Proto GF_Proto;

struct CommandBufferItem {
    void *node;
};
typedef struct CommandBufferItem CommandBufferItem;

typedef struct GF_BifsDecoder {
    GF_SceneGraph *current_graph;
    GF_Proto *pCurrentProto;
    GF_List *command_buffers;
    GF_List *QPs;
    GF_Err LastError;
} GF_BifsDecoder;

extern GF_Err BM_ParseInsert(GF_BifsDecoder *codec, GF_BitStream *bs, GF_List *com_list);
extern GF_Err BM_ParseDelete(GF_BifsDecoder *codec, GF_BitStream *bs, GF_List *com_list);
extern GF_Err BM_ParseReplace(GF_BifsDecoder *codec, GF_BitStream *bs, GF_List *com_list);
extern GF_Err BM_SceneReplace(GF_BifsDecoder *codec, GF_BitStream *bs, GF_List *com_list);
extern u32 gf_list_count(const GF_List *list);
extern u8 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
extern void gf_bifs_dec_qp_remove(GF_BifsDecoder *codec, u8 flag);
extern void gf_node_unregister(void *node, void *unused);
extern void *gf_list_pop_back(GF_List *list);
extern void gf_free(void *ptr);