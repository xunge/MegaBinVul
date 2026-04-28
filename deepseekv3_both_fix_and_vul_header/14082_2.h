#include <stdint.h>

typedef struct AVIOContext AVIOContext;
typedef struct AVFormatContext AVFormatContext;
typedef struct AVRational AVRational;
typedef struct ASFContext ASFContext;

struct AVFormatContext {
    AVIOContext *pb;
    void *priv_data;
};

struct AVRational {
    int num;
    int den;
};

struct ASFContext {
    struct {
        int preroll;
    } hdr;
};

#define AVERROR_INVALIDDATA (-1)
#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))

int avio_feof(AVIOContext *s);
int64_t avio_rl64(AVIOContext *s);
int32_t avio_rl32(AVIOContext *s);
int16_t avio_rl16(AVIOContext *s);
int avio_r8(AVIOContext *s);
void avio_skip(AVIOContext *s, int64_t offset);
int avio_get_str16le(AVIOContext *pb, int max_len, char *buf, int buf_size);
void avpriv_new_chapter(AVFormatContext *s, int id, AVRational time_base, int64_t start, int64_t end, const char *title);