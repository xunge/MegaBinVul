#include <stdint.h>
#include <stdarg.h>
#include <inttypes.h>
#include <string.h>
#include <assert.h>

#define TIFF_ANY 0
#define FIELD_CUSTOM 0
#define TIFF_PERSAMPLE 0
#define EXTRASAMPLE_ASSOCALPHA 0
#define SAMPLEFORMAT_UINT 1
#define SAMPLEFORMAT_INT 2
#define SAMPLEFORMAT_IEEEFP 3
#define SAMPLEFORMAT_VOID 4
#define DATATYPE_UINT 1
#define DATATYPE_INT 2
#define DATATYPE_IEEEFP 3
#define DATATYPE_VOID 4
#define TIFF_VARIABLE -1
#define TIFF_VARIABLE2 -2
#define TIFF_SPP -3
#define TIFF_BYTE 1
#define TIFF_UNDEFINED 2
#define TIFF_SBYTE 3
#define TIFF_SHORT 4
#define TIFF_SSHORT 5
#define TIFF_LONG 6
#define TIFF_IFD 7
#define TIFF_SLONG 8
#define TIFF_LONG8 9
#define TIFF_IFD8 10
#define TIFF_SLONG8 11
#define TIFF_RATIONAL 12
#define TIFF_SRATIONAL 13
#define TIFF_FLOAT 14
#define TIFF_DOUBLE 15
#define TIFF_ASCII 16

#define TIFFTAG_SUBFILETYPE 254
#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_BITSPERSAMPLE 258
#define TIFFTAG_COMPRESSION 259
#define TIFFTAG_PHOTOMETRIC 262
#define TIFFTAG_THRESHHOLDING 263
#define TIFFTAG_FILLORDER 266
#define TIFFTAG_ORIENTATION 274
#define TIFFTAG_SAMPLESPERPIXEL 277
#define TIFFTAG_ROWSPERSTRIP 278
#define TIFFTAG_MINSAMPLEVALUE 280
#define TIFFTAG_MAXSAMPLEVALUE 281
#define TIFFTAG_SMINSAMPLEVALUE 340
#define TIFFTAG_SMAXSAMPLEVALUE 341
#define TIFFTAG_XRESOLUTION 282
#define TIFFTAG_YRESOLUTION 283
#define TIFFTAG_PLANARCONFIG 284
#define TIFFTAG_XPOSITION 286
#define TIFFTAG_YPOSITION 287
#define TIFFTAG_RESOLUTIONUNIT 296
#define TIFFTAG_PAGENUMBER 297
#define TIFFTAG_HALFTONEHINTS 321
#define TIFFTAG_COLORMAP 320
#define TIFFTAG_STRIPOFFSETS 273
#define TIFFTAG_TILEOFFSETS 324
#define TIFFTAG_STRIPBYTECOUNTS 279
#define TIFFTAG_TILEBYTECOUNTS 325
#define TIFFTAG_MATTEING 32995
#define TIFFTAG_EXTRASAMPLES 338
#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323
#define TIFFTAG_TILEDEPTH 32998
#define TIFFTAG_DATATYPE 32996
#define TIFFTAG_SAMPLEFORMAT 339
#define TIFFTAG_IMAGEDEPTH 32997
#define TIFFTAG_SUBIFD 330
#define TIFFTAG_YCBCRPOSITIONING 531
#define TIFFTAG_YCBCRSUBSAMPLING 530
#define TIFFTAG_TRANSFERFUNCTION 301
#define TIFFTAG_REFERENCEBLACKWHITE 532
#define TIFFTAG_INKNAMES 333
#define TIFFTAG_NUMBEROFINKS 334
#define TIFFTAG_DOTRANGE 336

typedef struct TIFF TIFF;
typedef struct TIFFDirectory TIFFDirectory;
typedef struct TIFFField TIFFField;
typedef struct TIFFTagValue TIFFTagValue;

struct TIFFDirectory {
    uint32_t td_subfiletype;
    uint32_t td_imagewidth;
    uint32_t td_imagelength;
    uint16_t td_bitspersample;
    uint16_t td_compression;
    uint16_t td_photometric;
    uint16_t td_threshholding;
    uint16_t td_fillorder;
    uint16_t td_orientation;
    uint16_t td_samplesperpixel;
    uint32_t td_rowsperstrip;
    uint16_t td_minsamplevalue;
    uint16_t td_maxsamplevalue;
    double* td_sminsamplevalue;
    double* td_smaxsamplevalue;
    float td_xresolution;
    float td_yresolution;
    uint16_t td_planarconfig;
    float td_xposition;
    float td_yposition;
    uint16_t td_resolutionunit;
    uint16_t td_pagenumber[2];
    uint16_t td_halftonehints[2];
    uint16_t* td_colormap[3];
    uint64_t* td_stripoffset_p;
    uint64_t* td_stripbytecount_p;
    uint16_t td_extrasamples;
    uint16_t* td_sampleinfo;
    uint32_t td_tilewidth;
    uint32_t td_tilelength;
    uint32_t td_tiledepth;
    uint16_t td_sampleformat;
    uint32_t td_imagedepth;
    uint16_t td_nsubifd;
    uint64_t* td_subifd;
    uint16_t td_ycbcrpositioning;
    uint16_t td_ycbcrsubsampling[2];
    uint16_t* td_transferfunction[3];
    float* td_refblackwhite;
    char* td_inknames;
    uint16_t td_numberofinks;
    int td_customValueCount;
    TIFFTagValue* td_customValues;
};

struct TIFF {
    TIFFDirectory tif_dir;
    const char* tif_name;
    void* tif_clientdata;
    uint32_t tif_flags;
};

struct TIFFField {
    uint32_t field_tag;
    const char* field_name;
    int field_bit;
    int field_passcount;
    int field_readcount;
    int field_type;
};

struct TIFFTagValue {
    const TIFFField* info;
    uint32_t count;
    void* value;
};

const TIFFField* TIFFFindField(TIFF* tif, uint32_t tag, int any);
void _TIFFFillStriles(TIFF* tif);
int TIFFFieldSetGetSize(const TIFFField* fip);
int isPseudoTag(uint32_t tag);
void TIFFErrorExt(void* clientdata, const char* module, const char* fmt, ...);
void TIFFWarningExt(void* clientdata, const char* module, const char* fmt, ...);