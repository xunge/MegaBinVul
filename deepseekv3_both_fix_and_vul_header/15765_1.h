#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;
typedef unsigned char Bool;
#define GF_TRUE 1
#define GF_FALSE 0
#define Double double

typedef struct GF_ESInterface {
    u32 stream_id;
    u32 stream_type;
    u32 object_type_indication;
    char *decoder_config;
    u32 decoder_config_size;
    u32 lang;
    u32 timescale;
    Double duration;
    u32 bit_rate;
    u32 caps;
    struct GF_SLConfig *sl_config;
    void *input_ctrl;
    void *input_udta;
    u32 depends_on_stream;
} GF_ESInterface;

typedef struct GF_ESIMP4 {
    void *mp4;
    u32 track;
    u32 mtype;
    u32 mstype;
    Bool loop;
    u32 sample_count;
    void *source;
    char *dsi;
    u32 dsi_size;
    s64 ts_offset;
    s32 cts_dts_shift;
} GF_ESIMP4;

typedef struct GF_ESD {
    struct {
        u32 streamType;
        u32 objectTypeIndication;
        struct {
            void *data;
            u32 dataLength;
        } *decoderSpecificInfo;
    } *decoderConfig;
} GF_ESD;

typedef struct M2TSSource {
    Bool real_time;
    u32 samples_count;
    u32 nb_real_streams;
    u32 max_sample_size;
} M2TSSource;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Descriptor GF_Descriptor;
typedef struct GF_SLConfig {
    u32 tag;
    u32 useAccessUnitStartFlag;
    u32 useAccessUnitEndFlag;
    u32 useRandomAccessPointFlag;
    u32 useTimestampsFlag;
    u32 timestampLength;
    u32 timestampResolution;
} GF_SLConfig;

#define GPAC_OTI_AUDIO_AAC_MPEG4 0x40
#define GPAC_OTI_AUDIO_AAC_MPEG2_MP 0x66
#define GPAC_OTI_AUDIO_AAC_MPEG2_LCP 0x67
#define GPAC_OTI_AUDIO_AAC_MPEG2_SSRP 0x68
#define GPAC_OTI_VIDEO_MPEG4_PART2 0x20
#define GPAC_OTI_VIDEO_HEVC 0x23
#define GPAC_OTI_VIDEO_LHVC 0x2A
#define GPAC_OTI_VIDEO_AVC 0x21
#define GPAC_OTI_VIDEO_SVC 0x2B
#define GPAC_OTI_VIDEO_MVC 0x2C
#define GPAC_OTI_SCENE_VTT_MP4 0xE0

#define GF_ODF_SLC_TAG 0x06
#define GF_ESI_SIGNAL_DTS 0x01
#define GF_ISOM_REF_SCAL 0
#define GF_ISOM_REF_BASE 1
#define GF_ISOM_NALU_EXTRACT_LAYER_ONLY 0x01
#define GF_ISOM_NALU_EXTRACT_INBAND_PS_FLAG 0x02
#define GF_ISOM_NALU_EXTRACT_ANNEXB_FLAG 0x04
#define GF_ISOM_NALU_EXTRACT_VDRD_FLAG 0x08

#define GF_LOG_ERROR 1
#define GF_LOG_APP 2
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_4CC(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))
#define GF_LOG(level, category, message) fprintf(stderr, message)

void *gf_malloc(size_t size);
void gf_free(void *ptr);
void gf_odf_desc_del(GF_Descriptor *desc);
u32 gf_isom_get_media_type(void *mp4, u32 track);
u32 gf_isom_get_media_subtype(void *mp4, u32 track, u32 sub);
u32 gf_isom_get_sample_count(void *mp4, u32 track);
u32 gf_isom_get_track_id(void *mp4, u32 track);
GF_ESD *gf_media_map_esd(void *mp4, u32 track);
char *gf_isom_get_media_language(void *mp4, u32 track, char **lang);
u32 gf_isom_get_media_timescale(void *mp4, u32 track);
u64 gf_isom_get_media_data_size(void *mp4, u32 track);
u64 gf_isom_get_media_duration(void *mp4, u32 track);
Bool gf_isom_has_time_offset(void *mp4, u32 track);
s32 gf_isom_get_cts_to_dts_shift(void *mp4, u32 track);
s32 gf_isom_get_reference_count(void *mp4, u32 track, u32 ref_type);
void gf_isom_get_reference_ID(void *mp4, u32 track, u32 ref_type, u32 ref_idx, u32 *ref_id);
u32 gf_isom_get_sample_size(void *mp4, u32 track, u32 sample_num);
void gf_isom_set_nalu_extract_mode(void *mp4, u32 track, u32 flags);
void gf_isom_set_extraction_slc(void *mp4, u32 track, u32 enable, GF_SLConfig *slc);
Bool gf_isom_get_edit_list_type(void *mp4, u32 track, s64 *mediaOffset);

void *mp4_input_ctrl;