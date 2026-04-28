#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef bool Bool;

#define GF_EXPORT
#define GF_Err int
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_NOT_SUPPORTED 2
#define GF_OUT_OF_MEM 3

#define GF_TRUE 1
#define GF_FALSE 0

#define GF_ISOM_OPEN_EDIT 0
#define GF_ISOM_OPEN_WRITE 1
#define GF_ISOM_WRITE_EDIT 2

#define GF_ISOM_MEDIA_VISUAL 0
#define GF_ISOM_MEDIA_AUXV 1
#define GF_ISOM_MEDIA_PICT 2
#define GF_ISOM_MEDIA_AUDIO 3
#define GF_ISOM_MEDIA_HINT 4
#define GF_ISOM_MEDIA_OD 5
#define GF_ISOM_MEDIA_SCENE 6

#define GF_CODECID_JPEG 0
#define GF_CODECID_PNG 1
#define GF_CODECID_MPEG4_PART2 2
#define GF_CODECID_AAC_MPEG4 3
#define GF_CODECID_OD_V1 4
#define GF_CODECID_BIFS_V2 5

#define GF_STREAM_VISUAL 0
#define GF_STREAM_OD 1
#define GF_STREAM_SCENE 2

#define GF_ODF_IOD_TAG 0
#define GF_ODF_OD_TAG 1
#define GF_ODF_OD_UPDATE_TAG 2

#define RAP 1

#define ISMA_VIDEO_OD_ID 1
#define ISMA_AUDIO_OD_ID 2
#define ISMA_VIDEO_ES_ID 1
#define ISMA_AUDIO_ES_ID 2

#define SLPredef_MP4 0

#define GF_LOG_ERROR 0
#define GF_LOG_INFO 1
#define GF_LOG_MEDIA 2

#define GF_ISOM_BRAND_MP42 0
#define GF_ISOM_BRAND_ISOM 1
#define GF_ISOM_BRAND_3GP5 2

#define GF_ISOM_PL_SCENE 0
#define GF_ISOM_PL_GRAPHICS 1
#define GF_ISOM_PL_OD 2
#define GF_ISOM_PL_AUDIO 3
#define GF_ISOM_PL_VISUAL 4

#define GF_BITSTREAM_WRITE 1

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_ESD {
    struct {
        u32 bufferSizeDB;
        u32 objectTypeIndication;
        u32 streamType;
        struct {
            u8* data;
            u32 dataLength;
        } *decoderSpecificInfo;
    } *decoderConfig;
    u32 ESID;
    u32 OCRESID;
} GF_ESD;

typedef struct GF_Descriptor {
    u32 tag;
} GF_Descriptor;

typedef struct GF_ObjectDescriptor {
    u32 tag;
    u32 objectDescriptorID;
} GF_ObjectDescriptor;

typedef struct GF_InitialObjectDescriptor {
    u32 tag;
    u8 audio_profileAndLevel;
    u8 visual_profileAndLevel;
} GF_InitialObjectDescriptor;

typedef struct GF_ODUpdate {
    void* objectDescriptors;
} GF_ODUpdate;

typedef struct GF_ODCodec GF_ODCodec;
typedef struct GF_ISOSample {
    char* data;
    u32 dataLength;
    u32 CTS_Offset;
    u32 DTS;
    u32 IsRAP;
} GF_ISOSample;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_ODCom GF_ODCom;
typedef struct GF_M4VDecSpecInfo {
    u32 width;
    u32 height;
    u32 par_num;
    u32 par_den;
    u8 VideoPL;
} GF_M4VDecSpecInfo;

typedef struct GF_M4ADecSpecInfo {
    u8 audioPL;
} GF_M4ADecSpecInfo;

static const u8 ISMA_BIFS_IMAGE[] = {0};
static const u8 ISMA_GF_BIFS_VIDEO[] = {0};
static const u8 ISMA_BIFS_AI[] = {0};
static const u8 ISMA_BIFS_AV[] = {0};
static const u8 ISMA_BIFS_AUDIO[] = {0};

extern u32 gf_isom_get_track_count(GF_ISOFile *mp4file);
extern GF_ESD *gf_isom_get_esd(GF_ISOFile *mp4file, u32 track, u32 descIndex);
extern void gf_isom_remove_track_from_root_od(GF_ISOFile *mp4file, u32 track);
extern u32 gf_isom_get_media_type(GF_ISOFile *mp4file, u32 track);
extern u32 gf_isom_get_track_id(GF_ISOFile *mp4file, u32 track);
extern void gf_isom_remove_track(GF_ISOFile *mp4file, u32 track);
extern void GF_LOG(u32 level, u32 module, const char *format, ...);
extern void gf_odf_desc_del(GF_Descriptor *desc);
extern GF_ObjectDescriptor *gf_isom_get_root_od(GF_ISOFile *mp4file);
extern void gf_isom_set_root_od_id(GF_ISOFile *mp4file, u32 odID);
extern u32 gf_isom_get_track_by_id(GF_ISOFile *mp4file, u32 trackID);
extern void gf_isom_set_track_id(GF_ISOFile *mp4file, u32 track, u32 newID);
extern void gf_isom_get_track_layout_info(GF_ISOFile *mp4file, u32 track, u32 *w, u32 *h, u32 *par_num, u32 *par_den, u32 *fps);
extern void gf_isom_get_visual_info(GF_ISOFile *mp4file, u32 track, u32 descIndex, u32 *w, u32 *h);
extern void gf_m4v_get_config(u8 *data, u32 length, GF_M4VDecSpecInfo *dsi);
extern void gf_isom_set_visual_info(GF_ISOFile *mp4file, u32 track, u32 descIndex, u32 w, u32 h);
extern void gf_m4a_get_config(u8 *data, u32 length, GF_M4ADecSpecInfo *cfg);
extern void gf_isom_change_mpeg4_description(GF_ISOFile *mp4file, u32 track, u32 descIndex, GF_ESD *esd);
extern GF_ODCodec *gf_odf_codec_new();
extern GF_ISOSample *gf_isom_sample_new();
extern void gf_odf_codec_add_com(GF_ODCodec *codec, GF_ODCom *com);
extern void gf_odf_codec_encode(GF_ODCodec *codec, Bool encode);
extern void gf_odf_codec_get_au(GF_ODCodec *codec, char **data, u32 *length);
extern void gf_odf_codec_del(GF_ODCodec *codec);
extern u32 gf_isom_new_track(GF_ISOFile *mp4file, u32 trackID, u32 mediaType, u32 timescale);
extern GF_ESD *gf_odf_desc_esd_new(u32 slPredef);
extern u32 gf_isom_new_mpeg4_description(GF_ISOFile *mp4file, u32 track, GF_ESD *esd, void *config, u32 configSize, u32 *descIndex);
extern void gf_isom_add_sample(GF_ISOFile *mp4file, u32 track, u32 descIndex, GF_ISOSample *samp);
extern void gf_isom_sample_del(GF_ISOSample **samp);
extern void gf_isom_set_track_interleaving_group(GF_ISOFile *mp4file, u32 track, u32 group);
extern GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode);
extern void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 nbits);
extern void gf_bs_align(GF_BitStream *bs);
extern void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *length);
extern void gf_bs_del(GF_BitStream *bs);
extern void gf_isom_set_track_enabled(GF_ISOFile *mp4file, u32 track, Bool enabled);
extern void gf_isom_add_track_to_root_od(GF_ISOFile *mp4file, u32 track);
extern void gf_isom_set_pl_indication(GF_ISOFile *mp4file, u32 plType, u8 plValue);
extern void gf_isom_set_brand_info(GF_ISOFile *mp4file, u32 brand, Bool isPrimary);
extern void gf_isom_modify_alternate_brand(GF_ISOFile *mp4file, u32 brand, Bool add);
extern u32 gf_isom_get_mode(GF_ISOFile *mp4file);
extern u32 gf_isom_get_timescale(GF_ISOFile *mp4file);
extern u32 gf_isom_last_error(GF_ISOFile *mp4file);

extern void gf_odf_desc_add_desc(GF_Descriptor *parent, GF_Descriptor *child);
extern GF_Descriptor *gf_odf_desc_new(u32 tag);
extern GF_ODUpdate *gf_odf_com_new(u32 tag);
extern void gf_list_add(void *list, void *item);