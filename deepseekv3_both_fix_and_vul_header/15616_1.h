#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVBufferRef {
    uint8_t *data;
    int size;
} AVBufferRef;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVIOContext {
    // Minimal definition needed for compilation
} AVIOContext;

typedef struct AVFormatContext {
    void *priv_data;
    AVIOContext *pb;
} AVFormatContext;

typedef struct JXLAnimDemuxContext {
    AVBufferRef *initial;
} JXLAnimDemuxContext;

#define AVERROR(e) (-(e))
#define EDOM 33

int avio_size(AVIOContext *s);
int av_new_packet(AVPacket *pkt, int size);
void av_buffer_unref(AVBufferRef **buf);
int avio_read(AVIOContext *s, unsigned char *buf, int size);