#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define AV_SAMPLE_FMT_NONE -1
#define AV_SAMPLE_FMT_S16P 1
#define AV_SAMPLE_FMT_S32P 2
#define AV_SAMPLE_FMT_FLTP 3
#define AV_SAMPLE_FMT_DBLP 4
#define AV_SAMPLE_FMT_NB 64
#define SWR_CH_MAX 64
#define CONFIG_LIBSOXR 0
#define SWR_ENGINE_SOXR 0
#define SWR_ENGINE_SWR 1
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 0
#define AV_LOG_DEBUG 0
#define AVERROR(e) (-(e))
#define EINVAL 22
#define ENOMEM 12
#define AV_NOPTS_VALUE INT64_MIN
#define SWR_FLAG_RESAMPLE 1
#define RSC 1

struct AudioData {
    int ch_count;
    void *ch[SWR_CH_MAX];
};

struct SwrContext {
    int in_buffer_index;
    int in_buffer_count;
    int resample_in_constraint;
    struct AudioData in;
    struct AudioData out;
    struct {
        void *noise;
        void *temp;
        int method;
    } dither;
    int in_sample_fmt;
    int out_sample_fmt;
    uint64_t in_ch_layout;
    uint64_t out_ch_layout;
    int engine;
    int used_ch_count;
    int int_sample_fmt;
    int flushed;
    void *resample;
    int resample_first;
    int filter_size;
    int phase_shift;
    int linear_interp;
    double cutoff;
    int filter_type;
    double kaiser_beta;
    double precision;
    int cheby;
    int out_sample_rate;
    int in_sample_rate;
    int64_t firstpts_in_samples;
    int async;
    double min_compensation;
    double max_soft_compensation;
    int64_t firstpts;
    int64_t outpts;
    int flags;
    int rematrix;
    double rematrix_volume;
    int rematrix_custom;
    int *channel_map;
    const struct Resampler *resampler;
    void *in_convert;
    void *out_convert;
    void *full_convert;
    struct AudioData postin;
    struct AudioData midbuf;
    struct AudioData preout;
    struct AudioData in_buffer;
    struct AudioData silence;
    struct AudioData drop_temp;
};

struct Resampler {
    void *(*init)(void *, int, int, int, int, int, double, int, int, double, double, int);
    void (*free)(void **);
};

extern const struct Resampler soxr_resampler;
extern const struct Resampler swri_resampler;

void free_temp_audio(struct AudioData *);
void free_temp_ptr(void **);
void swri_audio_convert_free(void **);
void swri_rematrix_free(struct SwrContext *);
int av_get_channel_layout_nb_channels(uint64_t);
uint64_t av_get_default_channel_layout(int);
int av_get_planar_sample_fmt(int);
const char *av_get_sample_fmt_name(int);
void av_log(struct SwrContext *, int, const char *, ...);
void set_audiodata_fmt(struct AudioData *, int);
void av_get_channel_layout_string(char *, int, int, uint64_t);
void av_assert0(int);
int swri_dither_init(struct SwrContext *, int, int);
int swri_rematrix_init(struct SwrContext *);
void *swri_audio_convert_alloc(int, int, int, int *, int);

#define free_temp(p) _Generic((p), \
    struct AudioData*: free_temp_audio, \
    void**: free_temp_ptr \
)(p)

#define av_cold