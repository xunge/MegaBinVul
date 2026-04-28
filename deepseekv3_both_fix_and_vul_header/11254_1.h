#include <stdint.h>
#include <stdlib.h>

#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AVMEDIA_TYPE_DATA 4

typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct AVFormatContext AVFormatContext;
typedef struct AVCodecParameters AVCodecParameters;

struct AVStream {
    int id;
    AVCodecParameters *codecpar;
    int64_t start_time;
    int64_t duration;
    void *priv_data;
};

struct AVCodecParameters {
    int bit_rate;
    int codec_type;
};

struct AVFormatContext {
    AVIOContext *pb;
};

void *ff_rm_alloc_rmstream(void);
int ff_rm_read_mdpr_codecdata(AVFormatContext *s, AVIOContext *pb, AVStream *st, void *priv_data, unsigned size, char *mime);
AVStream *avformat_new_stream(AVFormatContext *s, void *codec);
uint16_t avio_rb16(AVIOContext *s);
uint32_t avio_rb32(AVIOContext *s);
void avpriv_request_sample(void *s, const char *msg, ...);