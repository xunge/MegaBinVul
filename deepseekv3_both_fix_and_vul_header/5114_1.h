#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <limits.h>

#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)
#define MAX_UINT_BITS(bits) ((bits) < 32 ? (1U << (bits)) - 1 : UINT_MAX)

typedef struct CodedBitstreamContext CodedBitstreamContext;
typedef struct GetBitContext GetBitContext;

struct CodedBitstreamContext {
    void *log_ctx;
    int trace_enable;
};

extern void av_log(void *avcl, int level, const char *fmt, ...);
extern int get_bits_count(GetBitContext *s);
extern int get_bits_left(GetBitContext *s);
extern unsigned int get_bits1(GetBitContext *s);
extern unsigned int get_bits_long(GetBitContext *s, int n);
extern void ff_cbs_trace_syntax_element(CodedBitstreamContext *ctx, int position,
                                       const char *name, const char *str,
                                       const char *bits, uint32_t value);