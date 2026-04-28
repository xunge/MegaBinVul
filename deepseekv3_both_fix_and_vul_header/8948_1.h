#include <stdint.h>
#include <stdlib.h>

#define av_cold
#define AVERROR_INVALIDDATA -1
#define AVERROR(ENOMEM) -2
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))

typedef struct VLC {
    struct {
        int num_rows;
    } cust_desc;
} VLC;

typedef struct IVIBandDesc {
    int plane;
    int band_num;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t aheight;
    int16_t *bufs[4];
    uint32_t bufsize;
    VLC blk_vlc;
} IVIBandDesc;

typedef struct IVIPlaneDesc {
    uint32_t width;
    uint32_t height;
    int num_bands;
    IVIBandDesc *bands;
} IVIPlaneDesc;

typedef struct IVIPicConfig {
    int pic_width;
    int pic_height;
    int luma_bands;
    int chroma_bands;
} IVIPicConfig;

void ivi_free_buffers(IVIPlaneDesc *planes);
void *av_mallocz(size_t size);
void *av_mallocz_array(size_t nmemb, size_t size);