#include <stdint.h>
#include <limits.h>

typedef struct GetBitContext {
    // dummy definition
    int dummy;
} GetBitContext;

typedef struct HEVCLocalContext {
    GetBitContext gb;
} HEVCLocalContext;

typedef struct HEVCPPS {
    int transquant_bypass_enable_flag;
} HEVCPPS;

typedef struct HEVCSPS {
    int ctb_width;
    int ctb_height;
    struct {
        int loop_filter_disable_flag;
        int enabled_flag;
    } pcm;
    int sao_enabled;
} HEVCSPS;

typedef struct HEVCContext {
    struct AVCodecContext *avctx;
    HEVCLocalContext HEVClc;
    int nal_unit_type;
    int max_ra;
    int poc;
    int is_decoded;
    int first_nal_type;
    void *ref;
    struct {
        int first_slice_in_pic_flag;
        int dependent_slice_segment_flag;
        int slice_type;
    } sh;
    HEVCSPS *sps;
    HEVCPPS *pps;
    int seq_decode;
} HEVCContext;

enum {
    NAL_VPS,
    NAL_SPS,
    NAL_PPS,
    NAL_SEI_PREFIX,
    NAL_SEI_SUFFIX,
    NAL_TRAIL_R,
    NAL_TRAIL_N,
    NAL_TSA_N,
    NAL_TSA_R,
    NAL_STSA_N,
    NAL_STSA_R,
    NAL_BLA_W_LP,
    NAL_BLA_W_RADL,
    NAL_BLA_N_LP,
    NAL_IDR_W_RADL,
    NAL_IDR_N_LP,
    NAL_CRA_NUT,
    NAL_RADL_N,
    NAL_RADL_R,
    NAL_RASL_N,
    NAL_RASL_R,
    NAL_EOS_NUT,
    NAL_EOB_NUT,
    NAL_AUD,
    NAL_FD_NUT,
    I_SLICE
};

#define AV_LOG_ERROR 0
#define AV_LOG_INFO 0
#define AV_LOG_WARNING 0
#define AV_EF_EXPLODE 0
#define AVERROR_INVALIDDATA 0
#define pcm_enabled_flag pcm.enabled_flag

struct AVCodecContext {
    int err_recognition;
};

int init_get_bits8(GetBitContext *gb, const uint8_t *buf, int byte_size);
int hls_nal_unit(HEVCContext *s);
int ff_hevc_decode_nal_vps(HEVCContext *s);
int ff_hevc_decode_nal_sps(HEVCContext *s);
int ff_hevc_decode_nal_pps(HEVCContext *s);
int ff_hevc_decode_nal_sei(HEVCContext *s);
int hls_slice_header(HEVCContext *s);
int hevc_frame_start(HEVCContext *s);
int ff_hevc_slice_rpl(HEVCContext *s);
int hls_slice_data(HEVCContext *s);
void restore_tqb_pixels(HEVCContext *s);
void av_log(void *avcl, int level, const char *fmt, ...);
#define IS_BLA(s) 0
#define IS_IDR(s) 0