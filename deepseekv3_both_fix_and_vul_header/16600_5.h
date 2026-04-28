#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef struct TIFF {
    void* tif_clientdata;
} TIFF;

typedef void (*tileContigRoutine)(struct TIFFRGBAImage*, uint32_t*, uint32_t, int32_t, uint32_t, uint32_t, int32_t, int32_t, unsigned char*);

typedef struct TIFFRGBAImage {
    TIFF* tif;
    struct {
        tileContigRoutine contig;
    } put;
    uint32_t col_offset;
    uint32_t row_offset;
    uint32_t samplesperpixel;
    int stoponerr;
} TIFFRGBAImage;

typedef int32_t tmsize_t;

#define FLIP_VERTICALLY 1
#define FLIP_HORIZONTALLY 2
#define TIFFTAG_TILEWIDTH 0
#define TIFFTAG_TILELENGTH 0

tmsize_t TIFFTileSize(TIFF*);
tmsize_t TIFFTileRowSize(TIFF*);
void TIFFErrorExt(void*, const char*, const char*, ...);
void TIFFGetField(TIFF*, int, ...);
int setorientation(TIFFRGBAImage*);
tmsize_t _TIFFReadTileAndAllocBuffer(TIFF*, void**, tmsize_t, uint32_t, uint32_t, uint32_t, uint32_t);
void _TIFFfree(void*);
const char* TIFFFileName(TIFF*);

#define uint32 uint32_t
#define int32 int32_t