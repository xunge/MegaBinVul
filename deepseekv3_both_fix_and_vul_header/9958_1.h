#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext {
    int width;
    int height;
    int coded_width;
    int coded_height;
    int codec_id;
    int flags;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

#define CODEC_ID_AMV 0
#define CODEC_FLAG_EMU_EDGE 0

static const uint8_t sp5x_data_dqt[134] = {0};
static const uint8_t sp5x_data_dht[420] = {0};
static const uint8_t sp5x_data_sof[17] = {0};
static const uint8_t sp5x_data_sos[10] = {0};
static const uint8_t sp5x_quant_table[128] = {0};

void *av_mallocz(size_t size);
void av_free(void *ptr);
void av_init_packet(AVPacket *pkt);
int ff_mjpeg_decode_frame(AVCodecContext *avctx, void *data, int *data_size, AVPacket *avpkt);

#define AV_WB16(p, d) do { \
        ((uint8_t*)(p))[0] = (d) >> 8; \
        ((uint8_t*)(p))[1] = (d); \
    } while(0)