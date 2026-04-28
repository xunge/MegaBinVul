#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int GF_Err;

#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_ISOM_INVALID_MEDIA 2
#define GF_NOT_SUPPORTED 3
#define GF_OUT_OF_MEM 4

#define GF_FALSE 0
#define GF_TRUE 1

#define GF_STREAM_AUDIO 0
#define GF_STREAM_VISUAL 1
#define GF_STREAM_TEXT 2
#define GF_STREAM_SCENE 3

#define GF_CODECID_AAC_MPEG4 0
#define GF_CODECID_MPEG_AUDIO 1
#define GF_CODECID_H263 2
#define GF_CODECID_LASER 3
#define GF_CODECID_MPHA 4
#define GF_CODECID_MHAS 5
#define GF_CODECID_OPUS 6
#define GF_CODECID_WEBVTT 7

#define GF_ISOM_BOX_TYPE_ENCV 0
#define GF_ISOM_BOX_TYPE_ENCA 1
#define GF_ISOM_BOX_TYPE_ENCS 2
#define GF_ISOM_BOX_TYPE_ENCF 3
#define GF_ISOM_BOX_TYPE_ENCM 4
#define GF_ISOM_BOX_TYPE_ENCT 5
#define GF_ISOM_BOX_TYPE_SINF 6
#define GF_ISOM_BOX_TYPE_RESV 7
#define GF_ISOM_BOX_TYPE_RINF 8
#define GF_ISOM_BOX_TYPE_MP4V 9
#define GF_ISOM_BOX_TYPE_AVC1 10
#define GF_ISOM_BOX_TYPE_AVC2 11
#define GF_ISOM_BOX_TYPE_AVC3 12
#define GF_ISOM_BOX_TYPE_AVC4 13
#define GF_ISOM_BOX_TYPE_HVC1 14
#define GF_ISOM_BOX_TYPE_HEV1 15
#define GF_ISOM_BOX_TYPE_HVC2 16
#define GF_ISOM_BOX_TYPE_HEV2 17
#define GF_ISOM_BOX_TYPE_HVT1 18
#define GF_ISOM_BOX_TYPE_264B 19
#define GF_ISOM_BOX_TYPE_265B 20
#define GF_ISOM_BOX_TYPE_DVHE 21
#define GF_ISOM_BOX_TYPE_DVH1 22
#define GF_ISOM_BOX_TYPE_DVA1 23
#define GF_ISOM_BOX_TYPE_DVAV 24
#define GF_ISOM_BOX_TYPE_VVC1 25
#define GF_ISOM_BOX_TYPE_VVI1 26
#define GF_ISOM_BOX_TYPE_SVC1 27
#define GF_ISOM_BOX_TYPE_MVC1 28
#define GF_ISOM_BOX_TYPE_LHE1 29
#define GF_ISOM_BOX_TYPE_LHV1 30
#define GF_ISOM_BOX_TYPE_DAV1 31
#define GF_ISOM_BOX_TYPE_AV01 32
#define GF_ISOM_BOX_TYPE_VP08 33
#define GF_ISOM_BOX_TYPE_VP09 34
#define GF_ISOM_BOX_TYPE_MP4A 35
#define GF_ISOM_BOX_TYPE_MP4S 36
#define GF_ISOM_BOX_TYPE_TX3G 37
#define GF_ISOM_BOX_TYPE_TEXT 38
#define GF_ISOM_BOX_TYPE_WVTT 39
#define GF_ISOM_BOX_TYPE_STPP 40
#define GF_ISOM_BOX_TYPE_SBTT 41
#define GF_ISOM_BOX_TYPE_STXT 42

#define GF_ISOM_SUBTYPE_3GP_AMR 43
#define GF_ISOM_SUBTYPE_3GP_AMR_WB 44
#define GF_ISOM_SUBTYPE_3GP_EVRC 45
#define GF_ISOM_SUBTYPE_3GP_QCELP 46
#define GF_ISOM_SUBTYPE_3GP_SMV 47
#define GF_ISOM_SUBTYPE_OPUS 48
#define GF_ISOM_SUBTYPE_3GP_H263 49
#define GF_ISOM_SUBTYPE_MP3 50
#define GF_ISOM_SUBTYPE_LSR1 51
#define GF_ISOM_SUBTYPE_MH3D_MHA1 52
#define GF_ISOM_SUBTYPE_MH3D_MHA2 53
#define GF_ISOM_SUBTYPE_MH3D_MHM1 54
#define GF_ISOM_SUBTYPE_MH3D_MHM2 55

#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 1
#define GF_ISOM_SAMPLE_ENTRY_MP4S 2
#define GF_ISOM_SAMPLE_ENTRY_GENERIC 3

#define GF_ISOM_NALU_EXTRACT_INSPECT 0
#define GF_M4A_AAC_LC 0
#define GF_BITSTREAM_WRITE 0

#define GF_LOG_WARNING 0
#define GF_LOG_CONTAINER 0

typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_ESD GF_ESD;
typedef struct GF_MPEGSampleEntryBox GF_MPEGSampleEntryBox;
typedef struct GF_ESDBox GF_ESDBox;
typedef struct GF_ProtectionSchemeInfoBox GF_ProtectionSchemeInfoBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;
typedef struct GF_MPEGAudioSampleEntryBox GF_MPEGAudioSampleEntryBox;
typedef struct GF_GenericAudioSampleEntryBox GF_GenericAudioSampleEntryBox;
typedef struct GF_WebVTTSampleEntryBox GF_WebVTTSampleEntryBox;
typedef struct GF_OpusSpecificBox GF_OpusSpecificBox;
typedef struct GF_LASeRSampleEntryBox GF_LASeRSampleEntryBox;
typedef struct GF_M4ADecSpecInfo GF_M4ADecSpecInfo;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Descriptor GF_Descriptor;

struct GF_MediaBox {
    struct {
        struct {
            GF_SampleDescriptionBox *SampleDescription;
        } *sampleTable;
    } *information;
    struct {
        u32 extractor_mode;
        struct {
            struct {
                Bool convert_streaming_text;
            } *mov;
        } *moov;
    } *mediaTrack;
};

struct GF_ESD {
    struct {
        u32 streamType;
        u32 objectTypeIndication;
        struct {
            u32 dataLength;
            void *data;
        } *decoderSpecificInfo;
    } *decoderConfig;
};

struct GF_MPEGSampleEntryBox {
    u32 type;
    u32 internal_type;
    struct {
        GF_ESDBox *esd;
        GF_OpusSpecificBox *cfg_opus;
        struct {
            u8 configuration_version;
            u8 mha_pl_indication;
            u8 reference_channel_layout;
            u16 mha_config_size;
            char *mha_config;
        } *cfg_mha;
    };
    struct {
        GF_ProtectionSchemeInfoBox *original_format;
    } *sinf;
    struct {
        GF_ESD *emul_esd;
    };
    struct {
        u32 channel_count;
        u32 samplerate_hi;
    };
    struct {
        char *string;
    } *config;
    struct {
        u32 hdr_size;
        char *hdr;
    } *lsr_config;
    void *child_boxes;
};

struct GF_ESDBox {
    GF_ESD *desc;
};

struct GF_ProtectionSchemeInfoBox {
    struct {
        u32 data_format;
    } *original_format;
};

struct GF_SampleDescriptionBox {
    void *child_boxes;
};

struct GF_MPEGVisualSampleEntryBox {
    GF_ESDBox *esd;
    GF_ESD *emul_esd;
    void *child_boxes;
};

struct GF_MPEGAudioSampleEntryBox {
    GF_ESDBox *esd;
    GF_OpusSpecificBox *cfg_opus;
    struct {
        u8 configuration_version;
        u8 mha_pl_indication;
        u8 reference_channel_layout;
        u16 mha_config_size;
        char *mha_config;
    } *cfg_mha;
    u32 channel_count;
    u32 samplerate_hi;
    void *child_boxes;
};

struct GF_GenericAudioSampleEntryBox {
    void *child_boxes;
};

struct GF_WebVTTSampleEntryBox {
    struct {
        char *string;
    } *config;
};

struct GF_OpusSpecificBox {
    struct {
        void *data;
        u32 dataLength;
    } opcfg;
};

struct GF_LASeRSampleEntryBox {
    struct {
        u32 hdr_size;
        char *hdr;
    } *lsr_config;
};

struct GF_M4ADecSpecInfo {
    u32 nb_chan;
    u32 base_object_type;
    u32 base_sr;
};

struct GF_BitStream {
    void *data;
    u32 size;
    u32 position;
};

extern GF_Err gf_isom_box_find_child(void *child_boxes, u32 type);
extern GF_Err gf_isom_get_ttxt_esd(GF_MediaBox *mdia, GF_ESD **out_esd);
extern GF_Err gf_isom_get_3gpp_audio_esd(void *sampleTable, u32 type, GF_GenericAudioSampleEntryBox *entry, GF_ESD **out_esd);
extern GF_ESD *gf_odf_desc_esd_new(u32 trackID);
extern GF_Err gf_odf_desc_copy(GF_Descriptor *desc, GF_Descriptor **out_desc);
extern void *gf_list_get(void *list, u32 index);
extern u32 gf_list_count(void *list);
extern void *gf_malloc(u32 size);
extern GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode);
extern void gf_bs_write_u8(GF_BitStream *bs, u8 value);
extern void gf_bs_write_u16(GF_BitStream *bs, u16 value);
extern void gf_bs_write_data(GF_BitStream *bs, void *data, u32 size);
extern void gf_bs_get_content(GF_BitStream *bs, void **data, u32 *size);
extern void gf_bs_del(GF_BitStream *bs);
extern void gf_m4a_write_config(GF_M4ADecSpecInfo *aacinfo, void **data, u32 *size);
extern void gf_odf_opus_cfg_write(void *opcfg, void **data, u32 *size);
extern GF_Err AVC_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
extern GF_Err HEVC_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
extern GF_Err AV1_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
extern GF_Err VP9_RewriteESDescriptorEx(GF_MPEGVisualSampleEntryBox *entry, GF_MediaBox *mdia);
extern void GF_LOG(u32 level, u32 category, const char *message);