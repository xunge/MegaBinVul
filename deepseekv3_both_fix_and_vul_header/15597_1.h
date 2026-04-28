#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define EMSG_BUF_SIZE 1024

typedef struct {
    uint32_t height;
    uint32_t width;
    uint32_t row_offset;
    uint32_t col_offset;
} TIFFRGBAImage;

typedef struct TIFF TIFF;
#define TIFFTAG_ROWSPERSTRIP 0

int TIFFIsTiled(TIFF*);
const char* TIFFFileName(TIFF*);
void TIFFErrorExtR(TIFF*, const char*, const char*, ...);
void TIFFGetFieldDefaulted(TIFF*, int, uint32_t*);
int TIFFRGBAImageOK(TIFF*, char*);
int TIFFRGBAImageBegin(TIFFRGBAImage*, TIFF*, int, char*);
int TIFFRGBAImageGet(TIFFRGBAImage*, uint32_t*, uint32_t, uint32_t);
void TIFFRGBAImageEnd(TIFFRGBAImage*);