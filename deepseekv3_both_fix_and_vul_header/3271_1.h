#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define AV_LOG_ERROR 16
#define SMKTREE_BITS 9
#define INIT_VLC_LE 2

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct VLC {
    int bits;
    uint16_t *table;
    int table_size, table_allocated;
} VLC;

typedef struct HuffContext {
    int length;
    int maxlength;
    int current;
    uint32_t *bits;
    int *lengths;
    int *values;
} HuffContext;

typedef struct DBCtx {
    int escapes[3];
    VLC *v1;
    VLC *v2;
    int *recode1;
    int *recode2;
    int *last;
} DBCtx;

typedef struct SmackVContext {
    void *avctx;
} SmackVContext;

static inline void *av_mallocz(size_t size) { return calloc(1, size); }
static inline void av_free(void *ptr) { free(ptr); }
static inline void av_log(void *avctx, int level, const char *fmt, ...) {}
static inline int get_bits1(GetBitContext *gb) { return 0; }
static inline int get_bits(GetBitContext *gb, int n) { return 0; }
static inline void skip_bits1(GetBitContext *gb) {}
static inline int init_vlc(VLC *vlc, int nb_bits, int nb_codes,
                         const void *bits, int bits_wrap, int bits_size,
                         const void *codes, int codes_wrap, int codes_size,
                         int flags) { return 0; }
static inline void free_vlc(VLC *vlc) {}
static inline void smacker_decode_tree(GetBitContext *gb, HuffContext *hc, int length, int recurse) {}
static inline void smacker_decode_bigtree(GetBitContext *gb, HuffContext *hc, DBCtx *ctx) {}