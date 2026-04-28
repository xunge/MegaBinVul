#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define MAX_TOC_ENTRIES 100
#define MAX_DICTIONARY_ENTRIES 100
#define TEA_BLOCK_SIZE 8
#define MP3_FRAME_SIZE 1152
#define TIMEPREC 1000
#define CHAPTER_HEADER_SIZE 8

typedef struct AVFormatContext AVFormatContext;
typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct AVDictionary AVDictionary;
typedef struct AADemuxContext AADemuxContext;
typedef struct AVCodecParameters AVCodecParameters;
typedef struct AVChapter AVChapter;
typedef struct AVRational {
    int num;
    int den;
} AVRational;

enum AVMediaType {
    AVMEDIA_TYPE_AUDIO
};

enum AVCodecID {
    AV_CODEC_ID_MP3,
    AV_CODEC_ID_SIPR
};

enum AVStreamParseType {
    AVSTREAM_PARSE_FULL_RAW
};

enum AVLogLevel {
    AV_LOG_DEBUG,
    AV_LOG_ERROR
};

#define AVERROR(e) (-(e))
#define AVERROR_INVALIDDATA AVERROR(EINVAL)
#define AVERROR(EINVAL) (-EINVAL)
#define AVERROR(ENOMEM) (-ENOMEM)

struct toc_entry {
    uint32_t offset;
    uint32_t size;
};

struct AVStream {
    AVCodecParameters *codecpar;
    int need_parsing;
    int64_t start_time;
    int64_t duration;
    AVRational time_base;
};

struct AVFormatContext {
    AVDictionary *metadata;
    AVIOContext *pb;
    void *priv_data;
    int nb_chapters;
};

struct AADemuxContext {
    uint8_t aa_fixed_key[16];
    int aa_fixed_key_len;
    int codec_second_size;
    void *tea_ctx;
    uint8_t file_key[16];
    uint32_t content_start;
    uint32_t content_end;
    uint32_t current_chapter_size;
    uint32_t seek_offset;
};

struct AVCodecParameters {
    enum AVMediaType codec_type;
    enum AVCodecID codec_id;
    int sample_rate;
    int block_align;
    int channels;
    int bit_rate;
};

uint32_t avio_rb32(AVIOContext *s);
void avio_skip(AVIOContext *s, int64_t offset);
int avio_get_str(AVIOContext *pb, int maxlen, char *buf, int buflen);
void av_log(void *avcl, int level, const char *fmt, ...);
void av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);
int64_t avio_tell(AVIOContext *s);
int64_t avio_seek(AVIOContext *s, int64_t offset, int whence);
AVStream *avformat_new_stream(AVFormatContext *s, const void *id);
void av_freep(void *ptr);
void *av_tea_alloc(void);
void av_tea_init(void *ctx, const uint8_t key[16], int rounds);
void av_tea_crypt(void *ctx, uint8_t *dst, const uint8_t *src, int count, uint8_t *iv, int decrypt);
void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, unsigned int pts_num, unsigned int pts_den);
AVChapter *avpriv_new_chapter(AVFormatContext *s, int id, AVRational time_base, int64_t start, int64_t end, const char *title);
void ff_update_cur_dts(AVFormatContext *s, AVStream *st, int64_t timestamp);
int get_second_size(const char *codec_name);

#define AV_WB32(p, d) do { \
        ((uint8_t*)(p))[0] = (d) >> 24; \
        ((uint8_t*)(p))[1] = (d) >> 16; \
        ((uint8_t*)(p))[2] = (d) >> 8; \
        ((uint8_t*)(p))[3] = (d); \
    } while(0)

#define SCNu32 "u"