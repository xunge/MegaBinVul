#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define av_cold 
#define AV_CODEC_FLAG_BITEXACT 0x0002
#define CODEC_FLAG_BITEXACT AV_CODEC_FLAG_BITEXACT
#define AV_SAMPLE_FMT_FLT 3
#define AV_SAMPLE_FMT_S16 1
#define MAX_ELEM_ID 16
#define MAX_CHANNELS 64
#define OC_GLOBAL_HDR 1
#define AV_EF_EXPLODE (1 << 0)
#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)

#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define AAC_INIT_VLC_STATIC(num, size)
#define INIT_VLC_STATIC(vlc, bits, size, bits_buf, bits_wrap, bits_size, codes_buf, codes_wrap, codes_size, flags)

typedef struct AVCodecContext {
    int sample_rate;
    int request_sample_fmt;
    int sample_fmt;
    int extradata_size;
    uint8_t *extradata;
    int channels;
    int err_recognition;
    void *priv_data;
    void *coded_frame;
    int flags;
} AVCodecContext;

typedef struct {
    int sample_rate;
    int sampling_index;
    int channels;
    int sbr;
    int ps;
    int chan_config;
} MPEG4AudioConfig;

typedef struct {
    MPEG4AudioConfig m4ac;
} OutputConfiguration;

typedef struct AACContext {
    AVCodecContext *avctx;
    OutputConfiguration oc[2];
    void *dsp;
    void *fmt_conv;
    void *fdsp;
    unsigned int random_state;
    void *mdct;
    void *mdct_small;
    void *mdct_ltp;
    void *frame;
} AACContext;

static int ff_mpeg4audio_channels[] = {0, 1, 2, 3, 4, 5, 6, 8};
static uint8_t ff_aac_scalefactor_bits[1];
static uint8_t ff_aac_scalefactor_code[1];
static float ff_aac_kbd_long_1024[1024];
static float ff_aac_kbd_short_128[128];

static int decode_audio_specific_config(void *ac, AVCodecContext *avctx, MPEG4AudioConfig *m4ac, uint8_t *extradata, int size, int flag) { return 0; }
static int sample_rate_idx(int sample_rate) { return 0; }
static int set_default_channel_config(AVCodecContext *avctx, uint8_t layout_map[][3], int *layout_map_tags, int chan_config) { return 0; }
static void output_configure(void *ac, uint8_t layout_map[][3], int layout_map_tags, int chan_config, int flag) {}
static void ff_aac_sbr_init(void) {}
static void ff_dsputil_init(void *dsp, AVCodecContext *avctx) {}
static void ff_fmt_convert_init(void *fmt_conv, AVCodecContext *avctx) {}
static void avpriv_float_dsp_init(void *fdsp, int flags) {}
static void ff_aac_tableinit(void) {}
static void ff_mdct_init(void *mdct, int n, int inverse, double scale) {}
static void ff_kbd_window_init(float *window, float alpha, int n) {}
static void ff_init_ff_sine_windows(int n) {}
static void cbrt_tableinit(void) {}
static void avcodec_get_frame_defaults(void *frame) {}
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}