#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef struct GetBitContext {
    unsigned int index;
    const uint8_t *buffer;
    int size_in_bits;
} GetBitContext;

typedef struct HEVCSPS {
    int ctb_width;
    int ctb_height;
} HEVCSPS;

typedef struct HEVCPPS {
    HEVCSPS *sps;
} HEVCPPS;

typedef struct HEVCSEI {
    // Minimal definition
} HEVCSEI;

typedef struct HEVCSliceHeader {
    int first_slice_in_pic_flag;
    int dependent_slice_segment_flag;
    int slice_type;
    int num_entry_point_offsets;
} HEVCSliceHeader;

typedef struct AVHWAccel {
    int (*start_frame)(void *avctx, const uint8_t *buffer, uint32_t size);
    int (*decode_slice)(void *avctx, const uint8_t *buffer, uint32_t size);
} AVHWAccel;

typedef struct AVCodecContext {
    AVHWAccel *hwaccel;
    int err_recognition;
    void *priv_data;
} AVCodecContext;

typedef struct HEVCLocalContext {
    GetBitContext gb;
} HEVCLocalContext;

typedef struct H2645NAL {
    GetBitContext gb;
    int type;
    int temporal_id;
    const uint8_t *raw_data;
    int raw_size;
} H2645NAL;

typedef struct HEVCContext {
    HEVCLocalContext *HEVClc;
    int nal_unit_type;
    int temporal_id;
    AVCodecContext *avctx;
    HEVCPPS ps;
    int apply_defdispwin;
    HEVCSEI sei;
    void *ref;
    int max_ra;
    int poc;
    int is_decoded;
    int first_nal_type;
    HEVCSliceHeader sh;
    int threads_number;
    int seq_decode;
} HEVCContext;

#define HEVC_NAL_VPS 32
#define HEVC_NAL_SPS 33
#define HEVC_NAL_PPS 34
#define HEVC_NAL_SEI_PREFIX 39
#define HEVC_NAL_SEI_SUFFIX 40
#define HEVC_NAL_TRAIL_R 1
#define HEVC_NAL_TRAIL_N 0
#define HEVC_NAL_TSA_N 2
#define HEVC_NAL_TSA_R 3
#define HEVC_NAL_STSA_N 4
#define HEVC_NAL_STSA_R 5
#define HEVC_NAL_BLA_W_LP 16
#define HEVC_NAL_BLA_W_RADL 17
#define HEVC_NAL_BLA_N_LP 18
#define HEVC_NAL_IDR_W_RADL 19
#define HEVC_NAL_IDR_N_LP 20
#define HEVC_NAL_CRA_NUT 21
#define HEVC_NAL_RADL_N 6
#define HEVC_NAL_RADL_R 7
#define HEVC_NAL_RASL_N 8
#define HEVC_NAL_RASL_R 9
#define HEVC_NAL_EOS_NUT 10
#define HEVC_NAL_EOB_NUT 11
#define HEVC_NAL_AUD 35
#define HEVC_NAL_FD_NUT 38
#define HEVC_SLICE_I 2

#define IS_BLA(x) 0
#define IS_IDR(x) 0

#define AVERROR_INVALIDDATA (-1)
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_INFO 32
#define AV_EF_EXPLODE (1 << 0)

void av_log(void *avctx, int level, const char *fmt, ...);
int ff_hevc_decode_nal_vps(GetBitContext *gb, AVCodecContext *avctx, HEVCPPS *ps);
int ff_hevc_decode_nal_sps(GetBitContext *gb, AVCodecContext *avctx, HEVCPPS *ps, int apply_defdispwin);
int ff_hevc_decode_nal_pps(GetBitContext *gb, AVCodecContext *avctx, HEVCPPS *ps);
int ff_hevc_decode_nal_sei(GetBitContext *gb, AVCodecContext *avctx, HEVCSEI *sei, HEVCPPS *ps, int nal_unit_type);
int hls_slice_header(HEVCContext *s);
int hevc_frame_start(HEVCContext *s);
int ff_hevc_slice_rpl(HEVCContext *s);
int hls_slice_data_wpp(HEVCContext *s, const H2645NAL *nal);
int hls_slice_data(HEVCContext *s);