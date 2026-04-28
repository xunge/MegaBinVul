#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define AVERROR_INVALIDDATA -1
#define AV_LOG_ERROR 0
#define FRAMETYPE_INTRA 0
#define IVI_VLC_BITS 9
#define IVI_MBs_PER_TILE(w, h, mb_size) (((w) + (mb_size) - 1) / (mb_size) * (((h) + (mb_size) - 1) / (mb_size)))

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct IVIMbInfo {
    int16_t mv_x;
    int16_t mv_y;
    uint8_t type;
    uint8_t cbp;
    int8_t q_delta;
    int xpos;
    int ypos;
    int buf_offs;
} IVIMbInfo;

typedef struct IVITile {
    int xpos;
    int ypos;
    int width;
    int height;
    int num_MBs;
    IVIMbInfo *mbs;
    IVIMbInfo *ref_mbs;
} IVITile;

typedef struct IVIBandDesc {
    int mb_size;
    int blk_size;
    int pitch;
    int bufsize;
    int is_halfpel;
    int qdelta_present;
    int inherit_qdelta;
    int inherit_mv;
    int plane;
    int band_num;
} IVIBandDesc;

typedef struct VLCTable {
    int16_t (*table)[2];
} VLCTable;

typedef struct VLC {
    VLCTable *tab;
} VLC;

typedef struct IVI5DecContext {
    GetBitContext gb;
    int frame_type;
    int frame_flags;
    struct {
        IVIBandDesc bands[1];
    } planes[1];
    VLC mb_vlc;
} IVI5DecContext;

typedef struct AVCodecContext {
    void *log_ctx;
    void (*log_callback)(void*, int, const char*, va_list);
} AVCodecContext;

static inline int get_bits1(GetBitContext *s) {
    return 0;
}

static inline int get_bits(GetBitContext *s, int n) {
    return 0;
}

static inline int get_vlc2(GetBitContext *s, const void *table, int bits, int max_depth) {
    return 0;
}

static inline void align_get_bits(GetBitContext *s) {
}

static inline int IVI_TOSIGNED(int x) {
    return x;
}

static inline int ivi_scale_mv(int mv, int scale) {
    return mv;
}

static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {
}