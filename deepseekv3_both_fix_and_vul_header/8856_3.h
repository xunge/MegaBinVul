#include <stdio.h>
#include <stdint.h>

typedef struct tiff TIFF;
typedef void (*copyFunc)(TIFF*, TIFF*, uint32_t, uint16_t);

extern uint16_t config;
extern int bias;
extern uint32_t rowsperstrip;
extern uint32_t tilewidth;
extern uint32_t tilelength;

#define TIFFTAG_PLANARCONFIG 284
#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_ROWSPERSTRIP 278
#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323

#define PLANARCONFIG_CONTIG 1
#define PLANARCONFIG_SEPARATE 2

extern int TIFFGetFieldDefaulted(TIFF*, int, ...);
extern int TIFFGetField(TIFF*, int, ...);
extern int TIFFIsTiled(TIFF*);
extern const char* TIFFFileName(TIFF*);

extern copyFunc cpContigStrips2ContigTiles;
extern copyFunc cpContigStrips2SeparateTiles;
extern copyFunc cpSeparateStrips2ContigTiles;
extern copyFunc cpSeparateStrips2SeparateTiles;
extern copyFunc cpContigTiles2ContigTiles;
extern copyFunc cpContigTiles2SeparateTiles;
extern copyFunc cpSeparateTiles2ContigTiles;
extern copyFunc cpSeparateTiles2SeparateTiles;
extern copyFunc cpContigTiles2ContigStrips;
extern copyFunc cpContigTiles2SeparateStrips;
extern copyFunc cpSeparateTiles2ContigStrips;
extern copyFunc cpSeparateTiles2SeparateStrips;
extern copyFunc cpBiasedContig2Contig;
extern copyFunc cpContig2ContigByRow;
extern copyFunc cpDecodedStrips;
extern copyFunc cpContig2SeparateByRow;
extern copyFunc cpSeparate2ContigByRow;
extern copyFunc cpSeparate2SeparateByRow;

typedef uint16_t uint16;
typedef uint32_t uint32;