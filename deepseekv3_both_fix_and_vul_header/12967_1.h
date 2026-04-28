#include <stdint.h>
#include <stdlib.h>

#define av_cold
#define LAMBDA_FRAC_BITS 8
#define FF_MB_DECISION_RD 0

typedef struct RCEntry {
    int dummy;
} RCEntry;

typedef struct RCCMPEntry {
    int dummy; 
} RCCMPEntry;

typedef struct AVCodecContext {
    int qmax;
    int mb_decision;
} AVCodecContext;

typedef struct DNXHDEncContext {
    struct {
        AVCodecContext *avctx;
        int mb_num;
    } m;
    RCEntry *mb_rc;
    RCCMPEntry *mb_cmp;
    struct {
        int coding_unit_size;
    } *cid_table;
    int frame_bits;
    int qscale;
    int lambda;
    int min_padding;
} DNXHDEncContext;

#define FF_ALLOCZ_OR_GOTO(ctx, ptr, size, label) \
    do { \
        ptr = calloc(1, size); \
        if (!ptr) goto label; \
    } while (0)