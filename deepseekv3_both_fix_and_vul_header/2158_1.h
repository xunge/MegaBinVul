#include <stdint.h>
#include <string.h>

#define AV_LOG_ERROR 16

typedef struct AVCodecContext AVCodecContext;

typedef struct IVIMbInfo {
    int16_t mv_x;
    int16_t mv_y;
    uint8_t type;
    uint8_t cbp;
    int buf_offs;
    int xpos;
    int ypos;
    int q_delta;
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
    int is_halfpel;
    int inherit_mv;
    int inherit_qdelta;
    int qdelta_present;
    int plane;
    int band_num;
    int glob_quant;
    int16_t *buf;
    const int16_t *ref_buf;
} IVIBandDesc;

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int IVI_MBs_PER_TILE(int width, int height, int mb_size);
void ff_ivi_mc_8x8_no_delta(int16_t *buf, const int16_t *ref_buf, uint32_t pitch, int mc_type);
void ff_ivi_mc_4x4_no_delta(int16_t *buf, const int16_t *ref_buf, uint32_t pitch, int mc_type);
int ivi_scale_mv(int mv, int scale);