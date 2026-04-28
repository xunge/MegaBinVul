#include <stdint.h>
#include <string.h>

typedef struct LagarithContext {
    int zeros_rem;
    void *avctx;
} LagarithContext;

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define AVERROR_INVALIDDATA (-1)
#define AV_LOG_ERROR 16

static int lag_calc_zero_run(uint8_t val);
static void av_log(void *avctx, int level, const char *fmt, ...);