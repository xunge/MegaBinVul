#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef signed int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

#define GF_TRUE 1
#define GF_FALSE 0
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef enum {
    GF_OK = 0,
    GF_ISOM_INVALID_FILE,
} GF_Err;

typedef struct {
    u32 IV_length;
} GF_SLMap;

typedef struct {
    u32 timestampResolution;
} GF_SLConfig;

typedef struct {
    GF_SLMap slMap;
    GF_SLConfig sl_config;
    u32 PayloadType;
    u32 rtp_payt;
    u32 auh_size;
} GF_RTPPacket;

typedef struct {
    u32 dataLength;
    u8 *data;
} GF_DefaultDescriptor;

typedef struct {
    GF_DefaultDescriptor *decoderSpecificInfo;
    u32 predefined_rvc_config;
    u32 objectTypeIndication;
    u32 rvc_config;
} GF_DecoderConfig;

typedef struct GF_Descriptor {
    u32 tag;
} GF_Descriptor;

typedef struct {
    GF_DecoderConfig *decoderConfig;
} GF_ESD;

typedef struct {
    GF_RTPPacket *rtp_p;
    void *file;
    u32 TrackNum;
    u32 HintTrack;
    u32 bandwidth;
    u32 nb_chan;
} GF_RTPHinter;

typedef struct {
    u32 AVCProfileIndication;
    u32 profile_compatibility;
    u32 AVCLevelIndication;
} GF_AVCConfig;

typedef struct {
    u32 profile;
    char *fullRequestHost;
    u32 pathComponents;
    u32 streamType;
    u32 containsRedundant;
    char *textEncoding;
    char *contentEncoding;
    char *content_script_types;
} GF_DIMSDescription;

typedef struct GF_BitStream GF_BitStream;

#define GF_RTP_PAYT_H263 0
#define GF_RTP_PAYT_AMR 1
#define GF_RTP_PAYT_AMR_WB 2
#define GF_RTP_PAYT_3GPP_TEXT 3
#define GF_RTP_PAYT_EVRC_SMV 4
#define GF_RTP_PAYT_H264_AVC 5
#define GF_RTP_PAYT_H264_SVC 6
#define GF_RTP_PAYT_MPEG4 7
#define GF_RTP_PAYT_LATM 8
#define GF_RTP_PAYT_3GPP_DIMS 9

#define GF_ISOM_MEDIA_SCENE 0
#define GF_ISOM_MEDIA_VISUAL 1
#define GF_ISOM_MEDIA_AUXV 2
#define GF_ISOM_MEDIA_PICT 3

#define GF_CODECID_AVC 0
#define GF_CODECID_SVC 1

#define GF_RTP_TX3G_SIDX_OFFSET 0
#define GPAC_ENABLE_3GPP_DIMS_RTP 0

#define GF_BITSTREAM_WRITE 1

#define GF_EXPORT

void gf_free(void *ptr);
int strnicmp(const char *s1, const char *s2, size_t n);
size_t gf_base64_encode(const u8 *in, u32 in_size, char *out, u32 out_size);

void gf_isom_sdp_clean_track(void *file, u32 TrackNum);
u32 gf_isom_get_media_type(void *file, u32 TrackNum);
Bool gf_isom_is_video_handler_type(u32 mtype);
void gf_isom_get_visual_info(void *file, u32 TrackNum, u32 descIndex, u32 *Width, u32 *Height);
void gf_rtp_builder_get_payload_name(GF_RTPPacket *rtp_p, char *payloadName, char *mediaName);
void gf_isom_sdp_add_track_line(void *file, u32 HintTrack, char *sdpLine);
u32 gf_isom_get_track_id(void *file, u32 TrackNum);
void gf_isom_get_track_layout_info(void *file, u32 TrackNum, u32 *w, u32 *h, s32 *tx, s32 *ty, s16 *l);
u32 gf_isom_get_track_count(void *file);
void gf_media_format_ttxt_sdp(GF_RTPPacket *rtp_p, char *payloadName, char *sdpLine, u32 w, u32 h, s32 tx, s32 ty, s16 l, u32 m_w, u32 m_h, void *ptr);
u32 gf_isom_get_sample_description_count(void *file, u32 TrackNum);
void gf_isom_text_get_encoded_tx3g(void *file, u32 TrackNum, u32 descIndex, u32 offset, u8 **tx3g, u32 *tx3g_len);
GF_AVCConfig *gf_isom_avc_config_get(void *file, u32 TrackNum, u32 descIndex);
GF_AVCConfig *gf_isom_svc_config_get(void *file, u32 TrackNum, u32 descIndex);
void write_avc_config(char *sdpLine, GF_AVCConfig *avcc, GF_AVCConfig *svcc);
void gf_odf_avc_cfg_del(GF_AVCConfig *cfg);
GF_ESD *gf_isom_get_esd(void *file, u32 TrackNum, u32 descIndex);
void gf_rtp_builder_format_sdp(GF_RTPPacket *rtp_p, char *payloadName, char *sdpLine, u8 *data, u32 dataLength);
void gf_odf_desc_del(GF_Descriptor *desc);
void gf_isom_get_ismacryp_info(void *file, u32 TrackNum, u32 descIndex, void *ptr1, void *ptr2, void *ptr3, void *ptr4, const char **kms, void *ptr5, void *ptr6, void *ptr7);
void gf_isom_get_dims_description(void *file, u32 TrackNum, u32 descIndex, GF_DIMSDescription *dims);
void gf_isom_set_track_enabled(void *file, u32 TrackNum, Bool enable);

GF_BitStream *gf_bs_new(void *buffer, u32 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);
void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 nBits);
void gf_bs_write_data(GF_BitStream *bs, void *data, u32 length);
void gf_bs_get_content(GF_BitStream *bs, u8 **output, u32 *outSize);