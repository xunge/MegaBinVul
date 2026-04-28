#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef struct tiff {
    void (*tif_setupdecode)(struct tiff*);
    unsigned char* tif_rawdata;
    uint32_t tif_rawcc;
    void* tif_clientdata;
    void (*tif_decoderow)(struct tiff*);
    void (*tif_decodestrip)(struct tiff*);
    void (*tif_decodetile)(struct tiff*);
} TIFF;

typedef struct {
    int* dec_codetab;
    void (*dec_decode)(TIFF*);
    int lzw_maxcode;
    int lzw_nbits;
    int lzw_nextbits;
    int lzw_nextdata;
    int dec_restart;
    int dec_nbitsmask;
    int dec_bitsleft;
    int old_tif_rawcc;
    int* dec_free_entp;
    int* dec_oldcodep;
    int* dec_maxcodep;
    int read_error;
} LZWCodecState;

#define BITS_MIN 9
#define MAXCODE(n) ((1 << (n)) - 1)
#define CODE_FIRST 257

extern LZWCodecState* DecoderState(TIFF*);
extern void LZWDecodeCompat(TIFF*);
extern void LZWDecode(TIFF*);
extern void TIFFWarningExt(void*, const char*, const char*);
extern void TIFFErrorExt(void*, const char*, const char*);