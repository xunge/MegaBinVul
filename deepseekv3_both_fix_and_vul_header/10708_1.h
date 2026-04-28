#include <stdint.h>

#define AVERROR_INVALIDDATA (-1)

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int bits_per_coded_sample;
} AVCodecContext;

typedef struct GetByteContext {
    // Add necessary fields here
} GetByteContext;

typedef struct RangeCoder {
    // Add necessary fields here
} RangeCoder;

typedef struct Model {
    // Add necessary fields here
} Model;

typedef struct SCPRContext {
    GetByteContext gb;
    RangeCoder rc;
    int cxshift;
    Model *pixel_model[3];
    Model *run_model[6];
    Model *op_model[6];
} SCPRContext;

static void reinit_tables(SCPRContext *s);
static void init_rangecoder(RangeCoder *rc, GetByteContext *gb);
static int decode_unit(SCPRContext *s, Model *model, int a, int *b);
static int decode_value(SCPRContext *s, Model *model, int a, int b, int *c);
static void bytestream2_skip(GetByteContext *gb, int n);