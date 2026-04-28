#include <stdlib.h>
#include <assert.h>

#define GF_EXPORT

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_NOT_SUPPORTED
} GF_Err;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_List GF_List;
typedef struct M_QuantizationParameter M_QuantizationParameter;

typedef struct {
    void* node;
} CommandBufferItem;

typedef struct {
    struct {
        int elementaryMasks;
    } config;
} GF_BifsStreamInfo;

typedef struct {
    M_QuantizationParameter* global_qp;
} GF_SceneGraph;

typedef struct GF_BifsDecoder {
    int dec_memory_mode;
    GF_BifsStreamInfo* info;
    GF_SceneGraph* scenegraph;
    GF_SceneGraph* current_graph;
    M_QuantizationParameter* ActiveQP;
    GF_List* command_buffers;
} GF_BifsDecoder;

#define GF_BITSTREAM_READ 0

GF_BitStream* gf_bs_new(u8* data, u32 length, u32 mode);
void gf_bs_del(GF_BitStream* bs);
void gf_bs_set_eos_callback(GF_BitStream* bs, void (*callback)(void*), void* param);
GF_Err BM_ParseCommand(GF_BifsDecoder* codec, GF_BitStream* bs, GF_List* com_list);
void BM_EndOfStream(void* param);
void gf_bifs_flush_command_list(GF_BifsDecoder* codec);
u32 gf_list_count(GF_List* list);
void* gf_list_get(GF_List* list, u32 index);
void gf_list_rem(GF_List* list, u32 index);
void gf_free(void* ptr);
void gf_node_unregister(void* node, void* param);
GF_BifsStreamInfo* gf_bifs_dec_get_stream(GF_BifsDecoder* codec, u16 ESID);