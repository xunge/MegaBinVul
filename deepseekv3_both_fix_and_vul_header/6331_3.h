#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct tiff TIFF;
typedef int (*copyFunc)(TIFF*, TIFF*, uint32_t, uint32_t, uint16_t);

struct cpTag {
    uint32_t tag;
    uint16_t count;
    uint16_t type;
};

#define PHOTOMETRIC_MINISBLACK 0
#define PHOTOMETRIC_RGB 2
#define PHOTOMETRIC_YCBCR 6
#define PHOTOMETRIC_LOGL 32844
#define PHOTOMETRIC_LOGLUV 32845

#define COMPRESSION_NONE 1
#define COMPRESSION_JPEG 7
#define COMPRESSION_LZW 5
#define COMPRESSION_ADOBE_DEFLATE 8
#define COMPRESSION_DEFLATE 32946
#define COMPRESSION_LZMA 34925
#define COMPRESSION_ZSTD 50000
#define COMPRESSION_WEBP 50001
#define COMPRESSION_CCITTFAX3 3
#define COMPRESSION_CCITTFAX4 4
#define COMPRESSION_SGILOG 34676
#define COMPRESSION_SGILOG24 34677
#define COMPRESSION_JBIG 34661

#define JPEGCOLORMODE_RGB 1

#define ORIENTATION_TOPLEFT 1
#define ORIENTATION_TOPRIGHT 2
#define ORIENTATION_BOTRIGHT 3
#define ORIENTATION_BOTLEFT 4
#define ORIENTATION_LEFTTOP 5
#define ORIENTATION_RIGHTTOP 6
#define ORIENTATION_RIGHTBOT 7
#define ORIENTATION_LEFTBOT 8

#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_BITSPERSAMPLE 258
#define TIFFTAG_SAMPLESPERPIXEL 277
#define TIFFTAG_COMPRESSION 259
#define TIFFTAG_PHOTOMETRIC 262
#define TIFFTAG_FILLORDER 266
#define TIFFTAG_ORIENTATION 274
#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323
#define TIFFTAG_ROWSPERSTRIP 278
#define TIFFTAG_PLANARCONFIG 284
#define TIFFTAG_TRANSFERFUNCTION 301
#define TIFFTAG_COLORMAP 320
#define TIFFTAG_JPEGQUALITY 65537
#define TIFFTAG_JPEGCOLORMODE 65538
#define TIFFTAG_FAXRECVPARAMS 34910
#define TIFFTAG_FAXRECVTIME 34911
#define TIFFTAG_FAXSUBADDRESS 34912
#define TIFFTAG_FAXDCS 34913
#define TIFFTAG_PREDICTOR 317
#define TIFFTAG_ZIPQUALITY 65539
#define TIFFTAG_LZMAPRESET 65540
#define TIFFTAG_ZSTD_LEVEL 65541
#define TIFFTAG_WEBP_LOSSLESS 65542
#define TIFFTAG_WEBP_LEVEL 65543
#define TIFFTAG_GROUP3OPTIONS 292
#define TIFFTAG_GROUP4OPTIONS 293
#define TIFFTAG_BADFAXLINES 326
#define TIFFTAG_CLEANFAXDATA 327
#define TIFFTAG_CONSECUTIVEBADFAXLINES 328
#define TIFFTAG_ICCPROFILE 34675
#define TIFFTAG_NUMBEROFINKS 334
#define TIFFTAG_INKNAMES 333
#define TIFFTAG_PAGENUMBER 297
#define TIFFTAG_YCBCRSUBSAMPLING 530

#define TIFF_SHORT 3
#define TIFF_LONG 4
#define TIFF_ASCII 2

#define FALSE 0
#define TRUE 1

extern uint16_t compression;
extern uint16_t fillorder;
extern uint16_t predictor;
extern uint16_t config;
extern uint16_t orientation;
extern uint16_t jpegcolormode;
extern uint16_t quality;
extern uint32_t g3opts;
extern uint32_t tilewidth;
extern uint32_t tilelength;
extern uint32_t rowsperstrip;
extern int outtiled;
extern int preset;
extern int pageInSeq;
extern int pageNum;
extern struct cpTag tags[];
extern int NTAGS;

int TIFFGetField(TIFF*, uint32_t, ...);
void TIFFWarning(const char*, const char*);
void TIFFSetField(TIFF*, uint32_t, ...);
void TIFFGetFieldDefaulted(TIFF*, uint32_t, ...);
int TIFFIsTiled(TIFF*);
void TIFFDefaultTileSize(TIFF*, uint32_t*, uint32_t*);
uint32_t TIFFDefaultStripSize(TIFF*, uint32_t);
const char* TIFFFileName(TIFF*);
void CopyField(uint32_t, uint32_t);
void CopyTag(uint32_t, uint16_t, uint16_t);
copyFunc pickCopyFunc(TIFF*, TIFF*, uint16_t, uint16_t);

#define uint16 uint16_t
#define uint32 uint32_t