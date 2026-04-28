#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_ISOM_INVALID_MEDIA,
    GF_OUT_OF_MEM,
    GF_ISOM_INVALID_FILE
} GF_Err;

typedef struct GF_List {
    u32 count;
    void **entries;
} GF_List;

typedef struct GF_Box {
    u32 type;
    struct GF_Box *parent;
    GF_List *child_boxes;
} GF_Box;

typedef struct GF_SampleDescriptionBox {
    GF_List *child_boxes;
} GF_SampleDescriptionBox;

typedef struct GF_ESD {
    struct {
        u32 streamType;
        u32 objectTypeIndication;
        struct {
            char *data;
            u32 dataLength;
        } *decoderSpecificInfo;
    } *decoderConfig;
} GF_ESD;

typedef struct GF_ESDBox {
    GF_Box box;
    GF_ESD *desc;
} GF_ESDBox;

typedef struct GF_MPEGSampleEntryBox {
    GF_Box box;
    u32 internal_type;
    GF_ESDBox *esd;
    GF_List *child_boxes;
    u32 type;
} GF_MPEGSampleEntryBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    GF_MPEGSampleEntryBox entry;
    GF_ESDBox *esd;
    GF_ESD *emul_esd;
} GF_MPEGVisualSampleEntryBox;

typedef struct GF_MPEGAudioSampleEntryBox {
    GF_MPEGSampleEntryBox entry;
    GF_ESDBox *esd;
    u32 channel_count;
    u32 samplerate_hi;
    struct GF_OpusSpecificBox *cfg_opus;
    struct {
        u8 configuration_version;
        u8 mha_pl_indication;
        u8 reference_channel_layout;
        u16 mha_config_size;
        char *mha_config;
    } *cfg_mha;
} GF_MPEGAudioSampleEntryBox;

typedef struct GF_GenericAudioSampleEntryBox {
    GF_MPEGSampleEntryBox entry;
} GF_GenericAudioSampleEntryBox;

typedef struct GF_ProtectionSchemeInfoBox {
    GF_Box box;
    struct {
        u32 data_format;
    } *original_format;
} GF_ProtectionSchemeInfoBox;

typedef struct GF_Descriptor {
    u8 tag;
} GF_Descriptor;

typedef struct GF_WebVTTSampleEntryBox {
    GF_MPEGSampleEntryBox entry;
    struct {
        char *string;
    } *config;
} GF_WebVTTSampleEntryBox;

typedef struct GF_LASeRSampleEntryBox {
    GF_MPEGSampleEntryBox entry;
    struct {
        char *hdr;
        u32 hdr_size;
    } *lsr_config;
} GF_LASeRSampleEntryBox;

typedef struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_MediaTrack {
    u32 extractor_mode;
    struct GF_MovieBox *moov;
} GF_MediaTrack;

typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
    GF_MediaTrack *mediaTrack;
} GF_MediaBox;

typedef struct GF_MovieBox {
    struct {
        int convert_streaming_text;
    } *mov;
} GF_MovieBox;

typedef struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_BitStream {
    void *buffer;
    u64 size;
    u32 mode;
} GF_BitStream;

typedef struct GF_M4ADecSpecInfo {
    u32 nb_chan;
    u32 base_object_type;
    u32 base_sr;
} GF_M4ADecSpecInfo;

typedef struct GF_OpusSpecificBox {
    GF_Box box;
} GF_OpusSpecificBox;

#define GF_ISOM_BOX_TYPE_ENCV 0x656E6376
#define GF_ISOM_BOX_TYPE_ENCA 0x656E6361
#define GF_ISOM_BOX_TYPE_ENCS 0x656E6373
#define GF_ISOM_BOX_TYPE_ENCF 0x656E6366
#define GF_ISOM_BOX_TYPE_ENCM 0x656E636D
#define GF_ISOM_BOX_TYPE_ENCT 0x656E6374
#define GF_ISOM_BOX_TYPE_SINF 0x73696E66
#define GF_ISOM_BOX_TYPE_RESV 0x72657376
#define GF_ISOM_BOX_TYPE_RINF 0x72696E66
#define GF_ISOM_BOX_TYPE_MP4V 0x6D703476
#define GF_ISOM_BOX_TYPE_AVC1 0x61766331
#define GF_ISOM_BOX_TYPE_AVC2 0x61766332
#define GF_ISOM_BOX_TYPE_AVC3 0x61766333
#define GF_ISOM_BOX_TYPE_AVC4 0x61766334
#define GF_ISOM_BOX_TYPE_HVC1 0x68766331
#define GF_ISOM_BOX_TYPE_HEV1 0x68657631
#define GF_ISOM_BOX_TYPE_HVC2 0x68766332
#define GF_ISOM_BOX_TYPE_HEV2 0x68657632
#define GF_ISOM_BOX_TYPE_HVT1 0x68767431
#define GF_ISOM_BOX_TYPE_264B 0x32363462
#define GF_ISOM_BOX_TYPE_265B 0x32363562
#define GF_ISOM_BOX_TYPE_DVHE 0x64766865
#define GF_ISOM_BOX_TYPE_VVC1 0x76766331
#define GF_ISOM_BOX_TYPE_VVI1 0x76766931
#define GF_ISOM_BOX_TYPE_SVC1 0x73766331
#define GF_ISOM_BOX_TYPE_MVC1 0x6D766331
#define GF_ISOM_BOX_TYPE_LHE1 0x6C686531
#define GF_ISOM_BOX_TYPE_LHV1 0x6C687631
#define GF_ISOM_BOX_TYPE_AV01 0x61763031
#define GF_ISOM_BOX_TYPE_VP08 0x76703038
#define GF_ISOM_BOX_TYPE_VP09 0x76703039
#define GF_ISOM_BOX_TYPE_MP4A 0x6D703461
#define GF_ISOM_BOX_TYPE_MP4S 0x6D703473
#define GF_ISOM_BOX_TYPE_TX3G 0x74783367
#define GF_ISOM_BOX_TYPE_TEXT 0x74657874
#define GF_ISOM_BOX_TYPE_WVTT 0x77767474
#define GF_ISOM_BOX_TYPE_STPP 0x73747070
#define GF_ISOM_BOX_TYPE_SBTT 0x73627474
#define GF_ISOM_BOX_TYPE_STXT 0x73747874

#define GF_ISOM_SAMPLE_ENTRY_VIDEO 1
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 2
#define GF_ISOM_SAMPLE_ENTRY_MP4S 3

#define GF_ISOM_NALU_EXTRACT_INSPECT 1

#define GF_STREAM_AUDIO 1
#define GF_STREAM_VISUAL 2
#define GF_STREAM_TEXT 3
#define GF_STREAM_SCENE 4

#define GF_CODECID_AAC_MPEG4 0x40
#define GF_CODECID_WEBVTT 0xE0
#define GF_CODECID_H263 0x20
#define GF_CODECID_MPEG_AUDIO 0x69
#define GF_CODECID_LASER 0xE1
#define GF_CODECID_MPHA 0xFF
#define GF_CODECID_MHAS 0xFE
#define GF_CODECID_OPUS 0xAD

#define GF_M4A_AAC_LC 0x02

#define GF_ISOM_SUBTYPE_3GP_AMR 0x73616D72
#define GF_ISOM_SUBTYPE_3GP_AMR_WB 0x73617762
#define GF_ISOM_SUBTYPE_3GP_EVRC 0x73657663
#define GF_ISOM_SUBTYPE_3GP_QCELP 0x73716376
#define GF_ISOM_SUBTYPE_3GP_SMV 0x73736D76
#define GF_ISOM_SUBTYPE_OPUS 0x6F707573
#define GF_ISOM_SUBTYPE_3GP_H263 0x73323633
#define GF_ISOM_SUBTYPE_MP3 0x6D7033
#define GF_ISOM_SUBTYPE_LSR1 0x6C737231
#define GF_ISOM_SUBTYPE_MH3D_MHA1 0x6D686131
#define GF_ISOM_SUBTYPE_MH3D_MHA2 0x6D686132
#define GF_ISOM_SUBTYPE_MH3D_MHM1 0x6D686D31
#define GF_ISOM_SUBTYPE_MH3D_MHM2 0x6D686D32

#define GF_BITSTREAM_WRITE 1
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

GF_Box *gf_isom_box_find_child(GF_List *child_boxes, u32 box_type);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 position);
GF_ESD *gf_odf_desc_esd_new(u8 tag);
GF_Err gf_odf_desc_copy(GF_Descriptor *desc, GF_Descriptor **out_desc);
void gf_m4a_write_config(GF_M4ADecSpecInfo *aacinfo, char **data, u32 *dataLength);
GF_BitStream *gf_bs_new(void *buffer, u64 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);
void gf_bs_get_content(GF_BitStream *bs, char **output, u32 *outSize);
void gf_bs_write_u8(GF_BitStream *bs, u32 value);
void gf_bs_write_u16(GF_BitStream *bs, u32 value);
void gf_bs_write_data(GF_BitStream *bs, const void *data, u32 length);
u32 gf_isom_box_size(GF_Box *box);
void gf_isom_box_write(GF_Box *box, GF_BitStream *bs);
void *gf_malloc(u32 size);
void gf_log(u32 log_level, u32 log_tool, const char *format, ...);
GF_Err gf_isom_get_ttxt_esd(GF_MediaBox *mdia, GF_ESD **out_esd);
GF_Err gf_isom_get_3gpp_audio_esd(GF_SampleTableBox *stsd, u32 type, GF_GenericAudioSampleEntryBox *entry, GF_ESD **out_esd);
GF_Err AVC_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
GF_Err HEVC_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
GF_Err AV1_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
GF_Err VP9_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);