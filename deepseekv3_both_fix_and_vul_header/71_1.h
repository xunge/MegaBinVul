#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;

typedef enum {
    GF_OK = 0,
    GF_ISOM_INVALID_FILE
} GF_Err;

typedef struct {
    u32 AVCProfileIndication;
    u32 profile_compatibility;
    u32 AVCLevelIndication;
} GF_AVCConfig;

typedef struct {
    u32 dataLength;
    u8 *data;
} GF_DecoderSpecificInfo;

typedef struct {
    GF_DecoderSpecificInfo *decoderSpecificInfo;
    u32 objectTypeIndication;
    u32 predefined_rvc_config;
    u32 rvc_config;
} GF_DecoderConfig;

typedef struct {
    GF_DecoderConfig *decoderConfig;
} GF_ESD;

typedef struct {
    u32 IV_length;
    u32 PayloadType;
    u32 rtp_payt;
    u32 auh_size;
    u32 timestampResolution;
    struct {
        u32 timestampResolution;
    } sl_config;
    struct {
        u32 IV_length;
    } slMap;
} GF_RTPPacket;

typedef struct {
    void *file;
    u32 TrackNum;
    u32 HintTrack;
    u32 bandwidth;
    u32 nb_chan;
    GF_RTPPacket *rtp_p;
} GF_RTPHinter;

typedef struct GF_BitStream GF_BitStream;

#define GF_EXPORT
#define GF_ISOM_MEDIA_SCENE 1
#define GF_ISOM_MEDIA_VISUAL 2
#define GF_ISOM_MEDIA_AUXV 3
#define GF_ISOM_MEDIA_PICT 4
#define GF_RTP_PAYT_H263 1
#define GF_RTP_PAYT_AMR 2
#define GF_RTP_PAYT_AMR_WB 3
#define GF_RTP_PAYT_3GPP_TEXT 4
#define GF_RTP_PAYT_EVRC_SMV 5
#define GF_RTP_PAYT_H264_AVC 6
#define GF_RTP_PAYT_H264_SVC 7
#define GF_RTP_PAYT_MPEG4 8
#define GF_RTP_PAYT_LATM 9
#define GF_RTP_PAYT_3GPP_DIMS 10
#define GF_CODECID_AVC 1
#define GF_CODECID_SVC 2
#define GF_RTP_TX3G_SIDX_OFFSET 0
#define GPAC_ENABLE_3GPP_DIMS_RTP 0
#define GF_BITSTREAM_WRITE 1
#define GF_TRUE 1
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef struct GF_Descriptor GF_Descriptor;

struct GF_DIMSDescription {
    u32 profile;
    Bool fullRequestHost;
    u32 pathComponents;
    u32 streamType;
    u32 containsRedundant;
    char *textEncoding;
    char *contentEncoding;
    char *content_script_types;
};