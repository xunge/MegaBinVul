#include <stdint.h>
#include <string.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct AVPacket AVPacket;
typedef struct AVFrame AVFrame;
typedef struct CDGraphicsContext CDGraphicsContext;

#define CDG_DATA_SIZE 16
#define CDG_MINIMUM_PKT_SIZE 24
#define CDG_HEADER_SIZE 24
#define AVPALETTE_SIZE (256 * 4)
#define CDG_MASK 0x3F
#define CDG_COMMAND 0x09
#define CDG_INST_MEMORY_PRESET 1
#define CDG_INST_LOAD_PAL_LO 2
#define CDG_INST_LOAD_PAL_HIGH 3
#define CDG_INST_BORDER_PRESET 4
#define CDG_INST_TILE_BLOCK 6
#define CDG_INST_TILE_BLOCK_XOR 7
#define CDG_INST_SCROLL_PRESET 8
#define CDG_INST_SCROLL_COPY 9
#define CDG_MINIMUM_SCROLL_SIZE 4
#define CDG_FULL_HEIGHT 216
#define AV_LOG_ERROR 16
#define AVERROR(e) (-(e))
#define EINVAL 22
#define AV_GET_BUFFER_FLAG_REF (1 << 0)

struct AVPacket {
    uint8_t *data;
    int size;
};

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
};

struct AVCodecContext {
    void *priv_data;
    int frame_number;
    int height;
};

struct CDGraphicsContext {
    AVFrame *frame;
};

static inline uint8_t bytestream_get_byte(const uint8_t **b) { return *(*b)++; }
static inline void bytestream_get_buffer(const uint8_t **b, uint8_t *dst, int size) { memcpy(dst, *b, size); *b += size; }