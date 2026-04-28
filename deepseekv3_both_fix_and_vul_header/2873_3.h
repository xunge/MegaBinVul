#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define AV_CH_LAYOUT_MONO 0x0004
#define AV_CH_LAYOUT_STEREO 0x0003

#define AVMEDIA_TYPE_AUDIO 0
#define AVMEDIA_TYPE_VIDEO 1

#define AV_CODEC_ID_PCM_S16BE_PLANAR 0x10000
#define AV_CODEC_ID_PCM_U8 0x10001
#define AV_CODEC_ID_PCM_S16BE 0x10002
#define AV_CODEC_ID_PCM_ALAW 0x10003
#define AV_CODEC_ID_PCM_MULAW 0x10004
#define AV_CODEC_ID_PCM_S8_PLANAR 0x10005
#define AV_CODEC_ID_8SVX_FIB 0x10006
#define AV_CODEC_ID_8SVX_EXP 0x10007
#define AV_CODEC_ID_IFF_ILBM 0x10008

#define AV_PIX_FMT_RGB24 0
#define AV_PIX_FMT_RGBA 1
#define AV_PIX_FMT_BGRA 2
#define AV_PIX_FMT_ARGB 3
#define AV_PIX_FMT_ABGR 4

#define ID_VHDR 0x56484452
#define ID_MHDR 0x4D484452
#define ID_ABIT 0x41424954
#define ID_BODY 0x424F4459
#define ID_DBOD 0x44424F44
#define ID_MDAT 0x4D444154
#define ID_CHAN 0x4348414E
#define ID_CAMG 0x43414D47
#define ID_CMAP 0x434D4150
#define ID_BMHD 0x424D4844
#define ID_DPEL 0x4450454C
#define ID_DGBL 0x4447424C
#define ID_DLOC 0x444C4F43
#define ID_TVDC 0x54564443
#define ID_ANNO 0x414E4E4F
#define ID_TEXT 0x54455854
#define ID_AUTH 0x41555448
#define ID_COPYRIGHT 0x28632920
#define ID_NAME 0x4E414D45
#define ID_16SV 0x31365356
#define ID_MAUD 0x4D415544

#define COMP_NONE 0
#define COMP_FIB 1
#define COMP_EXP 2

#define IFF_EXTRA_VIDEO_SIZE 24
#define FF_INPUT_BUFFER_PADDING_SIZE 16

#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define AV_LOG_ERROR 0
#define SEEK_SET 0

typedef struct AVFormatContext {
    void *priv_data;
    void *pb;
} AVFormatContext;

typedef struct AVIOContext {
    // Minimal stub for compilation
} AVIOContext;

typedef struct AVStream {
    struct {
        int channels;
        uint64_t channel_layout;
        int codec_type;
        int codec_tag;
        int sample_rate;
        int bits_per_coded_sample;
        int codec_id;
        int width;
        int height;
        int extradata_size;
        uint8_t *extradata;
        int block_align;
        int bit_rate;
        int pix_fmt;
    } *codec;
    struct {
        int num;
        int den;
    } sample_aspect_ratio;
} AVStream;

typedef struct IffDemuxContext {
    int bitmap_compression;
    int svx8_compression;
    int maud_bits;
    int maud_compression;
    uint64_t body_pos;
    uint64_t body_end;
    uint32_t body_size;
    uint8_t tvdc[16];
    int bpp;
    int ham;
    int flags;
    int masking;
    int transparency;
} IffDemuxContext;

static const uint8_t deep_rgb24[] = {0, 0, 0, 24, 0, 0, 0, 8, 0, 0, 0, 16, 0, 0, 0, 8};
static const uint8_t deep_rgba[] = {0, 0, 0, 32, 0, 0, 0, 8, 0, 0, 0, 16, 0, 0, 0, 8};
static const uint8_t deep_bgra[] = {0, 0, 0, 32, 0, 0, 0, 16, 0, 0, 0, 8, 0, 0, 0, 8};
static const uint8_t deep_argb[] = {0, 0, 0, 32, 0, 0, 0, 24, 0, 0, 0, 16, 0, 0, 0, 8};
static const uint8_t deep_abgr[] = {0, 0, 0, 32, 0, 0, 0, 8, 0, 0, 0, 16, 0, 0, 0, 24};

static inline int av_get_bits_per_sample(int codec_id) {
    switch(codec_id) {
        case AV_CODEC_ID_PCM_S16BE_PLANAR: return 16;
        case AV_CODEC_ID_PCM_U8: return 8;
        case AV_CODEC_ID_PCM_S16BE: return 16;
        case AV_CODEC_ID_PCM_ALAW: return 8;
        case AV_CODEC_ID_PCM_MULAW: return 8;
        case AV_CODEC_ID_PCM_S8_PLANAR: return 8;
        default: return 0;
    }
}

static inline int AVERROR(int err) {
    return -err;
}

static inline AVStream *avformat_new_stream(AVFormatContext *s, void *codec) {
    return NULL;
}

static inline void avio_skip(AVIOContext *pb, int offset) {
}

static inline uint32_t avio_rl32(AVIOContext *pb) {
    return 0;
}

static inline uint32_t avio_rb32(AVIOContext *pb) {
    return 0;
}

static inline int url_feof(AVIOContext *pb) {
    return 0;
}

static inline uint64_t avio_tell(AVIOContext *pb) {
    return 0;
}

static inline uint16_t avio_rb16(AVIOContext *pb) {
    return 0;
}

static inline uint8_t avio_r8(AVIOContext *pb) {
    return 0;
}

static inline int avio_read(AVIOContext *pb, uint8_t *buf, int size) {
    return 0;
}

static inline void *av_malloc(size_t size) {
    return malloc(size);
}

static inline void avio_seek(AVIOContext *pb, int64_t offset, int whence) {
}

static inline void bytestream_put_be16(uint8_t **buf, uint16_t val) {
}

static inline void bytestream_put_byte(uint8_t **buf, uint8_t val) {
}

static inline void bytestream_put_buffer(uint8_t **buf, const uint8_t *src, size_t size) {
}

static inline void av_log(void *avcl, int level, const char *fmt, ...) {
}

static inline void av_log_ask_for_sample(void *avcl, const char *fmt, ...) {
}

static inline int get_metadata(void *s, const char *tag, int size) {
    return 0;
}

static inline void avpriv_set_pts_info(AVStream *st, int pts_num, int pts_den, int rate) {
}

static inline void av_assert0(int expr) {
}