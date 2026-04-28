#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <assert.h>

#define FILETYPE_REDUCEDIMAGE 0x1
#define FILETYPE_PAGE 0x2
#define FILETYPE_MASK 0x4

#define RESUNIT_NONE 1
#define RESUNIT_INCH 2
#define RESUNIT_CENTIMETER 3

#define SAMPLEFORMAT_VOID 0
#define SAMPLEFORMAT_INT 1
#define SAMPLEFORMAT_UINT 2
#define SAMPLEFORMAT_IEEEFP 3
#define SAMPLEFORMAT_COMPLEXINT 4
#define SAMPLEFORMAT_COMPLEXIEEEFP 5

#define PHOTOMETRIC_LOGL 32844
#define PHOTOMETRIC_LOGLUV 32845

#define EXTRASAMPLE_UNSPECIFIED 0
#define EXTRASAMPLE_ASSOCALPHA 1
#define EXTRASAMPLE_UNASSALPHA 2

#define THRESHHOLD_BILEVEL 1
#define THRESHHOLD_HALFTONE 2
#define THRESHHOLD_ERRORDIFFUSE 3

#define FILLORDER_MSB2LSB 1
#define FILLORDER_LSB2MSB 2

#define YCBCRPOSITION_CENTERED 1
#define YCBCRPOSITION_COSITED 2

#define PLANARCONFIG_CONTIG 1
#define PLANARCONFIG_SEPARATE 2

#define TIFFPRINT_COLORMAP 0x1
#define TIFFPRINT_CURVES 0x2
#define TIFFPRINT_STRIPS 0x4

#define FIELD_SUBFILETYPE 1
#define FIELD_IMAGEDIMENSIONS 2
#define FIELD_IMAGEDEPTH 3
#define FIELD_TILEDIMENSIONS 4
#define FIELD_TILEDEPTH 5
#define FIELD_RESOLUTION 6
#define FIELD_RESOLUTIONUNIT 7
#define FIELD_POSITION 8
#define FIELD_BITSPERSAMPLE 9
#define FIELD_SAMPLEFORMAT 10
#define FIELD_COMPRESSION 11
#define FIELD_PHOTOMETRIC 12
#define FIELD_EXTRASAMPLES 13
#define FIELD_INKNAMES 14
#define FIELD_THRESHHOLDING 15
#define FIELD_FILLORDER 16
#define FIELD_YCBCRSUBSAMPLING 17
#define FIELD_YCBCRPOSITIONING 18
#define FIELD_HALFTONEHINTS 19
#define FIELD_ORIENTATION 20
#define FIELD_SAMPLESPERPIXEL 21
#define FIELD_ROWSPERSTRIP 22
#define FIELD_MINSAMPLEVALUE 23
#define FIELD_MAXSAMPLEVALUE 24
#define FIELD_SMINSAMPLEVALUE 25
#define FIELD_SMAXSAMPLEVALUE 26
#define FIELD_PLANARCONFIG 27
#define FIELD_PAGENUMBER 28
#define FIELD_COLORMAP 29
#define FIELD_REFBLACKWHITE 30
#define FIELD_TRANSFERFUNCTION 31
#define FIELD_SUBIFD 32
#define FIELD_STRIPOFFSETS 33
#define FIELD_NUMBEROFINKS 34

#define TIFF_PERSAMPLE 0x0100
#define TIFF_VARIABLE 1
#define TIFF_VARIABLE2 2
#define TIFF_SPP 3
#define TIFF_ASCII 2
#define TIFFTAG_DOTRANGE 0x150

typedef struct {
    uint32_t td_subfiletype;
    uint32_t td_imagewidth;
    uint32_t td_imagelength;
    uint32_t td_imagedepth;
    uint32_t td_tilewidth;
    uint32_t td_tilelength;
    uint32_t td_tiledepth;
    float td_xresolution;
    float td_yresolution;
    uint16_t td_resolutionunit;
    float td_xposition;
    float td_yposition;
    uint16_t td_bitspersample;
    uint16_t td_sampleformat;
    uint16_t td_compression;
    uint16_t td_photometric;
    uint16_t td_extrasamples;
    uint16_t* td_sampleinfo;
    char* td_inknames;
    uint32_t td_inknameslen;
    uint16_t td_threshholding;
    uint16_t td_fillorder;
    uint16_t td_ycbcrsubsampling[2];
    uint16_t td_ycbcrpositioning;
    uint16_t td_halftonehints[2];
    uint16_t td_orientation;
    uint16_t td_samplesperpixel;
    uint32_t td_rowsperstrip;
    uint16_t td_minsamplevalue;
    uint16_t td_maxsamplevalue;
    float* td_sminsamplevalue;
    float* td_smaxsamplevalue;
    uint16_t td_planarconfig;
    uint16_t td_pagenumber[2];
    uint16_t* td_colormap[3];
    float* td_refblackwhite;
    uint16_t* td_transferfunction[3];
    uint64_t* td_subifd;
    uint16_t td_nsubifd;
    uint32_t td_nstrips;
    uint16_t td_numberofinks;
} TIFFDirectory;

typedef struct {
    TIFFDirectory tif_dir;
    uint64_t tif_diroff;
    uint32_t tif_flags;
    struct {
        void (*printdir)(void*, FILE*, long);
    } tif_tagmethods;
    int (*tif_tagmethods_printdir)(void*, FILE*, long);
} TIFF;

typedef struct {
    const char* name;
} TIFFCodec;

typedef struct {
    uint32_t field_tag;
    const char* field_name;
    int field_passcount;
    int field_readcount;
    int field_type;
} TIFFField;

extern int TIFFFieldSet(TIFF*, int);
extern const TIFFCodec* TIFFFindCODEC(uint16_t);
extern short TIFFGetTagListCount(TIFF*);
extern uint32_t TIFFGetTagListEntry(TIFF*, int);
extern const TIFFField* TIFFFieldWithTag(TIFF*, uint32_t);
extern int TIFFGetField(TIFF*, uint32_t, ...);
extern int _TIFFPrettyPrintField(TIFF*, const TIFFField*, FILE*, uint32_t, uint32_t, void*);
extern void _TIFFPrintField(FILE*, const TIFFField*, uint32_t, void*);
extern void* _TIFFmalloc(size_t);
extern void _TIFFfree(void*);
extern int isTiled(TIFF*);
extern uint64_t TIFFGetStrileOffset(TIFF*, uint32_t);
extern uint64_t TIFFGetStrileByteCount(TIFF*, uint32_t);
extern void _TIFFprintAsciiBounded(FILE*, const char*, size_t);
extern int TIFFFieldSetGetSize(const TIFFField*);

static const char* photoNames[] = {
    "min-is-white",
    "min-is-black",
    "RGB",
    "palette",
    "mask",
    "separated",
    "YCbCr",
    "CIELab",
    "ICCLab",
    "ITULab",
    "CFA",
    "LinearRaw"
};

static const char* orientNames[] = {
    "top-left",
    "top-right",
    "bottom-right",
    "bottom-left",
    "left-top",
    "right-top",
    "right-bottom",
    "left-bottom"
};

#define NPHOTONAMES (sizeof(photoNames)/sizeof(photoNames[0]))
#define NORIENTNAMES (sizeof(orientNames)/sizeof(orientNames[0]))