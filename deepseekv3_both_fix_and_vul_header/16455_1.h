#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct AVIOContext {
    uint8_t *buffer;
    int buffer_size;
    int64_t pos;
} AVIOContext;

typedef struct AVCodecParameters {
    int codec_type;
    int codec_id;
    int width;
    int height;
    int channels;
    int sample_rate;
    uint8_t *extradata;
    int extradata_size;
} AVCodecParameters;

typedef struct AVStream {
    int id;
    AVCodecParameters *codecpar;
    int nb_frames;
} AVStream;

typedef struct AVFormatContext {
    void *opaque;
} AVFormatContext;

typedef struct VividasDemuxContext {
    int num_audio;
} VividasDemuxContext;

enum AVMediaType {
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO
};

enum AVCodecID {
    AV_CODEC_ID_VP6,
    AV_CODEC_ID_VORBIS
};

#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
#define AVERROR_EOF 1
#define AVERROR_PATCHWELCOME 2
#define AVERROR(ENOMEM) 3
#define AVERROR_INVALIDDATA 4
#define SEEK_SET 0
#define SEEK_CUR 1

int ffio_read_varlen(AVIOContext *pb);
void ffio_init_context(AVIOContext *pb, uint8_t *buf, int size, int write_flag, void *opaque, int (*read_packet)(void *opaque, uint8_t *buf, int buf_size), int (*write_packet)(void *opaque, uint8_t *buf, int buf_size), int64_t (*seek)(void *opaque, int64_t offset, int whence));
int avio_feof(AVIOContext *s);
int avio_r8(AVIOContext *s);
int64_t avio_tell(AVIOContext *s);
int64_t avio_seek(AVIOContext *s, int64_t offset, int whence);
uint32_t avio_rl32(AVIOContext *s);
uint16_t avio_rl16(AVIOContext *s);
void av_log(AVFormatContext *s, int level, const char *fmt, ...);
AVStream *avformat_new_stream(AVFormatContext *s, void *codec);
void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, int num, int den);
int ff_alloc_extradata(AVCodecParameters *par, int size);
int avio_read(AVIOContext *s, uint8_t *buf, int size);
unsigned av_xiphlacing(uint8_t *s, unsigned v);
void av_freep(void *ptr);