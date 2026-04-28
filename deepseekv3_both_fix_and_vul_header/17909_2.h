#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVIOContext {
    uint8_t *buf;
    int pos;
    int eof_reached;
} AVIOContext;

typedef struct AVPacket {
    int stream_index;
} AVPacket;

typedef struct AVStream {
    int id;
} AVStream;

typedef struct AVFormatContext {
    AVStream **streams;
    int nb_streams;
    void *priv_data;
    AVIOContext *pb;
} AVFormatContext;

typedef struct PayloadContext {
    AVIOContext pb;
    uint8_t *buf;
    AVIOContext *pktbuf;
} PayloadContext;

typedef struct RTSPState {
    AVFormatContext *asf_ctx;
    int asf_pb_pos;
} RTSPState;

#define RTP_FLAG_KEY   0x1
#define RTP_FLAG_MARKER 0x2

#define AVERROR(e) (-(e))
#define EIO 5

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

static void av_freep(void *ptr) { free(*(void**)ptr); *(void**)ptr = NULL; }
static void *av_realloc(void *ptr, size_t size) { return realloc(ptr, size); }
static void av_free(void *ptr) { free(ptr); }
static void av_free_packet(AVPacket *pkt) {}

static int avio_tell(AVIOContext *s) { return s->pos; }
static int avio_r8(AVIOContext *s) { return s->buf[s->pos++]; }
static int avio_rb24(AVIOContext *s) { 
    return (avio_r8(s) << 16) | (avio_r8(s) << 8) | avio_r8(s); 
}
static void avio_skip(AVIOContext *s, int len) { s->pos += len; }
static void avio_write(AVIOContext *s, const uint8_t *buf, int len) { 
    memcpy(s->buf + s->pos, buf, len); s->pos += len; 
}

static int avio_open_dyn_buf(AVIOContext **s) { return 0; }
static int avio_close_dyn_buf(AVIOContext *s, uint8_t **pbuf) { return 0; }
static void ffio_init_context(AVIOContext *s, const uint8_t *buf, int buf_size, 
                             int write_flag, void *opaque, 
                             int (*read_packet)(void *, uint8_t *, int),
                             int (*write_packet)(void *, uint8_t *, int),
                             int64_t (*seek)(void *, int64_t, int)) {
    s->buf = (uint8_t*)buf;
    s->pos = 0;
    s->eof_reached = 0;
}

static int av_read_packet(AVFormatContext *s, AVPacket *pkt) { return 0; }
static void init_packetizer(AVIOContext *s, uint8_t *buf, int len) {}