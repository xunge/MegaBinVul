#include <stdint.h>
#include <stdlib.h>

typedef int32_t tmsize_t;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef int32_t int32;

struct TIFFRGBAImage;

typedef struct TIFF {
    void* tif_clientdata;
} TIFF;

typedef void (*tileContigRoutine)(struct TIFFRGBAImage*, uint32*, uint32, uint32, uint32, uint32, int32, int32, unsigned char*);

typedef struct TIFFRGBAImage {
    TIFF* tif;
    uint32 width;
    uint32 row_offset;
    uint32 col_offset;
    uint16 samplesperpixel;
    int stoponerr;
    struct {
        tileContigRoutine contig;
    } put;
} TIFFRGBAImage;

#define FLIP_VERTICALLY 1
#define FLIP_HORIZONTALLY 2
#define TIFF_TMSIZE_T_MAX ((tmsize_t)(~(tmsize_t)0 >> 1))
#define TIFFTAG_YCBCRSUBSAMPLING 530
#define TIFFTAG_ROWSPERSTRIP 278

tmsize_t TIFFStripSize(TIFF*);
tmsize_t TIFFScanlineSize(TIFF*);
uint32 TIFFComputeStrip(TIFF*, uint32, uint16);
void TIFFErrorExt(void*, const char*, const char*, ...);
void TIFFGetFieldDefaulted(TIFF*, uint32, ...);
int _TIFFReadEncodedStripAndAllocBuffer(TIFF*, uint32, void**, tmsize_t, tmsize_t);
void _TIFFfree(void*);
const char* TIFFFileName(TIFF*);
int setorientation(struct TIFFRGBAImage*);