#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;

typedef struct GF_ISOFile {
    bool is_jp2;
    void* moov;
    struct {
        struct {
            u32 handlerType;
        } *handler;
    } *meta;
} GF_ISOFile;

typedef struct GF_MetaHandler {
    u32 handlerType;
} GF_MetaHandler;

typedef struct GF_DecoderConfig {
    u32 streamType;
    u32 objectTypeIndication;
} GF_DecoderConfig;

typedef struct GF_Descriptor {
    // base descriptor fields
} GF_Descriptor;

#define GF_EXPORT

#define GF_ISOM_BRAND_MJP2 0
#define GF_ISOM_BRAND_JP2 1
#define GF_ISOM_BRAND_ISOM 2
#define GF_ISOM_BRAND_3G2A 3
#define GF_ISOM_BRAND_MP42 4
#define GF_ISOM_BRAND_AVC1 5
#define GF_ISOM_BRAND_ISMA 6
#define GF_ISOM_BRAND_3GP5 7
#define GF_ISOM_BRAND_3GP6 8
#define GF_ISOM_BRAND_3GG6 9

#define GF_ISOM_MEDIA_SCENE 0
#define GF_ISOM_MEDIA_OD 1
#define GF_ISOM_MEDIA_TEXT 2
#define GF_ISOM_MEDIA_SUBT 3
#define GF_ISOM_MEDIA_AUDIO 4
#define GF_ISOM_MEDIA_VISUAL 5
#define GF_ISOM_MEDIA_AUXV 6
#define GF_ISOM_MEDIA_PICT 7

#define GF_ISOM_SUBTYPE_3GP_AMR 0
#define GF_ISOM_SUBTYPE_3GP_AMR_WB 1
#define GF_ISOM_SUBTYPE_3GP_H263 2
#define GF_ISOM_SUBTYPE_3GP_EVRC 3
#define GF_ISOM_SUBTYPE_3GP_QCELP 4
#define GF_ISOM_SUBTYPE_3GP_SMV 5
#define GF_ISOM_SUBTYPE_AVC_H264 6
#define GF_ISOM_SUBTYPE_AVC2_H264 7
#define GF_ISOM_SUBTYPE_AVC3_H264 8
#define GF_ISOM_SUBTYPE_AVC4_H264 9
#define GF_ISOM_SUBTYPE_SVC_H264 10
#define GF_ISOM_SUBTYPE_MVC_H264 11
#define GF_ISOM_SUBTYPE_MPEG4 12
#define GF_ISOM_SUBTYPE_MPEG4_CRYP 13

#define GF_STREAM_VISUAL 0
#define GF_STREAM_AUDIO 1

#define GF_CODECID_MPEG4_PART2 0
#define GF_CODECID_AVC 1
#define GF_CODECID_SVC 2
#define GF_CODECID_MVC 3
#define GF_CODECID_AAC_MPEG2_MP 4
#define GF_CODECID_AAC_MPEG2_LCP 5
#define GF_CODECID_AAC_MPEG2_SSRP 6
#define GF_CODECID_AAC_MPEG4 7
#define GF_CODECID_MPEG2_PART3 8
#define GF_CODECID_MPEG_AUDIO 9
#define GF_CODECID_EVRC 10
#define GF_CODECID_SMV 11
#define GF_CODECID_QCELP 12

u32 gf_isom_get_track_count(GF_ISOFile *file);
u32 gf_isom_get_media_type(GF_ISOFile *file, u32 track);
u32 gf_isom_get_media_subtype(GF_ISOFile *file, u32 track, u32 sample);
u32 gf_isom_get_sample_count(GF_ISOFile *file, u32 track);
bool gf_isom_is_video_handler_type(u32 type);
GF_DecoderConfig *gf_isom_get_decoder_config(GF_ISOFile *file, u32 track, u32 sample);
void gf_odf_desc_del(GF_Descriptor *desc);