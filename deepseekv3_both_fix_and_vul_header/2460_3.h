#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define AV_BPRINT_SIZE_UNLIMITED ((unsigned)-1)
#define AV_TIMECODE_STR_SIZE 16

enum AVMediaType {
    AVMEDIA_TYPE_UNKNOWN,
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO
};

enum AVColorRange {
    AVCOL_RANGE_UNSPECIFIED,
    AVCOL_RANGE_MPEG,
    AVCOL_RANGE_JPEG
};

enum AVColorSpace {
    AVCOL_SPC_UNSPECIFIED,
    AVCOL_SPC_BT709,
    AVCOL_SPC_FCC,
    AVCOL_SPC_BT470BG,
    AVCOL_SPC_SMPTE170M,
    AVCOL_SPC_SMPTE240M
};

enum AVColorPrimaries {
    AVCOL_PRI_UNSPECIFIED,
    AVCOL_PRI_BT709,
    AVCOL_PRI_BT470M,
    AVCOL_PRI_BT470BG,
    AVCOL_PRI_SMPTE170M,
    AVCOL_PRI_SMPTE240M
};

enum AVColorTransferCharacteristic {
    AVCOL_TRC_UNSPECIFIED,
    AVCOL_TRC_BT709,
    AVCOL_TRC_GAMMA22,
    AVCOL_TRC_GAMMA28
};

enum AVChromaLocation {
    AVCHROMA_LOC_UNSPECIFIED,
    AVCHROMA_LOC_LEFT,
    AVCHROMA_LOC_CENTER,
    AVCHROMA_LOC_TOPLEFT
};

enum AVFrameSideDataType {
    AV_FRAME_DATA_DISPLAYMATRIX,
    AV_FRAME_DATA_GOP_TIMECODE,
    AV_FRAME_DATA_MASTERING_DISPLAY_METADATA,
    AV_FRAME_DATA_CONTENT_LIGHT_LEVEL,
    AV_FRAME_DATA_ICC_PROFILE
};

#define AV_DICT_MATCH_CASE 1

typedef struct WriterContext WriterContext;
typedef struct AVBPrint {
    char *str;
    unsigned len;
    unsigned size;
    unsigned size_max;
    char reserved_internal_buffer[1];
} AVBPrint;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecParameters {
    int codec_type;
} AVCodecParameters;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    uint8_t **extended_data;
    int width, height;
    int nb_samples;
    int format;
    int key_frame;
    int64_t pts;
    int64_t pkt_dts;
    int64_t best_effort_timestamp;
    int64_t pkt_duration;
    int64_t pkt_pos;
    int64_t pkt_size;
    int channels;
    uint64_t channel_layout;
    int interlaced_frame;
    int top_field_first;
    int repeat_pict;
    int pict_type;
    int coded_picture_number;
    int display_picture_number;
    int color_range;
    int colorspace;
    int color_primaries;
    int color_trc;
    int chroma_location;
    int nb_side_data;
    struct AVFrameSideData **side_data;
    void *metadata;
} AVFrame;

typedef struct AVStream {
    int index;
    AVRational time_base;
    struct AVCodecParameters *codecpar;
} AVStream;

typedef struct AVFormatContext {
    void *priv_data;
} AVFormatContext;

typedef struct AVFrameSideData {
    enum AVFrameSideDataType type;
    uint8_t *data;
    int size;
    void *metadata;
} AVFrameSideData;

typedef struct AVMasteringDisplayMetadata {
    int has_primaries;
    int has_luminance;
    AVRational display_primaries[3][2];
    AVRational white_point[2];
    AVRational min_luminance;
    AVRational max_luminance;
} AVMasteringDisplayMetadata;

typedef struct AVContentLightMetadata {
    unsigned MaxCLL;
    unsigned MaxFALL;
} AVContentLightMetadata;

typedef struct AVDictionaryEntry {
    char *key;
    char *value;
} AVDictionaryEntry;

typedef struct AVDictionary AVDictionary;

enum {
    SECTION_ID_FRAME,
    SECTION_ID_FRAME_TAGS,
    SECTION_ID_FRAME_LOGS,
    SECTION_ID_FRAME_LOG,
    SECTION_ID_FRAME_SIDE_DATA_LIST,
    SECTION_ID_FRAME_SIDE_DATA
};

extern int do_show_frame_tags;
extern int do_show_log;
extern const char *unit_byte_str;

void av_bprint_init(AVBPrint *buf, unsigned size_init, unsigned size_max);
void av_bprint_clear(AVBPrint *buf);
void av_bprint_finalize(AVBPrint *buf, char **ret_str);
void av_bprint_channel_layout(AVBPrint *bp, int nb_channels, uint64_t channel_layout);
const char *av_get_media_type_string(int media_type);
const char *av_get_pix_fmt_name(int pix_fmt);
const char *av_get_sample_fmt_name(int sample_fmt);
char av_get_picture_type_char(int pict_type);
const char *av_color_range_name(int range);
const char *av_color_space_name(int space);
const char *av_color_primaries_name(int primaries);
const char *av_color_transfer_name(int transfer);
const char *av_chroma_location_name(int location);
const char *av_frame_side_data_name(int type);
int av_display_rotation_get(const int32_t matrix[9]);
void av_timecode_make_mpeg_tc_string(char *buf, uint64_t tc);
AVRational av_guess_sample_aspect_ratio(AVFormatContext *format, AVStream *stream, AVFrame *frame);
AVDictionaryEntry *av_dict_get(const AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags);

void writer_print_section_header(WriterContext *w, int section_id);
void writer_print_section_footer(WriterContext *w);
void writer_print_integers(WriterContext *w, const char *name, const uint8_t *data, int count, const char *fmt, int columns, int bytes_per_item, int offset);
void print_str(const char *key, const char *value);
void print_str_opt(const char *key, const char *value);
void print_int(const char *key, int value);
void print_ts(const char *key, int64_t value);
void print_time(const char *key, int64_t value, const AVRational *time_base);
void print_duration_ts(const char *key, int64_t value);
void print_duration_time(const char *key, int64_t value, const AVRational *time_base);
void print_fmt(const char *key, const char *fmt, ...);
void print_val(const char *key, int64_t value, const char *unit);
void print_q(const char *key, AVRational q, char sep);
void show_tags(WriterContext *w, AVDictionary *metadata, int section_id);
void show_log(WriterContext *w, int section_id_list, int section_id, int do_show_log);