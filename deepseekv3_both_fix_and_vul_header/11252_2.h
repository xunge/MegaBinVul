#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 40
#define AV_INPUT_BUFFER_PADDING_SIZE 32
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define AVERROR(e) (-(e))
#define ENOMEM 12

typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;

typedef enum AVCodecID {
    AV_CODEC_ID_NONE
} AVCodecID;

typedef struct AVCodecParameters {
    int width;
    int height;
    unsigned int codec_tag;
    AVCodecID codec_id;
    unsigned char *extradata;
    int extradata_size;
} AVCodecParameters;

struct AVStream {
    AVCodecParameters *codecpar;
};

unsigned int ff_get_bmp_header(AVIOContext *pb, AVStream *st, uint32_t *size_bmp);
int avio_rl32(AVIOContext *pb);
int avio_rl16(AVIOContext *pb);
void avio_skip(AVIOContext *pb, int offset);
int avio_read(AVIOContext *pb, unsigned char *buf, int size);
void *av_malloc(size_t size);

typedef struct AVCodecTag {
    unsigned int id;
    unsigned int tag;
} AVCodecTag;

extern const AVCodecTag ff_codec_bmp_tags[];
AVCodecID ff_codec_get_id(const AVCodecTag *tags, unsigned int tag);