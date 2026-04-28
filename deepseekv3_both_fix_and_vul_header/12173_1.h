#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;

#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_EXPORT

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_AVCConfig GF_AVCConfig;
typedef struct GF_NALUFFParam GF_NALUFFParam;
typedef struct __gf_list_t gf_list_t;

#define gf_list_count(l) 0
#define gf_list_get(l, i) NULL

enum {
    GF_ISOM_SUBTYPE_AVC_H264,
    GF_ISOM_SUBTYPE_AVC2_H264,
    GF_ISOM_SUBTYPE_AVC3_H264,
    GF_ISOM_SUBTYPE_AVC4_H264
};

u32 gf_isom_get_media_subtype(GF_ISOFile *file, u32 track, u32 stream);
GF_AVCConfig *gf_isom_avc_config_get(GF_ISOFile *file, u32 track, u32 stream);
GF_Err gf_isom_avc_config_update(GF_ISOFile *file, u32 track, u32 stream, GF_AVCConfig *avcc);
void gf_odf_avc_cfg_del(GF_AVCConfig *avcc);

struct GF_AVCConfig {
    u32 AVCLevelIndication;
    u32 profile_compatibility;
    u32 AVCProfileIndication;
    gf_list_t *sequenceParameterSets;
};

struct GF_NALUFFParam {
    uint8_t *data;
};