#include <stdint.h>

typedef struct AVCodecContext AVCodecContext;

enum AVCodecID {
    AV_CODEC_ID_MPEG4
};

typedef struct IDCTDSPContext {
    uint8_t idct_permutation[64];
    int mpeg4_studio_profile;
} IDCTDSPContext;

typedef struct ScanTable {
    uint8_t permutated[64];
    uint8_t raster_end[64];
} ScanTable;

typedef struct MpegEncContext {
    enum AVCodecID codec_id;
    int studio_profile;
    int alternate_scan;
    IDCTDSPContext idsp;
    AVCodecContext *avctx;
    ScanTable inter_scantable;
    ScanTable intra_scantable;
    ScanTable intra_h_scantable;
    ScanTable intra_v_scantable;
} MpegEncContext;

extern const uint8_t ff_alternate_vertical_scan[64];
extern const uint8_t ff_zigzag_direct[64];
extern const uint8_t ff_alternate_horizontal_scan[64];

void ff_idctdsp_init(IDCTDSPContext *idsp, AVCodecContext *avctx);
void ff_init_scantable(uint8_t *permutation, ScanTable *st, const uint8_t *src_scantable);

#define av_cold