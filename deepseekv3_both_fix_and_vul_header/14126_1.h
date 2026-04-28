#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int32_t s32;

typedef enum {
    GF_OK,
    GF_ISOM_INVALID_FILE
} GF_Err;

typedef enum {
    GF_ISOM_BOX_TYPE_AVCC
} GF_BoxType;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_WARNING,
    GF_LOG_CODING
} GF_LogLevel;

typedef struct {
    u32 size;
    char* data;
} GF_AVCConfigSlot;

typedef struct {
    u8 configurationVersion;
    u8 AVCProfileIndication;
    u8 profile_compatibility;
    u8 AVCLevelIndication;
    u8 complete_representation;
    u8 nal_unit_size;
    u8 chroma_format;
    u8 luma_bit_depth;
    u8 chroma_bit_depth;
    void* sequenceParameterSets;
    void* pictureParameterSets;
    void* sequenceParameterSetExtensions;
} GF_AVCConfiguration;

typedef struct {
    GF_BoxType type;
    u32 size;
    GF_AVCConfiguration* config;
} GF_AVCConfigurationBox;

typedef struct {
    GF_BoxType type;
    u32 size;
} GF_Box;

typedef struct {
    void* bs;
} GF_BitStream;

typedef struct {
    struct {
        u8 chroma_format;
        u8 luma_bit_depth_m8;
        u8 chroma_bit_depth_m8;
    } sps[1];
} AVCState;

void* gf_malloc(size_t size);
void gf_free(void* ptr);
void gf_bs_read_data(GF_BitStream* bs, char* data, u32 size);
u8 gf_bs_read_u8(GF_BitStream* bs);
u16 gf_bs_read_u16(GF_BitStream* bs);
u32 gf_bs_read_int(GF_BitStream* bs, u32 bits);
u32 gf_bs_available(GF_BitStream* bs);
void gf_list_add(void* list, void* item);
void* gf_list_new();
void* gf_list_get(void* list, u32 index);
GF_AVCConfiguration* gf_odf_avc_cfg_new();
void gf_odf_avc_cfg_del(GF_AVCConfiguration* cfg);
int gf_avc_is_rext_profile(u8 profile);
s32 gf_media_avc_read_sps(char* data, u32 size, AVCState* avc, u32 flag, u32* vui_flag_pos);
void GF_LOG(GF_LogLevel level, GF_LogLevel category, const char* format, ...);