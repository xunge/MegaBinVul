#include <stdint.h>

typedef int TIFF;
typedef unsigned char uint8;
typedef int32_t int32;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int tsize_t;

#define TIFFTAG_ROWSPERSTRIP 0
static int ignore;

uint16 TIFFNumberOfStrips(TIFF*);
uint32 TIFFStripSize(TIFF*);
uint32 TIFFGetFieldDefaulted(TIFF*, int, uint32*);
tsize_t TIFFScanlineSize(TIFF*);
void TIFFError(const char*, const char*, ...);
tsize_t TIFFReadEncodedStrip(TIFF*, uint16, void*, tsize_t);