#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 size;
    u32 id;
    char *data;
} GF_AVCConfigSlot;

typedef struct {
    u8 configurationVersion;
    u8 AVCProfileIndication;
    u8 profile_compatibility;
    u8 AVCLevelIndication;
    u8 nal_unit_size;
    u8 complete_representation;
    u8 chroma_format;
    u8 luma_bit_depth;
    u8 chroma_bit_depth;
    void *sequenceParameterSets;
    void *pictureParameterSets;
    void *sequenceParameterSetExtensions;
} GF_AVCConfig;

GF_AVCConfig *gf_odf_avc_cfg_new();
void *gf_list_new();
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_add(void *list, void *item);
void *gf_malloc(size_t size);