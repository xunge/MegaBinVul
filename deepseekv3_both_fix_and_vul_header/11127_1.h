#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))

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

struct eac3_info {
    int data_rate;
    int ec3_done;
    int num_ind_sub;
    eac3_substream substream[16];
    int num_blocks;
    AVPacket pkt;
};

typedef struct MOVMuxContext {
    void *fc;
} MOVMuxContext;

typedef struct MOVTrack {
    void *eac3_priv;
    void *entry;
    void *par;
} MOVTrack;

enum {
    EAC3_FRAME_TYPE_INDEPENDENT = 0,
    EAC3_FRAME_TYPE_DEPENDENT
};

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

#define AV_LOG_WARNING 0
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)

static inline void *av_mallocz(size_t size) { return calloc(1, size); }
static inline void av_free(void *ptr) { free(ptr); }
static inline void av_log(void *avcl, int level, const char *fmt, ...) {}
static inline void avpriv_request_sample(void *avctx, const char *msg) {}
static inline int avpriv_ac3_parse_header(AC3HeaderInfo **hdr, const uint8_t *data, size_t size) { return 0; }
static inline void init_get_bits8(GetBitContext *gb, const uint8_t *buffer, int byte_size) {}
static inline void skip_bits(GetBitContext *gb, int n) {}
static inline unsigned int get_bits(GetBitContext *gb, int n) { return 0; }
static inline int get_bits1(GetBitContext *gb) { return 0; }
static inline int av_packet_ref(AVPacket *dst, const AVPacket *src) { return 0; }
static inline int av_grow_packet(AVPacket *pkt, int grow_by) { return 0; }
static inline void av_packet_unref(AVPacket *pkt) {}
static inline int av_copy_packet_side_data(AVPacket *dst, const AVPacket *src) { return 0; }
static inline void av_packet_move_ref(AVPacket *dst, AVPacket *src) {}