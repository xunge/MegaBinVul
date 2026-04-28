#include <stdint.h>

#define BOT 0x1000000
#define AVERROR_INVALIDDATA (-1)

typedef struct RangeCoder {
    uint32_t range;
    uint32_t code;
    uint32_t low;
} RangeCoder;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct PixelModel {
    uint32_t total_freq;
    uint32_t freq[256];
    uint32_t lookup[16];
} PixelModel;

typedef struct SCPRContext {
    GetByteContext gb;
    RangeCoder rc;
    unsigned cbits;
    int (*get_freq)(struct RangeCoder *rc, unsigned totfr, unsigned *value);
    int (*decode)(struct GetByteContext *gb, struct RangeCoder *rc, unsigned cumfr, unsigned cnt_c, unsigned totfr);
} SCPRContext;