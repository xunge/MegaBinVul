#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVFormatContext AVFormatContext;
typedef struct AVStream AVStream;
typedef struct AVCodecContext AVCodecContext;
typedef struct ogg ogg;
typedef struct ogg_stream ogg_stream;
typedef struct oggvorbis_private oggvorbis_private;

struct AVFormatContext {
    void *priv_data;
    AVStream **streams;
};

struct AVStream {
    AVCodecContext *codec;
};

struct AVCodecContext {
    int channels;
    int bit_rate;
    int sample_rate;
    int codec_type;
    int codec_id;
    uint8_t *extradata;
    int extradata_size;
};

struct ogg {
    ogg_stream *streams;
};

struct ogg_stream {
    uint8_t *buf;
    int pstart;
    int psize;
    oggvorbis_private *private;
};

struct oggvorbis_private {
    uint8_t *packet[3];
    int len[3];
    void *vp;
};

#define AV_CODEC_ID_VORBIS 1
#define AVMEDIA_TYPE_AUDIO 1
#define AV_LOG_ERROR 1
#define AVERROR(e) (-(e))
#define ENOMEM 1
#define AVERROR_INVALIDDATA 1
#define AVERROR_PATCHWELCOME 1

static unsigned int AV_RL32(const void *p);
static void AV_WL32(void *p, unsigned int v);
static void av_log(void *avcl, int level, const char *fmt, ...);
static void *av_mallocz(size_t size);
static void av_freep(void *ptr);
static void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, unsigned int pts_num, unsigned int pts_den);
static int avpriv_vorbis_parse_extradata(AVCodecContext *avctx, void **vp);
static unsigned int bytestream_get_le32(const uint8_t **p);
static unsigned char bytestream_get_byte(const uint8_t **p);
static int vorbis_update_metadata(AVFormatContext *s, int idx);
static int fixup_vorbis_headers(AVFormatContext *s, oggvorbis_private *priv, uint8_t **extradata);