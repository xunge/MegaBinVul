#include <stdint.h>
#include <stdlib.h>

typedef struct URLContext URLContext;

enum RTMPPacketType {
    RTMP_PS_ONEBYTE,
    RTMP_PS_FOURBYTES,
    RTMP_PS_TWELVEBYTES
};

#define AV_LOG_ERROR 16

typedef struct RTMPPacket {
    uint8_t *data;
    int size;
    int channel_id;
    enum RTMPPacketType type;
    uint32_t ts_field;
    uint32_t extra;
    int offset;
    int read;
    int timestamp;
} RTMPPacket;

#define AVERROR(e) (-(e))
#define EIO 5
#define EAGAIN 11
#define AV_RL16(p) ((p)[0] | ((p)[1] << 8))
#define AV_RB24(p) (((p)[0] << 16) | ((p)[1] << 8) | (p)[2])
#define AV_RB32(p) (((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3])
#define AV_RL32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#define FFMIN(a, b) ((a) > (b) ? (b) : (a))

int ffurl_read_complete(URLContext *h, uint8_t *buf, int size);
int ff_rtmp_check_alloc_array(RTMPPacket **prev_pkt_ptr, int *nb_prev_pkt, int channel_id);
int ff_rtmp_packet_create(RTMPPacket *p, int channel_id, enum RTMPPacketType type, int timestamp, int size);
void ff_rtmp_packet_destroy(RTMPPacket *p);
void av_log(void *avcl, int level, const char *fmt, ...);