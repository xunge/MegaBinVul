#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef bool Bool;

#define GF_EXPORT
#define GF_Err int
#define GF_OK 0
#define GF_NON_COMPLIANT_BITSTREAM 1
#define GF_ISOM_INVALID_FILE 2
#define GF_BAD_PARAM 3
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 1
#define GF_LOG_DEBUG 2
#define GF_LOG_CONTAINER 3
#define GF_LOG_AUTHOR 4
#define RFC6381_CODEC_NAME_SIZE_MAX 256
#define GF_STREAM_AUDIO 0
#define GF_STREAM_VISUAL 1
#define GF_ISOM_REF_TBAS 0
#define GPAC_DISABLE_HEVC
#define GPAC_DISABLE_AV1
#define GPAC_DISABLE_AV_PARSERS

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_ESD GF_ESD;
typedef struct GF_AVCConfig GF_AVCConfig;
typedef struct GF_HEVCConfig GF_HEVCConfig;
typedef struct GF_AV1Config GF_AV1Config;
typedef struct GF_VPConfig GF_VPConfig;
typedef struct GF_Descriptor GF_Descriptor;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_M4ADecSpecInfo GF_M4ADecSpecInfo;
typedef struct GF_M4VDecSpecInfo GF_M4VDecSpecInfo;
typedef struct AV1State AV1State;

typedef struct {
    uint8_t *data;
    uint32_t dataLength;
} GF_DecoderSpecificInfo;

typedef struct {
    uint8_t streamType;
    uint8_t objectTypeIndication;
    GF_DecoderSpecificInfo *decoderSpecificInfo;
} GF_DecoderConfig;

struct GF_ESD {
    GF_DecoderConfig *decoderConfig;
};

struct GF_AVCConfig {
    uint8_t AVCProfileIndication;
    uint8_t profile_compatibility;
    uint8_t AVCLevelIndication;
};

struct GF_HEVCConfig {
    uint8_t profile_space;
    uint8_t profile_idc;
    uint32_t general_profile_compatibility_flags;
    uint8_t tier_flag;
    uint8_t level_idc;
    uint8_t progressive_source_flag;
    uint8_t interlaced_source_flag;
    uint8_t non_packed_constraint_flag;
    uint8_t frame_only_constraint_flag;
    uint64_t constraint_indicator_flags;
};

struct GF_VPConfig {
    uint8_t profile;
    uint8_t level;
    uint8_t bit_depth;
    uint8_t chroma_subsampling;
    uint8_t colour_primaries;
    uint8_t transfer_characteristics;
    uint8_t matrix_coefficients;
    uint8_t video_fullRange_flag;
};

struct GF_AV1Config {
    uint8_t seq_profile;
    uint8_t seq_level_idx_0;
    uint8_t seq_tier_0;
    uint8_t monochrome;
    uint8_t chroma_subsampling_x;
    uint8_t chroma_subsampling_y;
    uint8_t chroma_sample_position;
    uint8_t color_primaries;
    uint8_t transfer_characteristics;
    uint8_t matrix_coefficients;
    uint8_t color_range;
    uint8_t color_description_present_flag;
    uint8_t bit_depth;
};

struct AV1State {
    GF_AV1Config *config;
    uint8_t color_primaries;
    uint8_t transfer_characteristics;
    uint8_t matrix_coefficients;
    uint8_t color_range;
    uint8_t color_description_present_flag;
    struct {
        uint8_t obu_type;
    } frame_state;
};

typedef struct {
    uint8_t obu_type;
    uint8_t *obu;
    uint32_t obu_length;
} GF_AV1_OBUArrayEntry;

struct GF_M4ADecSpecInfo {
    uint8_t sbr_object_type;
    uint8_t sbr_sr;
    uint8_t has_ps;
};

struct GF_M4VDecSpecInfo {
    uint8_t VideoPL;
};

#define GF_ISOM_SUBTYPE_MPEG4_CRYP 0
#define GF_ISOM_SUBTYPE_MPEG4 1
#define GF_ISOM_SUBTYPE_AVC_H264 2
#define GF_ISOM_SUBTYPE_AVC2_H264 3
#define GF_ISOM_SUBTYPE_AVC3_H264 4
#define GF_ISOM_SUBTYPE_AVC4_H264 5
#define GF_ISOM_SUBTYPE_SVC_H264 6
#define GF_ISOM_SUBTYPE_MVC_H264 7
#define GF_ISOM_SUBTYPE_HVC1 8
#define GF_ISOM_SUBTYPE_HEV1 9
#define GF_ISOM_SUBTYPE_HVC2 10
#define GF_ISOM_SUBTYPE_HEV2 11
#define GF_ISOM_SUBTYPE_HVT1 12
#define GF_ISOM_SUBTYPE_LHV1 13
#define GF_ISOM_SUBTYPE_LHE1 14
#define GF_ISOM_SUBTYPE_AV01 15
#define GF_ISOM_SUBTYPE_VP08 16
#define GF_ISOM_SUBTYPE_VP09 17

void GF_LOG(int level, int category, const char *format, ...);
uint32_t gf_isom_get_media_subtype(GF_ISOFile *movie, uint32_t track, uint32_t sample);
Bool gf_isom_is_ismacryp_media(GF_ISOFile *movie, uint32_t track, uint32_t sample);
Bool gf_isom_is_omadrm_media(GF_ISOFile *movie, uint32_t track, uint32_t sample);
Bool gf_isom_is_cenc_media(GF_ISOFile *movie, uint32_t track, uint32_t sample);
uint32_t gf_isom_is_media_encrypted(GF_ISOFile *movie, uint32_t track, uint32_t sample);
GF_Err gf_isom_get_ismacryp_info(GF_ISOFile *movie, uint32_t track, uint32_t sample, uint32_t *originalFormat, void *a, void *b, void *c, void *d, void *e, void *f, void *g);
GF_Err gf_isom_get_omadrm_info(GF_ISOFile *movie, uint32_t track, uint32_t sample, uint32_t *originalFormat, void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h, void *i, void *j, void *k);
GF_Err gf_isom_get_cenc_info(GF_ISOFile *movie, uint32_t track, uint32_t sample, uint32_t *originalFormat, void *a, void *b, void *c);
GF_Err gf_isom_get_original_format_type(GF_ISOFile *movie, uint32_t track, uint32_t sample, uint32_t *originalFormat);
GF_ESD *gf_isom_get_esd(GF_ISOFile *movie, uint32_t track, uint32_t sample);
void gf_odf_desc_del(GF_Descriptor *desc);
GF_AVCConfig *gf_isom_avc_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
GF_AVCConfig *gf_isom_mvc_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
GF_AVCConfig *gf_isom_svc_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
void gf_odf_avc_cfg_del(GF_AVCConfig *avcc);
GF_HEVCConfig *gf_isom_hevc_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
GF_HEVCConfig *gf_isom_lhvc_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
void gf_odf_hevc_cfg_del(GF_HEVCConfig *hvcc);
GF_AV1Config *gf_isom_av1_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
void gf_odf_av1_cfg_del(GF_AV1Config *av1c);
GF_VPConfig *gf_isom_vp_config_get(GF_ISOFile *movie, uint32_t track, uint32_t sample);
void gf_odf_vp_cfg_del(GF_VPConfig *vpcc);
GF_Err gf_isom_get_reference(GF_ISOFile *movie, uint32_t track, uint32_t ref_type, uint32_t ref_index, uint32_t *refTrack);
const char *gf_4cc_to_str(uint32_t fourcc);
GF_Err gf_m4a_get_config(uint8_t *data, uint32_t dataLength, GF_M4ADecSpecInfo *a_cfg);
void gf_m4v_get_config(uint8_t *data, uint32_t dataLength, GF_M4VDecSpecInfo *dsi);
Bool av1_is_obu_header(uint8_t obu_type);
GF_Err aom_av1_parse_temporal_unit_from_section5(GF_BitStream *bs, AV1State *state);
void av1_reset_frame_state(void *frame_state);
GF_BitStream *gf_bs_new(uint8_t *data, uint32_t size, uint32_t mode);
void gf_bs_del(GF_BitStream *bs);