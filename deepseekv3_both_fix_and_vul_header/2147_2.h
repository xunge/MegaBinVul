#include <stdint.h>
#include <stdlib.h>

#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define IVI4_STREAM_ANALYSER 0
#define FRAMETYPE_INTRA 0
#define IVI_BLK_HUFF 0

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    void *opaque;
} AVCodecContext;

typedef struct IVIBandDesc {
    int plane;
    int band_num;
    int is_empty;
    int is_halfpel;
    int checksum_present;
    uint16_t checksum;
    int mb_size;
    int blk_size;
    int inherit_mv;
    int inherit_qdelta;
    int glob_quant;
    void (*inv_transform)(int16_t *block, const uint8_t *scan);
    void (*dc_transform)(int16_t *block, const uint8_t *scan);
    int is_2d_trans;
    int transform_size;
    const uint8_t *scan;
    int quant_mat;
    void *blk_vlc;
    int rvmap_sel;
    int num_corr;
    uint8_t corr[122];
    const int16_t *intra_base;
    const int16_t *inter_base;
    const int16_t *intra_scale;
    const int16_t *inter_scale;
} IVIBandDesc;

typedef struct IVI4DecContext {
    GetBitContext gb;
    int frame_type;
#if IVI4_STREAM_ANALYSER
    int uses_fullpel;
    int uses_haar;
#endif
} IVI4DecContext;

typedef struct Transform {
    void (*inv_trans)(int16_t *block, const uint8_t *scan);
    void (*dc_trans)(int16_t *block, const uint8_t *scan);
    int is_2d_trans;
} Transform;

static const Transform transforms[] = {
    {0}
};

extern const uint8_t *scan_index_to_tab[];
extern const uint8_t quant_index_to_tab[];
extern const int16_t ivi4_quant_8x8_intra[][64];
extern const int16_t ivi4_quant_8x8_inter[][64];
extern const int16_t ivi4_quant_4x4_intra[][16];
extern const int16_t ivi4_quant_4x4_inter[][16];

int get_bits(GetBitContext *s, int n);
int get_bits1(GetBitContext *s);
void skip_bits(GetBitContext *s, int n);
void align_get_bits(GetBitContext *s);
int ff_ivi_dec_huff_desc(GetBitContext *gb, int desc_coded, int which_tab, void *ctx, AVCodecContext *avctx);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
void av_log_ask_for_sample(AVCodecContext *avctx, const char *fmt, ...);