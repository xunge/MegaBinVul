#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int32_t GF_Err;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_List GF_List;

#define GF_EXPORT
#define GF_OK 0
#define GF_BAD_PARAM 1

typedef struct GF_AVCConfigSlot {
    u32 size;
    char *data;
} GF_AVCConfigSlot;

typedef struct GF_AVCConfig {
    u8 configurationVersion;
    u8 AVCProfileIndication;
    u8 profile_compatibility;
    u8 AVCLevelIndication;
    u8 nal_unit_size;
    u8 chroma_format;
    u8 luma_bit_depth;
    u8 chroma_bit_depth;
    u8 write_annex_b;
    GF_List *sequenceParameterSets;
    GF_List *pictureParameterSets;
    GF_List *sequenceParameterSetExtensions;
} GF_AVCConfig;

u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 nBits);
void gf_bs_write_u16(GF_BitStream *bs, u16 value);
void gf_bs_write_u32(GF_BitStream *bs, u32 value);
void gf_bs_write_u8(GF_BitStream *bs, u8 value);
void gf_bs_write_data(GF_BitStream *bs, const char *data, u32 size);
int gf_avc_is_rext_profile(u8 profile);