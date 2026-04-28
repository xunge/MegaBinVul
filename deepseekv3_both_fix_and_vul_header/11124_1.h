#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AC3HeaderInfo {
    int bit_rate;
    int num_blocks;
    int bitstream_id;
    int substreamid;
    int frame_type;
    int sr_code;
    int bitstream_mode;
    int channel_mode;
    int lfe_on;
    int frame_size;
} AC3HeaderInfo;

typedef struct eac3_substream {
    int fscod;
    int bsid;
    int bsmod;
    int acmod;
    int lfeon;
    int num_dep_sub;
    int chan_loc;
} eac3_substream;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int duration;
} AVPacket;

typedef struct eac3_info {
    int data_rate;
    int ec3_done;
    int num_ind_sub;
    eac3_substream substream[16];
    int num_blocks;
    AVPacket pkt;
} eac3_info;

typedef struct MOVTrack {
    void *eac3_priv;
    int entry;
    void *par;
} MOVTrack;

typedef struct MOVMuxContext {
    void *fc;
} MOVMuxContext;

enum {
    EAC3_FRAME_TYPE_INDEPENDENT,
    EAC3_FRAME_TYPE_DEPENDENT
};

#define AV_LOG_WARNING 0
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

static void *av_mallocz(size_t size);
static void init_get_bits(GetBitContext *gb, const uint8_t *buf, int bit_size);
static int avpriv_ac3_parse_header(GetBitContext *gbc, AC3HeaderInfo **phdr);
static void skip_bits(GetBitContext *gb, int n);
static int get_bits1(GetBitContext *gb);
static int get_bits(GetBitContext *gb, int n);
static int av_copy_packet(AVPacket *dst, const AVPacket *src);
static int av_grow_packet(AVPacket *pkt, int grow_by);
static void av_packet_unref(AVPacket *pkt);
static int av_copy_packet_side_data(AVPacket *dst, const AVPacket *src);
static void av_log(void *avcl, int level, const char *fmt, ...);
static void avpriv_request_sample(void *avctx, const char *msg);