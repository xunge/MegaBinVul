#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_SAMPLES 16

/* TIFF tag definitions */
#define TIFFTAG_BITSPERSAMPLE   258
#define TIFFTAG_PLANARCONFIG    284
#define TIFFTAG_ROWSPERSTRIP    278

typedef struct tiff TIFF;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;
typedef int32_t int32;
typedef unsigned long tsize_t;
typedef unsigned short tsample_t;
typedef unsigned short tstrip_t;

struct dump_opts {
    FILE *infile;
    const char *format;
    int level;
};

extern int ignore;
extern tsize_t TIFFScanlineSize(TIFF*);
extern tsize_t TIFFStripSize(TIFF*);
extern void TIFFError(const char*, const char*, ...);
extern int TIFFGetField(TIFF*, int, ...);
extern int TIFFGetFieldDefaulted(TIFF*, int, ...);
extern tsize_t TIFFReadEncodedStrip(TIFF*, tstrip_t, void*, tsize_t);
extern tstrip_t TIFFNumberOfStrips(TIFF*);
extern const char* TIFFFileName(TIFF*);
extern void* _TIFFmalloc(tsize_t);
extern void _TIFFfree(void*);
extern void dump_info(FILE*, const char*, const char*, const char*, ...);
extern int combineSeparateSamplesBytes(unsigned char**, unsigned char*, uint32, uint32, uint16, uint16, FILE*, const char*, int);
extern int combineSeparateSamples8bits(unsigned char**, unsigned char*, uint32, uint32, uint16, uint16, FILE*, const char*, int);
extern int combineSeparateSamples16bits(unsigned char**, unsigned char*, uint32, uint32, uint16, uint16, FILE*, const char*, int);
extern int combineSeparateSamples24bits(unsigned char**, unsigned char*, uint32, uint32, uint16, uint16, FILE*, const char*, int);
extern int combineSeparateSamples32bits(unsigned char**, unsigned char*, uint32, uint32, uint16, uint16, FILE*, const char*, int);