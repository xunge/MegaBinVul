#include <stdint.h>
#include <string.h>

typedef struct AVCodecContext {
    int codec_id;
    int codec_type;
    int extradata_size;
    uint8_t *extradata;
} AVCodecContext;

typedef struct AVDictionaryEntry {
    char *value;
} AVDictionaryEntry;

typedef struct AVStream {
    void *priv_data;
    void *metadata;
    AVCodecContext *codec;
    int disposition;
} AVStream;

typedef struct AVFormatContext {
    void *priv_data;
    int nb_streams;
    AVStream **streams;
} AVFormatContext;

typedef struct MpegTSService {
    int pcr_pid;
    void *pmt;
    int sid;
} MpegTSService;

typedef struct MpegTSWrite {
    int flags;
    int tables_version;
} MpegTSWrite;

typedef struct MpegTSWriteStream {
    int pid;
} MpegTSWriteStream;

#define AV_CODEC_ID_MPEG1VIDEO 0
#define AV_CODEC_ID_MPEG2VIDEO 1
#define AV_CODEC_ID_MPEG4 2
#define AV_CODEC_ID_H264 3
#define AV_CODEC_ID_CAVS 4
#define AV_CODEC_ID_DIRAC 5
#define AV_CODEC_ID_MP2 6
#define AV_CODEC_ID_MP3 7
#define AV_CODEC_ID_AAC 8
#define AV_CODEC_ID_AAC_LATM 9
#define AV_CODEC_ID_AC3 10
#define AV_CODEC_ID_EAC3 11
#define AV_CODEC_ID_S302M 12
#define AV_CODEC_ID_DVB_SUBTITLE 13
#define AV_CODEC_ID_DVB_TELETEXT 14
#define AV_CODEC_ID_SMPTE_KLV 15

#define STREAM_TYPE_VIDEO_MPEG2 1
#define STREAM_TYPE_VIDEO_MPEG4 2
#define STREAM_TYPE_VIDEO_H264 3
#define STREAM_TYPE_VIDEO_CAVS 4
#define STREAM_TYPE_VIDEO_DIRAC 5
#define STREAM_TYPE_AUDIO_MPEG1 6
#define STREAM_TYPE_AUDIO_AAC 7
#define STREAM_TYPE_AUDIO_AAC_LATM 8
#define STREAM_TYPE_AUDIO_AC3 9
#define STREAM_TYPE_PRIVATE_DATA 10

#define AVMEDIA_TYPE_VIDEO 0
#define AVMEDIA_TYPE_AUDIO 1
#define AVMEDIA_TYPE_SUBTITLE 2
#define AVMEDIA_TYPE_DATA 3

#define AV_DISPOSITION_CLEAN_EFFECTS 1
#define AV_DISPOSITION_HEARING_IMPAIRED 2
#define AV_DISPOSITION_VISUAL_IMPAIRED 4

#define PMT_TID 2
#define MPEGTS_FLAG_AAC_LATM 1
#define AVERROR(e) (-(e))
#define EINVAL 22

static void put16(uint8_t **q, int val);
static void mpegts_write_section1(void *pmt, int tid, int sid, int version, int current_next, int section_number, uint8_t *buf, int len);
static AVDictionaryEntry *av_dict_get(void *metadata, const char *key, const AVDictionaryEntry *prev, int flags);