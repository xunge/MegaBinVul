#include <stdint.h>
#include <stdlib.h>

typedef struct TIFF {
    void* tif_clientdata;
} TIFF;

typedef struct TIFFRGBAImage {
    TIFF* tif;
    uint32_t width;
    uint32_t row_offset;
    uint32_t col_offset;
    uint16_t samplesperpixel;
    int alpha;
    int stoponerr;
    uint16_t photometric;
    struct {
        void (*separate)(struct TIFFRGBAImage*, uint32_t*, uint32_t, uint32_t, uint32_t, uint32_t, int32_t, int32_t, 
                        unsigned char*, unsigned char*, unsigned char*, unsigned char*);
    } put;
} TIFFRGBAImage;

typedef int32_t tmsize_t;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef int32_t int32;

#define FLIP_VERTICALLY 1
#define FLIP_HORIZONTALLY 2
#define TIFF_TMSIZE_T_MAX ((tmsize_t)(~(tmsize_t)0 >> 1))
#define PHOTOMETRIC_MINISWHITE 0
#define PHOTOMETRIC_MINISBLACK 1
#define PHOTOMETRIC_PALETTE 3
#define TIFFTAG_ROWSPERSTRIP 278

typedef void (*tileSeparateRoutine)(TIFFRGBAImage*, uint32*, uint32, uint32, uint32, uint32, int32, int32, 
                                  unsigned char*, unsigned char*, unsigned char*, unsigned char*);

extern tmsize_t TIFFStripSize(TIFF*);
extern tmsize_t _TIFFMultiplySSize(TIFF*, int, tmsize_t, const char*);
extern int setorientation(TIFFRGBAImage*);
extern void TIFFGetFieldDefaulted(TIFF*, int, uint32*);
extern tmsize_t TIFFScanlineSize(TIFF*);
extern uint32 TIFFComputeStrip(TIFF*, uint32, uint16);
extern tmsize_t _TIFFReadEncodedStripAndAllocBuffer(TIFF*, uint32, void**, tmsize_t, tmsize_t);
extern tmsize_t TIFFReadEncodedStrip(TIFF*, uint32, void*, tmsize_t);
extern void TIFFErrorExt(void*, const char*, const char*);
extern const char* TIFFFileName(TIFF*);
extern void _TIFFfree(void*);