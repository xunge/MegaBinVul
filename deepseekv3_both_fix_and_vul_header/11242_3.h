#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef int16_t sint_t;
typedef char char_t;
typedef float smpl_t;
typedef unsigned int uint_t;

#define AUBIO_NEW(type) ((type *)malloc(sizeof(type)))
#define AUBIO_FREE(ptr) free(ptr)
#define AUBIO_ARRAY(type, size) ((type *)malloc((size) * sizeof(type)))
#define AUBIO_ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define AUBIO_WRN(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define PATH_MAX 4096
#define AUBIO_AVCODEC_MAX_BUFFER_SIZE 4096
#define AVMEDIA_TYPE_AUDIO 1

typedef struct AVStream AVStream;
typedef struct AVCodec AVCodec;
typedef struct AVCodecParameters AVCodecParameters;

typedef struct AVFormatContext {
    unsigned int nb_streams;
    AVStream **streams;
    int max_analyze_duration;
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

typedef struct AVStream {
    AVCodecContext *codec;
    AVCodecParameters *codecpar;
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
    smpl_t *output;
    uint_t read_samples;
    uint_t read_index;
    sint_t selected_stream;
    int eof;
    int multi;
    void *avr;
} aubio_source_avcodec_t;

void del_aubio_source_avcodec(aubio_source_avcodec_t *s);
int aubio_source_avcodec_has_network_url(aubio_source_avcodec_t *s);
void aubio_source_avcodec_reset_resampler(aubio_source_avcodec_t *s, uint_t output_channels);

// Dummy function declarations
void av_register_all(void);
void avformat_network_init(void);
int avformat_open_input(AVFormatContext **ps, const char *url, void *fmt, void *options);
int av_strerror(int errnum, char *errbuf, size_t errbuf_size);
int avformat_find_stream_info(AVFormatContext *ic, void **options);
AVCodec *avcodec_find_decoder(int id);
int avcodec_open2(AVCodecContext *avctx, const AVCodec *codec, void **options);
AVFrame *av_frame_alloc(void);
void *av_malloc(size_t size);