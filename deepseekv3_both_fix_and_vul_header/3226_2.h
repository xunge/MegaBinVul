#include <stdint.h>
#include <stdlib.h>

#define CODEC_CAP_HWACCEL_VDPAU 0
#define FF_DEBUG_ER 0
#define AV_EF_EXPLODE 0
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 0
#define AV_LOG_INFO 0
#define PICT_FRAME 0
#define VP_START 0
#define ER_AC_END 0
#define ER_MV_END 0
#define ER_DC_END 0
#define ER_AC_ERROR 0
#define ER_MB_ERROR 0
#define ER_MB_END 0
#define ER_DC_ERROR 0
#define ER_MV_ERROR 0
#define FF_EC_DEBLOCK 0
#define AV_PICTURE_TYPE_B 0
#define MB_TYPE_INTRA4x4 0
#define MB_TYPE_16x16 0
#define MB_TYPE_L0 0
#define MV_DIR_BACKWARD 0
#define MV_DIR_FORWARD 0
#define MV_TYPE_8X8 0
#define MV_TYPE_16X16 0
#define AV_CODEC_ID_H264 0
#define CONFIG_MPEG_XVMC_DECODER 0

typedef struct AVCodec {
    int capabilities;
} AVCodec;

typedef struct AVCodecContext {
    int lowres;
    int skip_top;
    int skip_bottom;
    int debug;
    int err_recognition;
    int error_concealment;
    int codec_id;
    int xvmc_acceleration;
    void *hwaccel;
    AVCodec *codec;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[3];
    int linesize[3];
    int motion_subsample_log2;
    uint8_t *ref_index[2];
    int16_t (*motion_val[2])[2];
    uint32_t *mb_type;
} AVFrame;

typedef struct Picture {
    AVFrame f;
    int16_t *motion_val_base[2];
} Picture;

typedef struct MpegEncContext {
    int b8_stride;
    int mb_height;
    int mb_width;
    int mb_stride;
    int mb_num;
    int *mb_index2xy;
    int *error_status_table;
    uint8_t *mbskip_table;
    uint8_t *mbintra_table;
    int pict_type;
    int picture_structure;
    int error_count;
    int err_recognition;
    int partitioned_frame;
    AVCodecContext *avctx;
    Picture *current_picture_ptr;
    Picture current_picture;
    Picture last_picture;
    Picture next_picture;
    Picture *next_picture_ptr;
    int16_t (*block)[64];
    int mb_x;
    int mb_y;
    int mv_dir;
    int mv_type;
    int mb_intra;
    int mb_skipped;
    int16_t mv[2][4][2];
    int pp_time;
    int pb_time;
    int linesize;
    int uvlinesize;
    int16_t *dc_val[3];
    struct {
        void (*clear_blocks)(int16_t *block);
    } dsp;
} MpegEncContext;

#define IS_INTRA(mb_type) ((mb_type) & MB_TYPE_INTRA4x4)
#define IS_8X8(mb_type) (0)
#define IS_INTER(mb_type) (!IS_INTRA(mb_type))

char av_get_picture_type_char(int pict_type);
void *av_mallocz(size_t size);
void av_log(void *avcl, int level, const char *fmt, ...);
void ff_thread_await_progress(AVFrame *f, int mb_y, int progress);
void decode_mb(MpegEncContext *s, int is_h264);
void guess_mv(MpegEncContext *s);
void guess_dc(MpegEncContext *s, int16_t *dc_val, int width, int height, int stride, int is_luma);
void filter181(int16_t *src, int width, int height, int stride);
void put_dc(MpegEncContext *s, uint8_t *dest_y, uint8_t *dest_cb, uint8_t *dest_cr, int mb_x, int mb_y);
void h_block_filter(MpegEncContext *s, uint8_t *dst, int width, int height, int stride, int is_luma);
void v_block_filter(MpegEncContext *s, uint8_t *dst, int width, int height, int stride, int is_luma);
int is_intra_more_likely(MpegEncContext *s);