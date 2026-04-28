#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <errno.h>

#define AV_LOG_INFO 0
#define AV_LOG_ERROR 1
#define AVFMT_NOFILE 0x0001

typedef struct AVFormatContext {
    struct AVOutputFormat *oformat;
    struct AVIOContext *pb;
} AVFormatContext;

typedef struct AVOutputFormat {
    int flags;
} AVOutputFormat;

typedef struct AVIOContext AVIOContext;
typedef struct AVFrame AVFrame;
typedef struct AVDictionary AVDictionary;
typedef struct AVCodecContext AVCodecContext;
typedef struct AVCodecParameters AVCodecParameters;
typedef struct AVFilterGraph AVFilterGraph;
typedef struct AVBufferRef AVBufferRef;
typedef struct AVBSFContext AVBSFContext;
typedef struct AVFifoBuffer AVFifoBuffer;

typedef struct AVSubtitle {
    // Minimal stub definition
    int dummy;
} AVSubtitle;

typedef struct AVPacket {
    // Minimal stub definition
    int dummy;
} AVPacket;

extern int do_benchmark;
extern int nb_filtergraphs;
extern int nb_output_files;
extern int nb_output_streams;
extern int nb_input_files;
extern int nb_input_streams;
extern int received_sigterm;
extern int ffmpeg_exited;
extern atomic_int transcode_init_done;

typedef struct FilterGraph {
    AVFilterGraph *graph;
    int nb_inputs;
    int nb_outputs;
    struct InputFilter **inputs;
    struct OutputFilter **outputs;
    char *graph_desc;
} FilterGraph;

typedef struct InputFilter {
    AVBufferRef *hw_frames_ctx;
    char *name;
    struct InputStream *ist;
    AVFifoBuffer *frame_queue;
} InputFilter;

typedef struct OutputFilter {
    char *name;
    int *formats;
    int64_t *channel_layouts;
    int *sample_rates;
} OutputFilter;

typedef struct InputStream {
    AVCodecContext *dec_ctx;
    AVFrame *decoded_frame;
    AVFrame *filter_frame;
    AVDictionary *decoder_opts;
    struct {
        AVSubtitle subtitle;
    } prev_sub;
    struct {
        AVFrame *frame;
        AVFifoBuffer *sub_queue;
    } sub2video;
    char *filters;
    char *hwaccel_device;
    int64_t *dts_buffer;
} InputStream;

typedef struct OutputStream {
    AVCodecContext *enc_ctx;
    AVCodecParameters *ref_par;
    AVFrame *filtered_frame;
    AVFrame *last_frame;
    AVDictionary *encoder_opts;
    char *forced_keyframes;
    void *forced_keyframes_pexpr;
    char *avfilter;
    char *logfile_prefix;
    int *audio_channels_map;
    int audio_channels_mapped;
    AVDictionary *sws_dict;
    AVDictionary *swr_opts;
    AVBSFContext **bsf_ctx;
    int nb_bitstream_filters;
    AVFifoBuffer *muxing_queue;
} OutputStream;

typedef struct InputFile {
    AVFormatContext *ctx;
} InputFile;

typedef struct OutputFile {
    AVFormatContext *ctx;
    AVDictionary *opts;
} OutputFile;

extern FilterGraph **filtergraphs;
extern AVSubtitle *subtitle_out;
extern OutputFile **output_files;
extern OutputStream **output_streams;
extern InputFile **input_files;
extern InputStream **input_streams;
extern FILE *vstats_file;
extern char *vstats_filename;

void av_log(void *avcl, int level, const char *fmt, ...);
void av_frame_free(AVFrame **frame);
void avsubtitle_free(AVSubtitle *sub);
void av_fifo_freep(AVFifoBuffer **f);
int av_fifo_size(AVFifoBuffer *f);
void av_fifo_generic_read(AVFifoBuffer *f, void *dst, int buf_size, void (*func)(void*, void*, int));
void av_buffer_unref(AVBufferRef **buf);
void av_freep(void *ptr);
void avfilter_graph_free(AVFilterGraph **graph);
void av_dict_free(AVDictionary **m);
void avcodec_free_context(AVCodecContext **avctx);
void avcodec_parameters_free(AVCodecParameters **par);
void av_bsf_free(AVBSFContext **bsf);
void av_packet_unref(AVPacket *pkt);
void avformat_close_input(AVFormatContext **s);
void avformat_free_context(AVFormatContext *s);
void avio_closep(AVIOContext **s);
void avformat_network_deinit(void);
char *av_err2str(int errnum);
void av_expr_free(void *expr);
void term_exit(void);
void uninit_opts(void);
int getmaxrss(void);
void free_input_threads(void);
int AVERROR(int errnum);