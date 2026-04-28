#include <stdint.h>
#include <stdlib.h>

#define av_cold
#define AV_LOG_ERROR 0
#define AVERROR(e) (-(e))
#define EINVAL 22
#define ENOMEM 12
#define FF_API_CODED_FRAME 1
#define FF_DISABLE_DEPRECATION_WARNINGS
#define FF_ENABLE_DEPRECATION_WARNINGS
#define AV_PICTURE_TYPE_I 1
#define AV_PIX_FMT_PAL8 0

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    void *priv_data;
    struct {
        int pict_type;
        int key_frame;
    } *coded_frame;
} AVCodecContext;

typedef struct GIFContext {
    int transparent_index;
    void *lzw;
    int buf_size;
    uint8_t *buf;
    uint8_t *tmpl;
    uint32_t palette[256];
} GIFContext;

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
void *av_mallocz(size_t size);
void *av_malloc(size_t size);
int avpriv_set_systematic_pal2(uint32_t *palette, int pix_fmt);
void av_assert0(int condition);
size_t ff_lzw_encode_state_size;