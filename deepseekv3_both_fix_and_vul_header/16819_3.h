#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef double Double;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_NOT_SUPPORTED,
    GF_OUT_OF_MEM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Descriptor GF_Descriptor;

typedef struct {
    u32 timestampResolution;
    u32 AUSeqNumLength;
    u32 CUDuration;
    Bool useRandomAccessPointFlag;
    Bool hasRandomAccessUnitsOnlyFlag;
} GF_SLConfig;

typedef struct {
    u32 CodecID;
    u32 DTSDeltaLength;
} GF_SLMap;

typedef struct {
    GF_SLMap slMap;
    u32 flags;
} GF_RTPBuilder;

typedef struct {
    u8 *data;
    u32 dataLength;
} GF_ISOSample;

typedef struct {
    u32 TrackNum;
    u32 HintID;
    u32 HintTrack;
    u32 TrackID;
    u32 OrigTimeScale;
    u32 avc_nalu_size;
    u32 nb_chan;
    u32 bandwidth;
    Bool has_ctts;
    GF_ISOFile *file;
    GF_RTPBuilder *rtp_p;
} GF_RTPHinter;

typedef struct {
    u32 streamType;
    u32 objectTypeIndication;
    char *URLString;
    struct {
        u32 streamType;
        u32 objectTypeIndication;
        struct {
            u8 *data;
            u32 dataLength;
        } *decoderSpecificInfo;
    } *decoderConfig;
} GF_ESD;

typedef struct {
    u32 nal_unit_size;
} GF_AVCConfig;

typedef struct {
    u32 nal_unit_size;
} GF_HEVCConfig;

typedef struct {
    u32 nb_chan;
    u32 audioPL;
    u32 base_sr;
    u32 base_object_type;
} GF_M4ADecSpecInfo;

typedef struct {
    u32 VideoPL;
} GF_M4VDecSpecInfo;

typedef enum {
    GF_ISOM_MEDIA_HINT,
    GF_ISOM_MEDIA_TEXT,
    GF_ISOM_MEDIA_SUBT
} GF_ISOM_MediaType;

typedef enum {
    GF_ISOM_SUBTYPE_MPEG4,
    GF_ISOM_SUBTYPE_MPEG4_CRYP,
    GF_ISOM_SUBTYPE_3GP_H263,
    GF_ISOM_SUBTYPE_3GP_AMR,
    GF_ISOM_SUBTYPE_3GP_AMR_WB,
    GF_ISOM_SUBTYPE_AVC_H264,
    GF_ISOM_SUBTYPE_AVC2_H264,
    GF_ISOM_SUBTYPE_AVC3_H264,
    GF_ISOM_SUBTYPE_AVC4_H264,
    GF_ISOM_SUBTYPE_SVC_H264,
    GF_ISOM_SUBTYPE_MVC_H264,
    GF_ISOM_SUBTYPE_HVC1,
    GF_ISOM_SUBTYPE_HEV1,
    GF_ISOM_SUBTYPE_HVC2,
    GF_ISOM_SUBTYPE_HEV2,
    GF_ISOM_SUBTYPE_3GP_QCELP,
    GF_ISOM_SUBTYPE_3GP_EVRC,
    GF_ISOM_SUBTYPE_3GP_SMV,
    GF_ISOM_SUBTYPE_3GP_DIMS,
    GF_ISOM_SUBTYPE_AC3,
    GF_ISOM_SUBTYPE_MP3
} GF_ISOM_MediaSubType;

typedef enum {
    GF_ISOM_EDIT_EMPTY
} GF_ISOEditType;

typedef enum {
    GF_STREAM_AUDIO,
    GF_STREAM_VISUAL,
    GF_STREAM_TEXT,
    GF_STREAM_SCENE
} GF_StreamType;

typedef enum {
    GF_CODECID_TEXT_MPEG4,
    GF_CODECID_AAC_MPEG4,
    GF_CODECID_AAC_MPEG2_MP,
    GF_CODECID_AAC_MPEG2_LCP,
    GF_CODECID_AAC_MPEG2_SSRP,
    GF_CODECID_MPEG2_PART3,
    GF_CODECID_MPEG_AUDIO,
    GF_CODECID_QCELP,
    GF_CODECID_EVRC,
    GF_CODECID_SMV,
    GF_CODECID_MPEG4_PART2,
    GF_CODECID_MPEG2_SIMPLE,
    GF_CODECID_MPEG2_422,
    GF_CODECID_MPEG1,
    GF_CODECID_AVC,
    GF_CODECID_SVC,
    GF_CODECID_HEVC
} GF_CodecID;

typedef enum {
    GF_M4A_AAC_MAIN,
    GF_M4A_AAC_LC,
    GF_M4A_AAC_SBR,
    GF_M4A_AAC_PS,
    GF_M4A_AAC_LTP,
    GF_M4A_AAC_SCALABLE,
    GF_M4A_ER_AAC_LC,
    GF_M4A_ER_AAC_LTP,
    GF_M4A_ER_AAC_SCALABLE,
    GF_M4A_CELP,
    GF_M4A_ER_CELP
} GF_M4AObjectType;

typedef enum {
    GF_RTP_PAYT_3GPP_TEXT,
    GF_RTP_PAYT_MPEG4,
    GF_RTP_PAYT_LATM,
    GF_RTP_PAYT_MPEG12_AUDIO,
    GF_RTP_PAYT_QCELP,
    GF_RTP_PAYT_EVRC_SMV,
    GF_RTP_PAYT_MPEG12_VIDEO,
    GF_RTP_PAYT_H263,
    GF_RTP_PAYT_AMR,
    GF_RTP_PAYT_AMR_WB,
    GF_RTP_PAYT_H264_AVC,
    GF_RTP_PAYT_H264_SVC,
    GF_RTP_PAYT_HEVC,
    GF_RTP_PAYT_AC3,
    GF_RTP_PAYT_3GPP_DIMS
} GF_RTPPayloadType;

#define GP_RTP_PCK_USE_LATM_AAC 0x01
#define GP_RTP_PCK_FORCE_MPEG4 0x02
#define GP_RTP_PCK_USE_STATIC_ID 0x04
#define GP_RTP_PCK_USE_MULTI 0x08
#define GP_RTP_PCK_SIGNAL_RAP 0x10
#define GP_RTP_PCK_SIGNAL_TS 0x20
#define GP_RTP_PCK_SIGNAL_SIZE 0x40
#define GP_RTP_PCK_SYSTEMS_CAROUSEL 0x80
#define GP_RTP_PCK_SELECTIVE_ENCRYPTION 0x100

#define OFFSET_HINT_GROUP_ID 1000

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_LOG(log_level, log_category, message)
#define GF_EXPORT

static inline u32 GF_4CC(u32 a, u8 b, u8 c, u8 d) {
    return (a << 24) | (b << 16) | (c << 8) | d;
}

#define gf_isom_get_track_id(file, track) 0
#define gf_isom_get_sample_count(file, track) 0
#define gf_isom_get_edits_count(file, track) 0
#define gf_isom_get_edit(file, track, index, et, sd, mt, em)
#define gf_isom_remove_edits(file, track)
#define gf_isom_is_track_enabled(file, track) 1
#define gf_isom_get_media_type(file, track) 0
#define gf_isom_get_media_subtype(file, track, desc_index) 0
#define gf_isom_get_sample_description_count(file, track) 0
#define gf_isom_get_esd(file, track, desc_index) NULL
#define gf_isom_has_time_offset(file, track) 0
#define gf_isom_has_sync_points(file, track) 0
#define gf_isom_has_sync_shadows(file, track) 0
#define gf_isom_has_sample_dependency(file, track) 0
#define gf_isom_get_ismacryp_info(file, track, desc_index, a, b, c, d, e, f, g, h)
#define gf_isom_get_media_timescale(file, track) 0
#define gf_isom_get_track_by_id(file, id) NULL
#define gf_isom_new_track(file, id, type, timescale) 0
#define gf_isom_setup_hint_track(file, track, hint_type)
#define gf_isom_new_hint_description(file, track, a, b, c, d)
#define gf_isom_rtp_set_timescale(file, track, desc_index, timescale)
#define gf_isom_set_extraction_slc(file, track, desc_index, slc) GF_OK
#define gf_isom_set_track_interleaving_group(file, track, group)
#define gf_isom_set_track_priority_in_group(file, track, priority)
#define gf_isom_get_audio_info(file, track, desc_index, rate, channels, bps)
#define gf_isom_get_sample(file, track, sample_num, err) NULL
#define gf_isom_sample_del(sample)
#define gf_isom_get_data_reference(file, track, desc_index, url, urn)
#define gf_isom_avc_config_get(file, track, desc_index) NULL
#define gf_isom_svc_config_get(file, track, desc_index) NULL
#define gf_isom_mvc_config_get(file, track, desc_index) NULL
#define gf_isom_hevc_config_get(file, track, desc_index) NULL
#define gf_odf_desc_del(desc)
#define gf_odf_avc_cfg_del(cfg)
#define gf_odf_hevc_cfg_del(cfg)
#define gf_m4a_get_config(data, size, cfg)
#define gf_m4v_get_config(data, size, cfg)
#define gf_mp3_num_channels(hdr) 0
#define gf_get_bit_size(count) 0
#define gf_media_get_sample_average_infos(file, track, min, max, avg, delta, dur, bw)
#define gf_rtp_builder_new(type, sl, flags, ptr, a, b, c, d) NULL
#define gf_rtp_builder_init(rtp, pid, mtu, ptime, st, cid, pl, min, max, avg, delta, iv, ki, mode)
#define gf_hinter_track_del(hinter)
#define InitSL_RTP(sl)
#define MP4T_OnNewPacket
#define MP4T_OnPacketDone
#define MP4T_OnDataRef
#define MP4T_OnData