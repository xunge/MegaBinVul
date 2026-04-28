#include <stdint.h>
#include <string.h>

typedef struct tiff {
    void* tif_clientdata;
} TIFF;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t row_offset;
    uint32_t col_offset;
} TIFFRGBAImage;

#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323

extern int TIFFIsTiled(TIFF*);
extern void TIFFErrorExt(void*, const char*, const char*, ...);
extern const char* TIFFFileName(TIFF*);
extern void TIFFGetFieldDefaulted(TIFF*, uint32_t, uint32_t*);
extern int TIFFRGBAImageOK(TIFF*, char*);
extern int TIFFRGBAImageBegin(TIFFRGBAImage*, TIFF*, int, char*);
extern int TIFFRGBAImageGet(TIFFRGBAImage*, uint32_t*, uint32_t, uint32_t);
extern void TIFFRGBAImageEnd(TIFFRGBAImage*);
extern void _TIFFmemset(void*, int, size_t);