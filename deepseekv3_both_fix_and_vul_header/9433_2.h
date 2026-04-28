#include <stdint.h>
#include <math.h>
#include <string.h>

#define AV_CODEC_FLAG_BITEXACT 0x0001
#define CODEC_FLAG_BITEXACT AV_CODEC_FLAG_BITEXACT
#define AV_CH_LAYOUT_STEREO 3
#define AV_CH_LAYOUT_MONO 4
#define AV_SAMPLE_FMT_FLTP 8
#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_INVALIDDATA (-2)
#define AVERROR(ENOMEM) (-3)
#define ON2AVC_SCALE_DIFFS 9
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24

typedef struct AVCodecContext {
    int channels;
    int sample_rate;
    int codec_tag;
    int flags;
    int sample_fmt;
    unsigned int channel_layout;
    void *priv_data;
} AVCodecContext;

typedef struct VLC {
    int dummy;
} VLC;

typedef struct On2AVCContext {
    AVCodecContext *avctx;
    int is_av500;
    float scale_tab[128];
    float long_win[1024];
    float short_win[128];
    const void *modes;
    const void *wtf;
    void *mdct;
    void *mdct_half;
    void *mdct_small;
    void *fft128;
    void *fft256;
    void *fft512;
    void *fft1024;
    void *fdsp;
    VLC scale_diff;
    VLC cb_vlc[16];
} On2AVCContext;

#define av_cold

extern void avpriv_request_sample(AVCodecContext *avctx, const char *msg);
extern void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
extern void ff_mdct_init(void *mdct, int nbits, int inverse, double scale);
extern void ff_fft_init(void *fft, int nbits, int inverse);
extern void avpriv_float_dsp_init(void *fdsp, int flags);
extern int init_vlc(VLC *vlc, int nb_bits, int nb_codes,
                    const void *bits, int bits_wrap, int bits_size,
                    const void *codes, int codes_wrap, int codes_size,
                    int flags);
extern int ff_init_vlc_sparse(VLC *vlc, int nb_bits, int nb_codes,
                             const void *bits, int bits_wrap, int bits_size,
                             const void *codes, int codes_wrap, int codes_size,
                             const void *symbols, int symbols_wrap, int symbols_size,
                             int flags);
extern void on2avc_free_vlcs(On2AVCContext *c);

extern const float ff_on2avc_window_long_24000[1024];
extern const float ff_on2avc_window_long_32000[1024];
extern const float ff_on2avc_window_short[128];
extern const void *ff_on2avc_modes_40;
extern const void *ff_on2avc_modes_44;
extern const void *wtf_40;
extern const void *wtf_44;
extern const uint8_t ff_on2avc_scale_diff_bits[9];
extern const uint32_t ff_on2avc_scale_diff_codes[9];
extern const uint8_t *ff_on2avc_quad_cb_bits[8];
extern const uint32_t *ff_on2avc_quad_cb_codes[8];
extern const uint16_t *ff_on2avc_quad_cb_syms[8];
extern const int ff_on2avc_quad_cb_elems[8];
extern const uint8_t *ff_on2avc_pair_cb_bits[7];
extern const uint16_t *ff_on2avc_pair_cb_codes[7];
extern const uint16_t *ff_on2avc_pair_cb_syms[7];
extern const int ff_on2avc_pair_cb_elems[7];