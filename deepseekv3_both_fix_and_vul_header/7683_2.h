#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <sys/types.h>

typedef ssize_t tmsize_t;
typedef unsigned long WordType;

#define BITS_MIN 9
#define BITS_MAX 12
#define CODE_FIRST 257
#define CODE_CLEAR 256
#define CODE_EOI 257
#define CSIZE (1 << BITS_MAX)
#define MAXCODE(n) ((1 << (n)) - 1)

typedef struct code_t {
    struct code_t* next;
    uint8_t firstchar;
    uint8_t value;
    unsigned short length;
    bool repeated;
} code_t;

typedef struct {
    code_t* dec_codetab;
    code_t* dec_free_entp;
    code_t* dec_maxcodep;
    code_t* dec_oldcodep;
    code_t* dec_codep;
    unsigned short lzw_nbits;
    WordType lzw_nextdata;
    long lzw_nextbits;
    long dec_nbitsmask;
    uint64_t dec_bitsleft;
    tmsize_t old_tif_rawcc;
    tmsize_t dec_restart;
    int read_error;
} LZWCodecState;

typedef struct tiff {
    void* tif_clientdata;
    uint32_t tif_curstrip;
    uint32_t tif_row;
    const char* tif_name;
    uint8_t* tif_rawcp;
    tmsize_t tif_rawcc;
} TIFF;

void TIFFErrorExt(void*, const char*, const char*, ...);
LZWCodecState* DecoderState(TIFF* tif);

#define GetNextCodeLZW() \
    do { \
        if (dec_bitsleft < (uint64_t)nbits) { \
            TIFFErrorExt(tif->tif_clientdata, module, \
                "LZWDecode: Strip %"PRIu32" not terminated with EOI code", \
                tif->tif_curstrip); \
            goto no_eoi; \
        } \
        nextdata = (nextdata << 8) | *bp++; \
        nextbits += 8; \
        dec_bitsleft -= 8; \
        if (nextbits < nbits) { \
            if (dec_bitsleft < (uint64_t)(nbits - nextbits)) { \
                TIFFErrorExt(tif->tif_clientdata, module, \
                    "LZWDecode: Strip %"PRIu32" not terminated with EOI code", \
                    tif->tif_curstrip); \
                goto no_eoi; \
            } \
            nextdata = (nextdata << 8) | *bp++; \
            nextbits += 8; \
            dec_bitsleft -= 8; \
        } \
        code = (nextdata >> (nextbits - nbits)) & nbitsmask; \
        nextbits -= nbits; \
    } while (0)