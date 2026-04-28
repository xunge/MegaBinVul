#include <stdlib.h>
#include <string.h>

#define GF_EXPORT
#define GF_STREAM_SCENE 1
#define GF_CODECID_DIMS 2

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GF_StreamContext {
    u32 streamType;
    u32 codec_id;
} GF_StreamContext;

typedef struct GF_Descriptor {
    // placeholder for descriptor structure
} GF_Descriptor;

typedef struct {
    GF_Descriptor *root_od;
    void *streams;
} GF_SceneEngineContext;

typedef struct GF_SceneEngine {
    GF_SceneEngineContext *ctx;
} GF_SceneEngine;

void* gf_list_enum(void* list, u32* index);
u32 gf_base64_encode(const u8* src, u32 src_size, u8* dst, u32 dst_size);
void gf_odf_desc_write(GF_Descriptor *desc, u8 **buffer, u32 *size);
void* gf_malloc(size_t size);
void gf_free(void *ptr);