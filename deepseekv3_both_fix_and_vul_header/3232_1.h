#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define CBF0_TAG 0x43424630
#define CBFZ_TAG 0x4342465A
#define CBP0_TAG 0x43425030
#define CBPZ_TAG 0x4342505A
#define CPL0_TAG 0x43504C30
#define CPLZ_TAG 0x43504C5A
#define VPTZ_TAG 0x5650545A

#define MAX_CODEBOOK_SIZE 0x10000
#define AVERROR_INVALIDDATA -1
#define AV_LOG_ERROR 16
#define SEEK_SET 0

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct AVCodecContext {
    void *opaque;
    int log_level_offset;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

typedef struct VqaContext {
    AVCodecContext *avctx;
    GetByteContext gb;
    int vqa_version;
    int width;
    int height;
    int vector_height;
    uint32_t palette[256];
    uint8_t *codebook;
    int codebook_size;
    uint8_t *decode_buffer;
    int decode_buffer_size;
    AVFrame frame;
    uint8_t *next_codebook_buffer;
    int next_codebook_buffer_index;
    int partial_count;
    int partial_countdown;
} VqaContext;

static void av_log(void *avctx, int level, const char *fmt, ...);
static unsigned int bytestream2_get_bytes_left(GetByteContext *gb);
static unsigned int bytestream2_get_be32u(GetByteContext *gb);
static unsigned int bytestream2_tell(GetByteContext *gb);
static void bytestream2_skip(GetByteContext *gb, int n);
static void bytestream2_seek(GetByteContext *gb, int offset, int whence);
static unsigned int bytestream2_get_be32(GetByteContext *gb);
static unsigned char bytestream2_get_byteu(GetByteContext *gb);
static void bytestream2_get_buffer(GetByteContext *gb, uint8_t *dst, int size);
static void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size);
static int decode_format80(VqaContext *s, int src_size, uint8_t *dest, int dest_size, int check_size);