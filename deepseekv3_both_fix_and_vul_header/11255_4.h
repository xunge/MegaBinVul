#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define AV_LOG_TRACE 56
#define AV_LOG_DEBUG 48
#define AV_LOG_VERBOSE 40
#define AV_LOG_INFO 32
#define AV_LOG_WARNING 24
#define AV_LOG_ERROR 16

#define AVERROR_INVALIDDATA (-(EINVAL))
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AV_NOPTS_VALUE INT64_MIN

#define AV_TIMECODE_FLAG_DROPFRAME (1 << 0)

#define AVSTREAM_PARSE_HEADERS 1
#define AVSTREAM_PARSE_FULL 2
#define AVSTREAM_PARSE_TIMESTAMPS 3

typedef uint8_t UID[16];

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef enum AVMediaType {
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA,
    AVMEDIA_TYPE_SUBTITLE
} AVMediaType;

typedef enum AVCodecID {
    AV_CODEC_ID_NONE,
    AV_CODEC_ID_PCM_ALAW,
    AV_CODEC_ID_PCM_S16LE,
    AV_CODEC_ID_PCM_S24LE,
    AV_CODEC_ID_PCM_S32LE,
    AV_CODEC_ID_PCM_S16BE,
    AV_CODEC_ID_PCM_S24BE,
    AV_CODEC_ID_PCM_S32BE,
    AV_CODEC_ID_MP2,
    AV_CODEC_ID_H264,
    AV_CODEC_ID_RAWVIDEO
} AVCodecID;

typedef enum AVPixelFormat {
    AV_PIX_FMT_NONE,
    AV_PIX_FMT_UYVY422
} AVPixelFormat;

typedef enum AVFieldOrder {
    AV_FIELD_PROGRESSIVE,
    AV_FIELD_TT,
    AV_FIELD_BB,
    AV_FIELD_TB,
    AV_FIELD_BT
} AVFieldOrder;

typedef struct AVFormatContext {
    void *metadata;
    void *priv_data;
} AVFormatContext;

typedef struct AVStream {
    int index;
    int id;
    int64_t duration;
    int64_t start_time;
    void *priv_data;
    void *metadata;
    struct {
        AVMediaType codec_type;
        AVCodecID codec_id;
        AVPixelFormat format;
        int width;
        int height;
        AVFieldOrder field_order;
        int channels;
        int bits_per_coded_sample;
        int sample_rate;
        int codec_tag;
        uint8_t *extradata;
        int extradata_size;
    } *codecpar;
    int need_parsing;
    AVRational time_base;
    AVRational display_aspect_ratio;
} AVStream;

typedef struct AVTimecode {
    int start;
    AVRational rate;
    int flags;
} AVTimecode;

typedef struct MXFContext {
    AVFormatContext *fc;
    int metadata_sets_count;
    int packages_count;
    UID *packages_refs;
    int essence_container_data_count;
    UID *essence_container_data_refs;
    void **metadata_sets;
    enum {
        OPAtom,
    } op;
} MXFContext;

typedef struct MXFPackage {
    char *name;
    UID descriptor_ref;
    void *descriptor;
    int tracks_count;
    UID *tracks_refs;
} MXFPackage;

typedef struct MXFTrack {
    int track_id;
    char *name;
    UID sequence_ref;
    struct MXFSequence *sequence;
    AVRational edit_rate;
    int body_sid;
    int index_sid;
    int original_duration;
    enum {
        ClipWrapped,
        FrameWrapped,
        UnknownWrapped,
    } wrapping;
    int intra_only;
} MXFTrack;

typedef struct MXFDescriptor {
    UID essence_codec_ul;
    UID essence_container_ul;
    UID codec_ul;
    int width;
    int height;
    enum {
        FullFrame,
        OneField,
        MixedFields,
        SegmentedFrame,
        SeparateFields,
    } frame_layout;
    int video_line_map[2];
    enum {
        MXF_FIELD_DOMINANCE_DEFAULT,
        MXF_FIELD_DOMINANCE_FF,
        MXF_FIELD_DOMINANCE_FL,
    } field_dominance;
    AVPixelFormat pix_fmt;
    int horiz_subsampling;
    int vert_subsampling;
    int component_depth;
    AVRational aspect_ratio;
    int channels;
    int bits_per_sample;
    AVRational sample_rate;
    int extradata_size;
    uint8_t *extradata;
    int64_t duration;
} MXFDescriptor;

typedef struct MXFStructuralComponent {
    UID source_package_ul;
    UID source_package_uid;
    int source_track_id;
    int64_t start_position;
    int64_t duration;
    int structural_components_count;
    UID *structural_components_refs;
} MXFStructuralComponent;

typedef struct MXFSequence {
    UID data_definition_ul;
    int64_t origin;
    int structural_components_count;
    UID *structural_components_refs;
} MXFSequence;

typedef struct MXFTimecodeComponent {
    AVRational rate;
    int drop_frame;
    int start_frame;
} MXFTimecodeComponent;

typedef struct MXFEssenceContainerData {
    UID package_ul;
    UID package_uid;
    int body_sid;
    int index_sid;
} MXFEssenceContainerData;

typedef struct MXFMetadataSet {
    int type;
} MXFMetadataSet;

typedef struct MXFCryptoContext {
    UID source_container_ul;
} MXFCryptoContext;

typedef struct MXFCodecUL {
    const char *desc;
    int id;
} MXFCodecUL;

enum {
    MaterialPackage,
    Track,
    Sequence,
    TimecodeComponent,
    EssenceContainerData,
    CryptoContext,
    AnyType,
};

static const MXFCodecUL ff_mxf_data_definition_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL ff_mxf_codec_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL mxf_picture_essence_container_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL mxf_sound_essence_container_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL mxf_data_essence_container_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL ff_mxf_pixel_format_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL ff_mxf_codec_tag_uls[] = {
    { NULL, 0 }
};

static const MXFCodecUL mxf_intra_only_picture_coded_width[] = {
    { NULL, 0 }
};

static const UID mxf_encrypted_essence_container;

static void av_log(void *avcl, int level, const char *fmt, ...) {}
static void av_dict_set(void **pm, const char *key, const char *value, int flags) {}
static void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, int pts_num, int pts_den) {}
static void avpriv_request_sample(void *avc, const char *msg, ...) {}
static int av_timecode_init(AVTimecode *tc, AVRational rate, int flags, int frame, void *log_ctx) { return 0; }
static AVStream *avformat_new_stream(AVFormatContext *s, void *c) { return NULL; }
static int ff_alloc_extradata(void *par, int size) { return 0; }
static int ff_generate_avci_extradata(AVStream *st) { return 0; }
static const char *avcodec_get_name(int id) { return ""; }
static void av_dict_set_int(void **pm, const char *key, int64_t value, int flags) {}
static MXFPackage *mxf_resolve_strong_ref(MXFContext *mxf, UID *ref, int type) { return NULL; }
static void mxf_add_umid_metadata(void **pm, const char *key, MXFPackage *pkg) {}
static void mxf_parse_package_comments(MXFContext *mxf, void **pm, MXFPackage *pkg) {}
static void mxf_add_timecode_metadata(void **pm, const char *key, AVTimecode *tc) {}
static MXFStructuralComponent *mxf_resolve_sourceclip(MXFContext *mxf, UID *ref) { return NULL; }
static MXFPackage *mxf_resolve_source_package(MXFContext *mxf, UID ul, UID uid) { return NULL; }
static int mxf_add_metadata_stream(MXFContext *mxf, MXFTrack *track) { return 0; }
static MXFDescriptor *mxf_resolve_multidescriptor(MXFContext *mxf, void *descriptor, int track_id) { return NULL; }
static void PRINT_KEY(void *avcl, const char *key, UID ul) {}
static const MXFCodecUL *mxf_get_codec_ul(const MXFCodecUL *uls, UID *ul) { return NULL; }
static int mxf_get_wrapping_kind(UID *ul) { return 0; }
static int IS_KLV_KEY(UID *key, const UID klv) { return 0; }
static void mxf_parse_physical_source_package(MXFContext *mxf, MXFTrack *track, AVStream *st) {}
static int mxf_is_intra_only(MXFDescriptor *descriptor) { return 0; }
static int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq) { return 0; }
static AVRational av_inv_q(AVRational q) { return q; }
static AVMediaType avcodec_get_type(int codec_id) { return AVMEDIA_TYPE_VIDEO; }
static int FFMIN(int a, int b) { return a < b ? a : b; }