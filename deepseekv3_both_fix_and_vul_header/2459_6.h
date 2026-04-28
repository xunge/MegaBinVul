#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

typedef struct WriterContext WriterContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVBPrint {
    char *str;
    unsigned len;
    unsigned size;
    unsigned size_max;
    char reserved_internal_buffer[1];
} AVBPrint;

typedef struct AVCodecDescriptor {
    const char *name;
    const char *long_name;
} AVCodecDescriptor;

typedef struct AVOption {
    const char *name;
    int flags;
} AVOption;

typedef struct AVStream {
    int index;
    struct AVCodecParameters *codecpar;
    int64_t start_time;
    int64_t duration;
    int64_t nb_frames;
    int id;
    int disposition;
    void *metadata;
    int nb_side_data;
    void *side_data;
    AVRational r_frame_rate;
    AVRational avg_frame_rate;
    AVRational time_base;
} AVStream;

typedef struct AVCodecParameters {
    int codec_id;
    int profile;
    int codec_type;
    int width;
    int height;
    int video_delay;
    int format;
    int level;
    int color_range;
    int color_space;
    int color_trc;
    int color_primaries;
    int chroma_location;
    int field_order;
    int sample_rate;
    int channels;
    uint64_t channel_layout;
    int bit_rate;
    uint8_t *extradata;
    int extradata_size;
    uint32_t codec_tag;
} AVCodecParameters;

typedef struct AVCodecContext {
    AVRational time_base;
    int coded_width;
    int coded_height;
    int refs;
    int bits_per_raw_sample;
    void *priv_data;
    struct AVCodec *codec;
    int timecode_frame_start;
} AVCodecContext;

typedef struct InputStream {
    AVStream *st;
    AVCodecContext *dec_ctx;
} InputStream;

typedef struct AVFormatContext {
    struct AVInputFormat *iformat;
} AVFormatContext;

typedef struct AVInputFormat {
    int flags;
} AVInputFormat;

typedef struct AVCodec {
    void *priv_class;
} AVCodec;

#define AV_BPRINT_SIZE_UNLIMITED 0
#define FF_PROFILE_UNKNOWN 0
#define AVMEDIA_TYPE_VIDEO 0
#define AVMEDIA_TYPE_AUDIO 1
#define AVMEDIA_TYPE_SUBTITLE 2
#define AVCOL_RANGE_UNSPECIFIED 0
#define AVCOL_SPC_UNSPECIFIED 0
#define AVCOL_TRC_UNSPECIFIED 0
#define AVCOL_PRI_UNSPECIFIED 0
#define AVCHROMA_LOC_UNSPECIFIED 0
#define AV_FIELD_PROGRESSIVE 0
#define AV_FIELD_TT 1
#define AV_FIELD_BB 2
#define AV_FIELD_TB 3
#define AV_FIELD_BT 4
#define AV_DISPOSITION_DEFAULT 0
#define AV_DISPOSITION_DUB 0
#define AV_DISPOSITION_ORIGINAL 0
#define AV_DISPOSITION_COMMENT 0
#define AV_DISPOSITION_LYRICS 0
#define AV_DISPOSITION_KARAOKE 0
#define AV_DISPOSITION_FORCED 0
#define AV_DISPOSITION_HEARING_IMPAIRED 0
#define AV_DISPOSITION_VISUAL_IMPAIRED 0
#define AV_DISPOSITION_CLEAN_EFFECTS 0
#define AV_DISPOSITION_ATTACHED_PIC 0
#define AV_DISPOSITION_TIMED_THUMBNAILS 0
#define AVFMT_SHOW_IDS 0

extern int do_bitexact;
extern int show_private_data;
extern int do_show_data;
extern int do_show_stream_disposition;
extern int do_show_stream_tags;
extern uint64_t nb_streams_frames[];
extern uint64_t nb_streams_packets[];
extern const char *unit_hertz_str;
extern const char *unit_bit_per_second_str;

enum {
    SECTION_ID_PROGRAM_STREAM,
    SECTION_ID_STREAM,
    SECTION_ID_PROGRAM_STREAM_DISPOSITION,
    SECTION_ID_STREAM_DISPOSITION,
    SECTION_ID_PROGRAM_STREAM_TAGS,
    SECTION_ID_STREAM_TAGS,
    SECTION_ID_STREAM_SIDE_DATA_LIST,
    SECTION_ID_STREAM_SIDE_DATA
};

static void av_bprint_init(AVBPrint *buf, unsigned size_init, unsigned size_max);
static void av_bprint_clear(AVBPrint *buf);
static void av_bprint_channel_layout(AVBPrint *bp, int nb_channels, uint64_t channel_layout);
static void av_bprint_finalize(AVBPrint *buf, char **ret_str);
static const AVCodecDescriptor *avcodec_descriptor_get(int id);
static const char *avcodec_profile_name(int codec_id, int profile);
static const char *av_get_media_type_string(int media_type);
static const char *av_fourcc2str(uint32_t fourcc);
static AVRational av_guess_sample_aspect_ratio(void *format, void *stream, void *frame);
static void av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max);
static const char *av_get_pix_fmt_name(int pix_fmt);
static const char *av_color_range_name(int range);
static const char *av_color_space_name(int space);
static const char *av_color_transfer_name(int transfer);
static const char *av_color_primaries_name(int primaries);
static const char *av_chroma_location_name(int location);
static const char *av_get_sample_fmt_name(int sample_fmt);
static int av_get_bits_per_sample(int codec_id);
static const AVOption *av_opt_next(void *obj, const AVOption *prev);
static int av_opt_get(void *obj, const char *name, int search_flags, uint8_t **out_val);
static void av_free(void *ptr);
static void av_timecode_make_mpeg_tc_string(char *buf, int tc);

static void writer_print_section_header(WriterContext *w, int section_id);
static void writer_print_section_footer(WriterContext *w);
static void writer_print_data(WriterContext *w, const char *name, const uint8_t *data, int size);
static void writer_print_data_hash(WriterContext *w, const char *name, const uint8_t *data, int size);
static void print_int(const char *name, int64_t val);
static void print_str(const char *name, const char *val);
static void print_str_opt(const char *name, const char *val);
static void print_fmt(const char *name, const char *fmt, ...);
static void print_q(const char *name, AVRational q, char sep);
static void print_ts(const char *name, int64_t ts);
static void print_time(const char *name, int64_t ts, const AVRational *time_base);
static void print_val(const char *name, int64_t val, const char *unit_str);
static int show_tags(WriterContext *w, void *metadata, int section_id);
static void print_pkt_side_data(WriterContext *w, AVCodecParameters *par, void *sd, int nb_sd, int section_id_list, int section_id);