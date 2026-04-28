#include <stdint.h>
#include <string.h>

#define AV_LOG_ERROR 16

typedef struct AVCodecContext AVCodecContext;
typedef struct AVClass AVClass;
typedef struct AVFrame AVFrame;
typedef struct AVFloatDSPContext AVFloatDSPContext;
typedef struct AACContext AACContext;
typedef struct SpectralBandReplication SpectralBandReplication;
typedef struct PSContext PSContext;

typedef struct FFTContext {
    void* ptr;
} FFTContext;

typedef struct MDCTContext {
    void* ptr;
} MDCTContext;

enum {
    TYPE_CPE,
    TYPE_SCE,
    TYPE_CCE,
    TYPE_LFE,
    TYPE_DSE,
    TYPE_PCE,
    TYPE_FIL,
    TYPE_END
};

struct AACContext {
    AVCodecContext *avctx;
    struct {
        int ext_sample_rate;
        int ps;
    } m4ac;
    AVFloatDSPContext *fdsp;
    struct {
        struct {
            int ext_sample_rate;
            int ps;
        } m4ac;
    } oc[2];
};

struct PSContext {
    int start;
};

struct SpectralBandReplication {
    int sample_rate;
    int id_aac;
    int kx_and_m_pushed;
    int kx[2];
    int m[2];
    int start;
    float alpha0[2];
    float alpha1[2];
    int k[2];
    float (*X_low)[32][2];
    float (*X_high)[40][2];
    float (*X[2])[64][2];
    void *qmf_filter_scratch;
    float *e_curr;
    struct {
        float (*analysis_filterbank_samples)[32][2];
        float (*W)[32][32][2];
        int Ypos;
        float (*bw_array)[2];
        int t_env;
        int bs_num_env;
        float (*e_a)[48];
        float (*Y[2])[64][2];
        float (*synthesis_filterbank_samples)[32][2];
        int synthesis_filterbank_samples_offset;
    } data[2];
    struct {
        void (*sbr_lf_gen)(AACContext *, SpectralBandReplication *, float (*)[32][2], const float (*)[32][32][2], int);
        void (*sbr_hf_inverse_filter)(void *, float [2], float [2], const float (*)[40][2], int);
        void (*sbr_hf_assemble)(float (*)[64][2], const float (*)[40][2], SpectralBandReplication *, void *, float (*)[48]);
        void (*sbr_x_gen)(SpectralBandReplication *, float (*)[64][2], const float (*)[64][2], const float (*)[64][2], const float (*)[40][2], int);
    } c;
    PSContext ps;
    FFTContext mdct_ana;
    MDCTContext mdct;
    void *dsp;
};

void av_log(void *avcl, int level, const char *fmt, ...);
void sbr_turnoff(SpectralBandReplication *sbr);
void sbr_dequant(SpectralBandReplication *sbr, int id_aac);
void sbr_qmf_analysis(AVFloatDSPContext *fdsp, FFTContext *mdct_ana, void *dsp, float *L, float (*analysis_filterbank_samples)[32][2], float *qmf_filter_scratch, float (*W)[32][32][2], int Ypos);
void sbr_chirp(SpectralBandReplication *sbr, void *data);
void sbr_hf_gen(AACContext *ac, SpectralBandReplication *sbr, float (*X_high)[40][2], const float (*X_low)[40][2], const float (*alpha0)[2], const float (*alpha1)[2], float (*bw_array)[2], int t_env, int bs_num_env);
int sbr_mapping(AACContext *ac, SpectralBandReplication *sbr, void *data, float (*e_a)[48]);
void sbr_env_estimate(float *e_curr, float (*X_high)[40][2], SpectralBandReplication *sbr, void *data);
void sbr_gain_calc(AACContext *ac, SpectralBandReplication *sbr, void *data, float (*e_a)[48]);
void sbr_qmf_synthesis(MDCTContext *mdct, void *dsp, AVFloatDSPContext *fdsp, float *L, float (*X)[64][2], void *qmf_filter_scratch, float (*synthesis_filterbank_samples)[32][2], int *synthesis_filterbank_samples_offset, int downsampled);
void ff_ps_apply(AVCodecContext *avctx, PSContext *ps, float (*X)[64][2], float (*Y)[64][2], int kx_plus_m);