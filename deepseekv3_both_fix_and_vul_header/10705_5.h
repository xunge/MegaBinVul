#include <stdint.h>
#include <string.h>
#include <limits.h>

#define AVPROBE_PADDING_SIZE 32
#define AVPROBE_SCORE_EXTENSION 25

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVIOContext {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
} AVIOContext;

struct AVRational {
    int num;
    int den;
};

typedef struct AVStream {
    void *priv_data;
    void *metadata;
    void *codecpar;
    struct AVRational time_base;
} AVStream;

typedef struct AVFormatContext {
    AVIOContext *pb;
    int nb_streams;
    AVStream **streams;
} AVFormatContext;

typedef struct AVInputFormat {
    const char *name;
} AVInputFormat;

typedef struct AVProbeData {
    unsigned char *buf;
    int buf_size;
} AVProbeData;

typedef struct AVIStream {
    AVFormatContext *sub_ctx;
    AVPacket sub_pkt;
    uint8_t *sub_buffer;
} AVIStream;

static uint16_t AV_RL16(const uint8_t *p) { return p[0] | (p[1] << 8); }
static uint16_t avio_rl16(AVIOContext *s) { return 0; }
static uint32_t avio_rl32(AVIOContext *s) { return 0; }
static int avio_get_str16le(AVIOContext *pb, int maxlen, char *buf, int buflen) { return 0; }
static void avio_skip(AVIOContext *s, int64_t offset) {}
static void av_dict_set(void **pm, const char *key, const char *value, int flags) {}
static AVIOContext *avio_alloc_context(unsigned char *buffer, int buffer_size, int write_flag, void *opaque, int (*read_packet)(void *opaque, uint8_t *buf, int buf_size), int (*write_packet)(void *opaque, uint8_t *buf, int buf_size), int64_t (*seek)(void *opaque, int64_t offset, int whence)) { return NULL; }
static void *av_mallocz(size_t size) { return NULL; }
static void av_freep(void *ptr) {}
static AVInputFormat *av_probe_input_format2(AVProbeData *pd, int is_opened, int *score_max) { return NULL; }
static AVFormatContext *avformat_alloc_context(void) { return NULL; }
static int avformat_open_input(AVFormatContext **ps, const char *filename, AVInputFormat *fmt, void *options) { return 0; }
static void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, unsigned int pts_num, unsigned int pts_den) {}
static int ff_copy_whiteblacklists(AVFormatContext *d, AVFormatContext *s) { return 0; }
static int ff_read_packet(AVFormatContext *s, AVPacket *pkt) { return 0; }
static void avcodec_parameters_copy(void *dst, const void *src) {}

typedef struct AVRational AVRational;