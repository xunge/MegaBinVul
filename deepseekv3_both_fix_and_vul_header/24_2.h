#include <stdint.h>
#include <string.h>
#include <limits.h>

#define AV_LOG_ERROR 16

typedef struct HEVCLocalContext HEVCLocalContext;
typedef struct HEVCContext HEVCContext;
typedef struct AVFrame AVFrame;
typedef struct AVCodecContext AVCodecContext;

struct HEVCLocalContext {
    int start_of_tiles_x;
    int end_of_tiles_x;
};

struct ThreadFrame {
    int progress;
};

struct HEVCContext {
    HEVCLocalContext HEVClc;
    uint8_t *horizontal_bs;
    uint8_t *vertical_bs;
    uint8_t *cbf_luma;
    uint8_t *is_pcm;
    int bs_width;
    int bs_height;
    int is_decoded;
    int first_nal_type;
    int nal_unit_type;
    int poc;
    AVFrame *output_frame;
    AVFrame *frame;
    AVFrame *sao_frame;
    AVCodecContext *avctx;
    struct {
        int log2_ctb_size;
        int min_tb_width;
        int min_tb_height;
        int min_pu_width;
        int min_pu_height;
        int sao_enabled;
    } *sps;
    struct {
        int tiles_enabled_flag;
        int *column_width;
    } *pps;
    struct {
        struct ThreadFrame tf;
    } *ref;
};

int ff_hevc_set_new_ref(HEVCContext *s, AVFrame *frame, int poc);
int ff_hevc_frame_rps(HEVCContext *s);
int set_side_data(HEVCContext *s);
int ff_hevc_output_frame(HEVCContext *s, AVFrame *frame, int output);
void ff_thread_finish_setup(AVCodecContext *avctx);
void ff_thread_report_progress(struct ThreadFrame *tf, int progress, int field);
void av_frame_unref(AVFrame *frame);
void av_log(void *avcl, int level, const char *fmt, ...);