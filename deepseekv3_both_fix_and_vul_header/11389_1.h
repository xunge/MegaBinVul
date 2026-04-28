#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define AV_NOPTS_VALUE INT64_MIN
#define AV_TIME_BASE 1000000
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AV_LOG_WARNING 24
#define AV_LOG_ERROR 16
#define AV_PKT_FLAG_KEY (1 << 0)
#define AVSTREAM_EVENT_FLAG_METADATA_UPDATED (1 << 0)
#define AV_PKT_DATA_NEW_EXTRADATA 0
#define AV_INPUT_BUFFER_PADDING_SIZE 32
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define SEEK_SET 0
#define SEEK_CUR 1
#define AVERROR_INVALIDDATA (-(EINVAL))

enum AVMediaType {
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA,
    AVMEDIA_TYPE_SUBTITLE
};

enum AVCodecID {
    AV_CODEC_ID_VP6F,
    AV_CODEC_ID_VP6A,
    AV_CODEC_ID_VP6,
    AV_CODEC_ID_AAC,
    AV_CODEC_ID_H264,
    AV_CODEC_ID_MPEG4,
    AV_CODEC_ID_SPEEX,
    AV_CODEC_ID_TEXT
};

enum {
    FLV_TAG_TYPE_VIDEO = 9,
    FLV_TAG_TYPE_AUDIO = 8,
    FLV_TAG_TYPE_META = 18
};

enum {
    FLV_FRAME_KEY = 1,
    FLV_FRAME_INTER = 3
};

enum {
    AMF_DATA_TYPE_STRING = 2,
    AMF_DATA_TYPE_MIXEDARRAY = 8,
    AMF_END_OF_OBJECT = 9
};

enum {
    FLV_ADD_KEYFRAME_INDEX = (1 << 0)
};

enum {
    AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT
};

typedef struct AVIOContext {
    int error;
} AVIOContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int stream_index;
    int64_t dts;
    int64_t pts;
    int64_t duration;
    int flags;
} AVPacket;

typedef struct AVCodecParameters {
    enum AVCodecID codec_id;
    enum AVMediaType codec_type;
    uint8_t *extradata;
    int extradata_size;
    int width;
    int height;
} AVCodecParameters;

typedef struct AVStream {
    AVCodecParameters *codecpar;
    void *priv_data;
    int nb_frames;
} AVStream;

typedef struct AVFormatContext {
    AVIOContext *pb;
    AVStream **streams;
    void *priv_data;
    unsigned int event_flags;
} AVFormatContext;

typedef struct FLVContext {
    int64_t delay;
    int64_t duration;
    int flags;
    int reserved;
    int videosize;
    int audiosize;
    double lasttimestamp;
    double lastkeyframetimestamp;
    int64_t lastkeyframelocation;
    int acurframeindex;
    double framerate;
    AVCodecParameters *video_par;
} FLVContext;

typedef struct FLVStreamContext {
    unsigned int last_ts;
} FLVStreamContext;

static const int flv_video_codec_ids[] = {0};

static inline uint16_t AV_RB16(const uint8_t *p) {
    return (p[0] << 8) | p[1];
}