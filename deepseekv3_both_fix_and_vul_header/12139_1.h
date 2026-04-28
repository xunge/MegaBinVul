#include <stdint.h>
#include <stdlib.h>

#define MAX_PREFIX_ALPHABET_SIZE 32768
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_BUFFER_TOO_SMALL (-2)
#define AVERROR(ENOMEM) (-3)
#define VLC_INIT_LE 0

typedef struct VLC {
    int bits;
    void *table;
} VLC;

typedef struct JXLSymbolDistribution {
    int alphabet_size;
    VLC vlc;
    int default_symbol;
} JXLSymbolDistribution;

typedef struct JXLEntropyDecoder {
    void *logctx;
} JXLEntropyDecoder;

typedef struct GetBitContext {
    int dummy;
} GetBitContext;

static const uint8_t prefix_codelen_map[18] = {0};
static const uint8_t level0_table[32] = {0};

static int get_bits(GetBitContext *gb, int n) { return 0; }
static int get_bits_left(GetBitContext *gb) { return 0; }
static int get_vlc2(GetBitContext *gb, const void *table, int bits, int max_depth) { return 0; }
static int read_simple_vlc_prefix(GetBitContext *gb, JXLEntropyDecoder *dec, JXLSymbolDistribution *dist) { return 0; }
static int ff_vlc_init_from_lengths(VLC *vlc, int nb_bits, int nb_codes, const int8_t *lens, int lens_wrap, const void *syms, int syms_wrap, int syms_size, int flags, int init, void *logctx) { return 0; }
static void ff_vlc_free(VLC *vlc) {}
static void *av_mallocz(size_t size) { return NULL; }
static void av_freep(void *ptr) {}

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))