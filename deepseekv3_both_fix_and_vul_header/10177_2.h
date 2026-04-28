#include <stdint.h>

typedef struct tiff TIFF;
typedef unsigned char uint8;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int tsize_t;

#define TIFFTAG_ROWSPERSTRIP 278

extern uint32 TIFFNumberOfStrips(TIFF*);
extern uint32 TIFFStripSize(TIFF*);
extern uint32 TIFFGetFieldDefaulted(TIFF*, int, uint32*);
extern tsize_t TIFFScanlineSize(TIFF*);
extern tsize_t TIFFReadEncodedStrip(TIFF*, uint32, void*, tsize_t);
extern void TIFFError(const char*, const char*, ...);

static int ignore = 0;