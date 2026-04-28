#include <stdint.h>
#include <stdlib.h>

typedef struct AVCodecContext {
    void *priv_data;
    int flags;
    int codec_id;
    int coded_width;
    int coded_height;
    int extradata_size;
    uint8_t *extradata;
    int pix_fmt;
    int has_b_frames;
    int skip_frame;
    int err_recognition;
    struct {
        int (*start_frame)(struct AVCodecContext *avctx, uint8_t *buffer, int buffer_size);
        int (*end_frame)(struct AVCodecContext *avctx);
    } *hwaccel;
    int sample_aspect_ratio;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int format;
    int width;
    int height;
    uint8_t *data[4];
    int linesize[4];
    int pict_type;
    int key_frame;
} AVFrame;

typedef struct GetBitContext {
    uint8_t *buffer;
    uint8_t *buffer_end;
} GetBitContext;

typedef struct Picture {
    AVFrame *f;
} Picture;

typedef struct MpegEncContext {
    int low_delay;
    Picture *next_picture_ptr;
    AVCodecContext *avctx;
    int codec_id;
    int width;
    int height;
    int context_initialized;
    int divx_packed;
    int bitstream_buffer_size;
    uint8_t *bitstream_buffer;
    GetBitContext gb;
    int msmpeg4_version;
    int picture_number;
    Picture *picture;
    Picture *current_picture_ptr;
    Picture *last_picture_ptr;
    int pict_type;
    int droppable;
    int no_rounding;
    int studio_profile;
    int context_reinit;
    int gob_index;
    int mb_x;
    int mb_y;
    int mb_width;
    int mb_height;
    int slice_height;
    int mb_num;
    struct {
        int error_occurred;
        int *error_status_table;
    } er;
    struct {
        void *qpel_put;
        void *qpel_avg;
    } me;
    struct {
        void *put_qpel_pixels_tab;
        void *avg_qpel_pixels_tab;
        void *put_no_rnd_qpel_pixels_tab;
    } qdsp;
    struct {
        void *idct;
    } idsp;
    struct {
        void *parse_context;
    };
    int h263_flv;
    int codec_tag;
    int next_p_frame_damaged;
    Picture current_picture;
    int h263_pred;
} MpegEncContext;

#define AV_CODEC_FLAG_TRUNCATED 0x0008
#define AV_CODEC_ID_MPEG4 13
#define AV_CODEC_ID_H263 4
#define AV_CODEC_ID_H263P 5
#define AV_CODEC_ID_H263I 6
#define AV_PIX_FMT_YUV420P 0
#define AV_PIX_FMT_NONE -1
#define AVERROR(e) (-(e))
#define ENOSYS 38
#define AVERROR_UNKNOWN (-1)
#define AVDISCARD_NONREF 1
#define AVDISCARD_NONKEY 2
#define AVDISCARD_ALL 3
#define AV_RL32(x) (*(const uint32_t*)(x))
#define AV_CEIL_RSHIFT(a,b) ((a) > 0 ? ((a) + (1<<(b))-1)>>(b) : (a)>>(b))
#define CONFIG_MPEG4_DECODER 1
#define CONFIG_H263_DECODER 1
#define CONFIG_H263P_DECODER 1
#define CONFIG_WMV2_DECODER 1
#define CONFIG_MSMPEG4_DECODER 1
#define CONFIG_H263I_DECODER 1
#define CONFIG_FLV_DECODER 1
#define MAX_NVOP_SIZE 100
#define FRAME_SKIPPED 1
#define ER_MB_ERROR 1
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
#define AV_EF_EXPLODE 0x0001
#define FF_QSCALE_TYPE_MPEG1 0
#define AVERROR_INVALIDDATA (-1)

enum AVPictureType {
    AV_PICTURE_TYPE_NONE = 0,
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P,
    AV_PICTURE_TYPE_B,
    AV_PICTURE_TYPE_S,
    AV_PICTURE_TYPE_SI,
    AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI
};

#define FFSWAP(type,a,b) do{type SWAP_tmp= b; b= a; a= SWAP_tmp;}while(0)

int av_frame_ref(AVFrame *dst, const AVFrame *src);
void av_log(void *avctx, int level, const char *fmt, ...);
int ff_mpeg4_find_frame_end(void *parse_context, const uint8_t *buf, int buf_size);
int ff_h263_find_frame_end(void *parse_context, const uint8_t *buf, int buf_size);
int ff_combine_frame(void *parse_context, int next, const uint8_t **buf, int *buf_size);
int init_get_bits8(GetBitContext *gb, const uint8_t *buffer, int byte_size);
void ff_mpv_idct_init(MpegEncContext *s);
int ff_wmv2_decode_picture_header(MpegEncContext *s);
int ff_msmpeg4_decode_picture_header(MpegEncContext *s);
int ff_mpeg4_decode_picture_header(void *priv_data, GetBitContext *gb);
int ff_intel_h263_decode_picture_header(MpegEncContext *s);
int ff_flv_decode_picture_header(MpegEncContext *s);
int ff_h263_decode_picture_header(MpegEncContext *s);
int get_consumed_bytes(MpegEncContext *s, int buf_size);
int h263_get_format(AVCodecContext *avctx);
int ff_mpv_common_init(MpegEncContext *s);
int ff_find_unused_picture(void *avctx, void *picture, int unused);
int ff_mpeg4_workaround_bugs(AVCodecContext *avctx);
int ff_set_dimensions(AVCodecContext *avctx, int width, int height);
void ff_set_sar(AVCodecContext *avctx, int sar);
int ff_mpv_common_frame_size_change(MpegEncContext *s);
int H263_GOB_HEIGHT(int height);
int ff_mpv_frame_start(MpegEncContext *s, AVCodecContext *avctx);
void ff_thread_finish_setup(AVCodecContext *avctx);
void ff_mpeg_er_frame_start(MpegEncContext *s);
int ff_wmv2_decode_secondary_picture_header(MpegEncContext *s);
int decode_slice(MpegEncContext *s);
int ff_h263_resync(MpegEncContext *s);
void ff_mpeg4_clean_buffers(MpegEncContext *s);
int ff_msmpeg4_decode_ext_header(MpegEncContext *s, int buf_size);
void ff_er_frame_end(void *er);
int ff_mpv_frame_end(MpegEncContext *s);
int ff_mpeg4_frame_end(AVCodecContext *avctx, const uint8_t *buf, int buf_size);
void ff_print_debug_info(MpegEncContext *s, void *picture_ptr, AVFrame *pict);
void ff_mpv_export_qp_table(MpegEncContext *s, AVFrame *pict, void *picture_ptr, int type);
int av_frame_make_writable(AVFrame *frame);
void av_assert1(int condition);
int get_bits_left(GetBitContext *gb);