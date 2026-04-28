#include <stdint.h>
#include <inttypes.h>

#define JPEG2000_SOD  0xff93
#define JPEG2000_EOC  0xffd9
#define JPEG2000_SIZ  0xff51
#define JPEG2000_COC  0xff53
#define JPEG2000_COD  0xff52
#define JPEG2000_QCC  0xff5d
#define JPEG2000_QCD  0xff5c
#define JPEG2000_POC  0xff5f
#define JPEG2000_SOT  0xff90
#define JPEG2000_PLM  0xff57
#define JPEG2000_COM  0xff64
#define JPEG2000_TLM  0xff55
#define JPEG2000_PLT  0xff58

#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA -1

typedef struct ByteIOContext {
    uint8_t *buffer;
    int bytes_left;
} ByteIOContext;

typedef struct Jpeg2000POC {
    int dummy;
} Jpeg2000POC;

typedef struct Jpeg2000CodingStyle {
    int dummy;
} Jpeg2000CodingStyle;

typedef struct Jpeg2000QuantStyle {
    int dummy;
} Jpeg2000QuantStyle;

typedef struct Jpeg2000TilePart {
    ByteIOContext tpg;
    uint8_t *tp_end;
} Jpeg2000TilePart;

typedef struct Jpeg2000Tile {
    Jpeg2000TilePart *tile_part;
    int tp_idx;
    Jpeg2000CodingStyle *codsty;
    Jpeg2000QuantStyle *qntsty;
    Jpeg2000POC poc;
    uint8_t *properties;
} Jpeg2000Tile;

typedef struct Jpeg2000DecoderContext {
    ByteIOContext *avctx;
    ByteIOContext g;
    uint8_t *properties;
    Jpeg2000Tile *tile;
    int curtileno;
    int ncomponents;
    int numXtiles;
    int numYtiles;
    Jpeg2000CodingStyle *codsty;
    Jpeg2000QuantStyle *qntsty;
    Jpeg2000POC poc;
} Jpeg2000DecoderContext;

static void bytestream2_init(ByteIOContext *s, uint8_t *buf, int buf_size) {
    s->buffer = buf;
    s->bytes_left = buf_size;
}
static int bytestream2_get_bytes_left(ByteIOContext *s) {
    return s->bytes_left;
}
static uint16_t bytestream2_get_be16u(ByteIOContext *s) {
    uint16_t val;
    val = (s->buffer[0] << 8) | s->buffer[1];
    s->buffer += 2;
    s->bytes_left -= 2;
    return val;
}
static int bytestream2_tell(ByteIOContext *s) {
    return -1; // dummy implementation
}
static void bytestream2_skip(ByteIOContext *s, int n) {
    s->buffer += n;
    s->bytes_left -= n;
}
static uint16_t bytestream2_get_be16(ByteIOContext *s) {
    return bytestream2_get_be16u(s);
}
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void av_assert1(int condition) {}
static int get_siz(Jpeg2000DecoderContext *s) { return 0; }
static int get_coc(Jpeg2000DecoderContext *s, Jpeg2000CodingStyle *codsty, uint8_t *properties) { return 0; }
static int get_cod(Jpeg2000DecoderContext *s, Jpeg2000CodingStyle *codsty, uint8_t *properties) { return 0; }
static int get_qcc(Jpeg2000DecoderContext *s, int len, Jpeg2000QuantStyle *qntsty, uint8_t *properties) { return 0; }
static int get_qcd(Jpeg2000DecoderContext *s, int len, Jpeg2000QuantStyle *qntsty, uint8_t *properties) { return 0; }
static int get_poc(Jpeg2000DecoderContext *s, int len, Jpeg2000POC *poc) { return 0; }
static int get_sot(Jpeg2000DecoderContext *s, int len) { return 0; }
static int get_tlm(Jpeg2000DecoderContext *s, int len) { return 0; }
static int get_plt(Jpeg2000DecoderContext *s, int len) { return 0; }