#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    AVRational time_base;
    AVRational sample_aspect_ratio;
    int width;
    int height;
    int debug;
} AVCodecContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    int width;
    int height;
    int vo_type;
    int aspect_ratio_info;
    int low_delay;
    int picture_number;
    int progressive_sequence;
    int progressive_frame;
    int interlaced_dct;
    int quant_precision;
    int mpeg_quant;
    int quarter_sample;
    int data_partitioning;
    int vol_control_parameters;
    int intra_matrix[64];
    int chroma_intra_matrix[64];
    int inter_matrix[64];
    int chroma_inter_matrix[64];
    struct {
        int idct_permutation[64];
    } dsp;
    uint32_t codec_tag;
    int context_reinit;
    int sprite_warping_accuracy;
} MpegEncContext;

typedef struct Mpeg4DecContext {
    MpegEncContext m;
    int shape;
    int time_increment_bits;
    int t_frame;
    int vol_sprite_usage;
    int num_sprite_warping_points;
    int sprite_brightness_change;
    int cplx_estimation_trash_i;
    int cplx_estimation_trash_p;
    int cplx_estimation_trash_b;
    int resync_marker;
    int rvlc;
    int new_pred;
    int scalability;
    int enhancement_type;
} Mpeg4DecContext;

enum {
    FF_DEBUG_PICT_INFO = 1,
    FF_ASPECT_EXTENDED = 15,
    AV_LOG_ERROR = 16,
    AV_LOG_INFO = 24,
    AV_LOG_DEBUG = 48
};

enum {
    RECT_SHAPE = 0,
    BIN_ONLY_SHAPE = 1,
    GRAY_SHAPE = 2
};

enum {
    CHROMA_420 = 1
};

enum {
    STATIC_SPRITE = 1,
    GMC_SPRITE = 2
};

extern const AVRational ff_h263_pixel_aspect[16];
extern const uint8_t ff_zigzag_direct[64];
extern const uint8_t ff_mpeg4_default_intra_matrix[64];
extern const uint8_t ff_mpeg4_default_non_intra_matrix[64];

static inline void skip_bits(GetBitContext *gb, int n) {
    gb->index += n;
}

static inline unsigned int get_bits(GetBitContext *gb, int n) {
    return 0;
}

static inline unsigned int get_bits1(GetBitContext *gb) {
    return 0;
}

static inline int get_bits_left(GetBitContext *gb) {
    return 0;
}

static inline int get_bits_count(GetBitContext *gb) {
    return gb->index;
}

static inline void skip_bits1(GetBitContext *gb) {
    gb->index++;
}

static inline void skip_bits_long(GetBitContext *gb, int n) {
    gb->index += n;
}

static inline int check_marker(GetBitContext *gb, const char *msg) {
    return 1;
}

static inline int av_log2(unsigned int v) {
    return 0;
}

static inline void av_log(void *avcl, int level, const char *fmt, ...) {
}

#define AV_RL32(x) 0
#define AVERROR_INVALIDDATA (-1)