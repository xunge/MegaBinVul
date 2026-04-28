#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned char u8;

typedef enum {
    GF_SDP_IOD_NONE,
    GF_SDP_IOD_ISMA,
    GF_SDP_IOD_ISMA_STRICT
} GF_SDP_IODProfile;

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_NOT_SUPPORTED
} GF_Err;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_WARNING
} GF_LogLevel;

typedef enum {
    GF_LOG_RTP
} GF_LogCategory;

typedef enum {
    GF_ISOM_MEDIA_OD = 1,
    GF_ISOM_MEDIA_SCENE = 2
} GF_ISOM_MediaType;

typedef enum {
    GF_STREAM_OD,
    GF_STREAM_SCENE,
    GF_STREAM_VISUAL,
    GF_STREAM_AUDIO
} GF_StreamType;

typedef enum {
    GF_CODECID_MPEG4_PART2,
    GF_CODECID_AAC_MPEG4
} GF_CodecID;

typedef struct GF_Descriptor GF_Descriptor;

typedef struct {
    u32 predefined;
    Bool hasRandomAccessUnitsOnlyFlag;
    u32 timeScale;
    u32 timestampResolution;
    u32 OCRResolution;
    u64 startCTS;
    u64 startDTS;
} GF_SLConfig;

typedef struct {
    u32 ESID;
    u32 OCRESID;
    char *URLString;
    struct {
        u32 avgBitrate;
        u32 bufferSizeDB;
        u32 maxBitrate;
        GF_StreamType streamType;
        GF_CodecID objectTypeIndication;
    } *decoderConfig;
} GF_ESD;

typedef struct {
    void *ESDescriptors;
} GF_InitialObjectDescriptor;

typedef struct {
    u8 *data;
    u32 dataLength;
    u64 DTS;
    u64 CTS_Offset;
} GF_ISOSample;

typedef struct {
    void *root_od;
} GF_ISOFile;

#define GF_EXPORT

void gf_isom_sdp_clean(GF_ISOFile *file);
void gf_isom_sdp_add_line(GF_ISOFile *file, const char *line);
Bool gf_sys_is_test_mode(void);
const char *gf_gpac_version(void);
const char *gf_gpac_copyright(void);
u32 gf_isom_get_track_count(GF_ISOFile *file);
Bool gf_isom_is_track_in_root_od(GF_ISOFile *file, u32 track);
GF_ISOM_MediaType gf_isom_get_media_type(GF_ISOFile *file, u32 track);
void *gf_isom_get_root_od(GF_ISOFile *file);
GF_ESD *gf_isom_get_esd(GF_ISOFile *file, u32 track, u32 descIndex);
u32 gf_isom_get_sample_count(GF_ISOFile *file, u32 track);
GF_ISOSample *gf_isom_get_sample(GF_ISOFile *file, u32 track, u32 sampleNum, u32 *descIndex);
Bool gf_hinter_can_embbed_data(u8 *data, u32 size, GF_StreamType type);
void InitSL_NULL(GF_SLConfig *slc);
void gf_isom_set_extraction_slc(GF_ISOFile *file, u32 track, u32 descIndex, GF_SLConfig *slc);
u32 gf_base64_encode(u8 *in, u32 in_size, char *out, u32 out_size);
void gf_isom_sample_del(GF_ISOSample **samp);
void gf_odf_desc_del(GF_Descriptor *desc);
void gf_list_rem(void *list, u32 index);
void *gf_list_get(void *list, u32 index);
u32 gf_list_count(void *list);
void gf_list_add(void *list, void *item);
u32 gf_isom_get_media_timescale(GF_ISOFile *file, u32 track);
void gf_free(void *ptr);
void *gf_malloc(size_t size);
void gf_odf_desc_write(GF_Descriptor *desc, u8 **buffer, u32 *size);
void GF_LOG(GF_LogLevel level, GF_LogCategory category, const char *fmt, ...);