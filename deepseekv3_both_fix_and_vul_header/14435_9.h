#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Opus constants */
#define OPUS_OK 0
#define OPUS_APPLICATION_VOIP 2048
#define OPUS_SIGNAL_VOICE 3001
#define OPUS_AUTO -1000
#define OPUS_SET_SIGNAL(x) ((x) << 16 | 0x4000)
#define OPUS_SET_BITRATE(x) ((x) << 16 | 0x4002)
#define OPUS_SET_DTX(x) ((x) << 16 | 0x4006)
#define OPUS_SET_INBAND_FEC(x) ((x) << 16 | 0x4008)
#define OPUS_SET_MAX_BANDWIDTH(x) ((x) << 16 | 0x400A)
#define OPUS_SET_PACKET_LOSS_PERC(x) ((x) << 16 | 0x400C)
#define OPUS_SET_COMPLEXITY(x) ((x) << 16 | 0x400E)
#define OPUS_SET_VBR(x) ((x) << 16 | 0x4010)

/* PJMEDIA constants */
#define PJMEDIA_FRAME_TYPE_NONE 0

typedef int pj_status_t;
typedef bool pj_bool_t;
#define PJ_TRUE true
#define PJ_FALSE false
#define PJ_EINVAL 22
#define PJ_ENOMEM 12
#define PJMEDIA_CODEC_EFAILED 1
#define PJ_SUCCESS 0

#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)
#define PJ_LOG(level, args)
#define TRACE_(args)
#define THIS_FILE ""
#define __FUNCTION__ __func__

struct pj_str_t {
    char *ptr;
    unsigned slen;
};

struct fmtp_param {
    struct pj_str_t val;
};

struct fmtp {
    struct fmtp_param *param;
};

struct pjmedia_codec_param {
    struct {
        unsigned clock_rate;
        unsigned channel_cnt;
        unsigned frm_ptime;
        unsigned avg_bps;
    } info;
    struct {
        pj_bool_t plc;
        pj_bool_t vad;
        struct fmtp enc_fmtp;
        struct fmtp dec_fmtp;
    } setting;
};

typedef struct pjmedia_codec {
    void *codec_data;
} pjmedia_codec;

typedef struct pjmedia_codec_param pjmedia_codec_param;

struct opus_data {
    void *mutex;
    void *pool;
    void *enc;
    void *dec;
    void *enc_packer;
    void *dec_packer;
    struct {
        unsigned sample_rate;
        unsigned channel_cnt;
        unsigned packet_loss;
        unsigned complexity;
        pj_bool_t cbr;
    } cfg;
    unsigned enc_ptime;
    unsigned dec_ptime;
    struct {
        int type;
        void *buf;
    } dec_frame[2];
    int dec_frame_index;
};

static const struct pj_str_t STR_MAX_BIT_RATE = {"maxaveragebitrate", 16};
static const struct pj_str_t STR_INBAND_FEC = {"useinbandfec", 11};
static const struct pj_str_t STR_DTX = {"usedtx", 6};
static const struct pj_str_t STR_CBR = {"cbr", 3};

/* Opus function stubs */
static size_t opus_encoder_get_size(int channels) { return 0; }
static size_t opus_decoder_get_size(int channels) { return 0; }
static size_t opus_repacketizer_get_size(void) { return 0; }
static int opus_encoder_init(void *st, int fs, int channels, int application) { return 0; }
static int opus_decoder_init(void *st, int fs, int channels) { return 0; }
static int opus_encoder_ctl(void *st, int request, ...) { return 0; }
static int opus_repacketizer_init(void *rp) { return 0; }

/* Utility function stubs */
static void pj_mutex_lock(void *mutex) {}
static void pj_mutex_unlock(void *mutex) {}
static void *pj_pool_zalloc(void *pool, size_t size) { return calloc(1, size); }
static unsigned long pj_strtoul(const struct pj_str_t *str) { return strtoul(str->ptr, NULL, 10); }
static int find_fmtp(struct fmtp *fmtp, const struct pj_str_t *str, pj_bool_t ignore_case) { return -1; }
static int get_opus_bw_constant(unsigned rate) { return 0; }