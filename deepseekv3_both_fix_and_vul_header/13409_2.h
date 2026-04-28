#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

typedef long tmsize_t;
typedef unsigned long long WordType;

typedef struct code_t {
    uint8_t value;
    bool repeated;
    unsigned short length;
    uint8_t firstchar;
    struct code_t *next;
} code_t;

typedef struct {
    code_t *dec_codetab;
    code_t *dec_codep;
    code_t *dec_oldcodep;
    code_t *dec_free_entp;
    code_t *dec_maxcodep;
    uint64_t dec_bitsleft;
    tmsize_t old_tif_rawcc;
    unsigned short lzw_nbits;
    WordType lzw_nextdata;
    long lzw_nextbits;
    long dec_nbitsmask;
    tmsize_t dec_restart;
    int read_error;
} LZWCodecState;

typedef struct {
    uint8_t *tif_rawcp;
    tmsize_t tif_rawcc;
    uint32_t tif_row;
    uint32_t tif_curstrip;
    char *tif_name;
} TIFF;

#define CODE_FIRST 257
#define CODE_EOI 258
#define CODE_CLEAR 256
#define BITS_MAX 12
#define BITS_MIN 9
#define CSIZE (1 << BITS_MAX)
#define MAXCODE(n) ((1 << (n)) - 1)

static LZWCodecState *DecoderState(TIFF *tif);
static void GetNextCodeLZW(void);
static void TIFFErrorExtR(TIFF *tif, const char *module, const char *fmt, ...);