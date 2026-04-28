#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct tiff TIFF;
typedef uint16_t uint16;
typedef uint32_t uint32;

#define PHOTOMETRIC_MINISBLACK 0
#define PHOTOMETRIC_RGB 2
#define PHOTOMETRIC_YCBCR 6
#define PHOTOMETRIC_LOGL 32844
#define PHOTOMETRIC_LOGLUV 32845

#define COMPRESSION_NONE 1
#define COMPRESSION_JPEG 7
#define COMPRESSION_SGILOG 34676
#define COMPRESSION_SGILOG24 34677
#define COMPRESSION_JBIG 9
#define COMPRESSION_LZW 5
#define COMPRESSION_ADOBE_DEFLATE 8
#define COMPRESSION_DEFLATE 32946
#define COMPRESSION_LZMA 34925
#define COMPRESSION_CCITTFAX3 3
#define COMPRESSION_CCITTFAX4 4

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
#define TIFFTAG_JPEGCOLORMODE 65538
#define TIFFTAG_YCBCRSUBSAMPLING 530
#define TIFFTAG_FILLORDER 266
#define TIFFTAG_ORIENTATION 274
#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323
#define TIFFTAG_ROWSPERSTRIP 278
#define TIFFTAG_PLANARCONFIG 284
#define TIFFTAG_TRANSFERFUNCTION 301
#define TIFFTAG_COLORMAP 320
#define TIFFTAG_JPEGQUALITY 65537
#define TIFFTAG_GROUP3OPTIONS 292
#define TIFFTAG_GROUP4OPTIONS 293
#define TIFFTAG_BADFAXLINES 326
#define TIFFTAG_CLEANFAXDATA 327
#define TIFFTAG_CONSECUTIVEBADFAXLINES 328
#define TIFFTAG_FAXRECVPARAMS 329
#define TIFFTAG_FAXRECVTIME 330
#define TIFFTAG_FAXSUBADDRESS 331
#define TIFFTAG_FAXDCS 332
#define TIFFTAG_PREDICTOR 317
#define TIFFTAG_ZIPQUALITY 65539
#define TIFFTAG_LZMAPRESET 65540
#define TIFFTAG_ICCPROFILE 34675
#define TIFFTAG_NUMBEROFINKS 334
#define TIFFTAG_INKNAMES 333
#define TIFFTAG_PAGENUMBER 297

#define TIFF_SHORT 3
#define TIFF_LONG 4
#define TIFF_ASCII 2

#define FALSE 0
#define TRUE 1

typedef int (*copyFunc)(TIFF*, TIFF*, uint32, uint32, uint16);

struct cpTag {
    int tag;
    int count;
    int type;
};

extern uint16 compression;
extern uint16 fillorder;
extern uint16 orientation;
extern int outtiled;
extern uint32 tilewidth;
extern uint32 tilelength;
extern uint32 rowsperstrip;
extern uint16 config;
extern uint16 predictor;
extern int preset;
extern uint32 g3opts;
extern int quality;
extern int jpegcolormode;
extern int pageInSeq;
extern int pageNum;
extern struct cpTag tags[];
extern int NTAGS;

#define CopyField(tag, v) 
#define CopyTag(tag, count, type)