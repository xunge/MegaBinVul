#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

struct AVIOContext;
struct AVStream;
struct AVCodecContext;
struct FLVContext;
struct FLVStreamContext;

typedef struct AVPacket {
    int stream_index;
    int64_t dts;
    int64_t pts;
    int64_t duration;
    uint8_t *data;
    int size;
    int flags;
} AVPacket;

typedef struct AVFormatContext {
    struct AVIOContext *pb;
    struct AVStream **streams;
    int nb_streams;
    void *priv_data;
    int event_flags;
} AVFormatContext;

#define AV_NOPTS_VALUE INT64_MIN
#define AV_LOG_WARNING 24
#define AV_LOG_ERROR 16
#define AVERROR(e) (-(e))
#define EINVAL 22
#define AVERROR_INVALIDDATA (-0x3ebacb)
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define AV_RB16(x) ((((const uint8_t*)(x))[0] << 8) | ((const uint8_t*)(x))[1])
#define AV_PKT_FLAG_KEY 0x0001
#define SEEK_SET 0
#define SEEK_CUR 1
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))

enum AVMediaType {
    AVMEDIA_TYPE_UNKNOWN = -1,
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA,
    AVMEDIA_TYPE_SUBTITLE,
};

enum AVCodecID {
    AV_CODEC_ID_NONE,
    AV_CODEC_ID_VP6F,
    AV_CODEC_ID_VP6A,
    AV_CODEC_ID_VP6,
    AV_CODEC_ID_AAC,
    AV_CODEC_ID_H264,
    AV_CODEC_ID_MPEG4,
    AV_CODEC_ID_SPEEX,
    AV_CODEC_ID_TEXT,
};

enum {
    FLV_TAG_TYPE_AUDIO = 8,
    FLV_TAG_TYPE_VIDEO = 9,
    FLV_TAG_TYPE_META = 18,
    FLV_FRAME_KEY = 1,
    FLV_FRAME_INTER = 3,
};

enum {
    AMF_DATA_TYPE_STRING = 2,
    AMF_DATA_TYPE_MIXEDARRAY = 8,
    AMF_END_OF_OBJECT = 9,
};

enum {
    AVSTREAM_EVENT_FLAG_METADATA_UPDATED = 1,
};

typedef struct AVCodecContext {
    int codec_type;
    int codec_id;
    int width;
    int height;
    uint8_t *extradata;
    int extradata_size;
} AVCodecContext;

typedef struct AVStream {
    AVCodecContext *codec;
    void *priv_data;
    int nb_frames;
} AVStream;

typedef struct AVIOContext {
    int error;
} AVIOContext;

typedef struct FLVContext {
    int64_t delay;
    int64_t duration;
    int reserved;
} FLVContext;

typedef struct FLVStreamContext {
    unsigned last_ts;
} FLVStreamContext;

static const int flv_video_codec_ids[] = {0};