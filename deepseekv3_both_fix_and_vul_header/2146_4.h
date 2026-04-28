#include <stdint.h>
#include <string.h>

typedef struct GetBitContext GetBitContext;

typedef struct VLC {
    int bits;
    struct {
        void *table;
    } *tab;
} VLC;

typedef struct RVMapDesc {
    uint32_t eob_sym;
    uint32_t esc_sym;
    const uint8_t *runtab;
    const int16_t *valtab;
} RVMapDesc;

typedef struct IVIMbInfo {
    uint32_t type;
    uint32_t cbp;
    uint32_t buf_offs;
    int q_delta;
    int mv_x;
    int mv_y;
} IVIMbInfo;

typedef struct IVITile {
    IVIMbInfo *mbs;
    int num_MBs;
} IVITile;

typedef struct IVIBandDesc {
    int blk_size;
    int mb_size;
    int pitch;
    int is_halfpel;
    int is_2d_trans;
    int transform_size;
    uint32_t glob_quant;
    const uint16_t *intra_base;
    const uint16_t *inter_base;
    const uint8_t *intra_scale;
    const uint8_t *inter_scale;
    int16_t *buf;
    int16_t *ref_buf;
    const uint8_t *scan;
    RVMapDesc *rv_map;
    VLC blk_vlc;
    void (*inv_transform)(int32_t *in, int16_t *out, uint32_t pitch, const uint8_t *flags);
    void (*dc_transform)(int32_t *in, int16_t *out, uint32_t pitch, int blk_size);
} IVIBandDesc;

#define IVI_VLC_BITS 9
#define AVERROR_INVALIDDATA (-1)
#define AV_LOG_ERROR 16

static inline int av_clip(int a, int amin, int amax) {
    if (a < amin) return amin;
    if (a > amax) return amax;
    return a;
}

static inline int FFSIGN(int x) {
    return (x >> 31) | ((unsigned)-x >> 31);
}

static inline int IVI_TOSIGNED(int x) {
    return (x >> 1) ^ -(x & 1);
}

static inline void av_dlog(void *avcl, const char *fmt, ...) {}
static inline void av_log(void *avcl, int level, const char *fmt, ...) {}

static inline unsigned int get_vlc2(GetBitContext *s, const void *table, int bits, int max_depth) {
    return 0;
}

static inline void align_get_bits(GetBitContext *s) {}

void ff_ivi_mc_8x8_delta(int16_t *buf, const int16_t *ref_buf, uint32_t pitch, int mc_type);
void ff_ivi_mc_8x8_no_delta(int16_t *buf, const int16_t *ref_buf, uint32_t pitch, int mc_type);
void ff_ivi_mc_4x4_delta(int16_t *buf, const int16_t *ref_buf, uint32_t pitch, int mc_type);
void ff_ivi_mc_4x4_no_delta(int16_t *buf, const int16_t *ref_buf, uint32_t pitch, int mc_type);