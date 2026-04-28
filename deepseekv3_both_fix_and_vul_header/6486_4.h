#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef int16_t sint_t;
typedef uint32_t uint_t;
typedef char char_t;
typedef float smpl_t;

#define AUBIO_NEW(type) ((type *)calloc(1, sizeof(type)))
#define AUBIO_FREE(ptr) do { free(ptr); ptr = NULL; } while (0)
#define AUBIO_ARRAY(type, count) ((type *)malloc((count) * sizeof(type)))
#define AUBIO_ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define AUBIO_WRN(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define PATH_MAX 4096
#define AUBIO_AVCODEC_MAX_BUFFER_SIZE 4096
#define AVMEDIA_TYPE_AUDIO 1

struct AVStream;
struct AVCodecParameters;

typedef struct AVFormatContext {
    unsigned int nb_streams;
    struct AVStream **streams;
    int max_analyze_duration;
    int max_analyze_duration2;
} AVFormatContext;

typedef struct AVCodecContext {
    int sample_rate;
    int channels;
    int codec_id;
    int codec_type;
} AVCodecContext;

typedef struct AVFrame {
    // dummy structure
} AVFrame;

typedef struct AVCodec {
    // dummy structure
} AVCodec;

typedef struct AVStream {
    struct AVCodecContext *codec;
    struct AVCodecParameters *codecpar;
} AVStream;

typedef struct aubio_source_avcodec_t {
    AVFormatContext *avFormatCtx;
    AVCodecContext *avCodecCtx;
    AVFrame *avFrame;
    char_t *path;
    uint_t hop_size;
    uint_t channels;
    uint_t input_samplerate;
    uint_t input_channels;
    uint_t samplerate;
    sint_t selected_stream;
    smpl_t *output;
    uint_t read_samples;
    uint_t read_index;
    int eof;
    int multi;
    void *avr;
} aubio_source_avcodec_t;

int av_register_all(void);
int avformat_network_init(void);
int avformat_open_input(AVFormatContext **ps, const char *url, void *fmt, void *options);
int av_strerror(int errnum, char *errbuf, size_t errbuf_size);
int avformat_find_stream_info(AVFormatContext *ic, void **options);
struct AVCodec *avcodec_find_decoder(int id);
int avcodec_open2(AVCodecContext *avctx, const struct AVCodec *codec, void **options);
AVFrame *av_frame_alloc(void);
void *av_malloc(size_t size);

int aubio_source_avcodec_has_network_url(aubio_source_avcodec_t *s);
void del_aubio_source_avcodec(aubio_source_avcodec_t *s);
void aubio_source_avcodec_reset_resampler(aubio_source_avcodec_t *s, uint_t output_channels);