#include <stdint.h>
#include <stdio.h>

#define T2P_TRANSCODE_RAW 1
#define T2P_COMPRESS_G4 1
#define T2P_COMPRESS_ZIP 1
#define T2P_COMPRESS_JPEG 1
#define COMPRESSION_OJPEG 1
#define COMPRESSION_JPEG 1
#define PHOTOMETRIC_YCBCR 1
#define PLANARCONFIG_SEPARATE 1
#define CCITT_SUPPORT 1
#define ZIP_SUPPORT 1
#define JPEG_SUPPORT 1
#define OJPEG_SUPPORT 1

#define TIFF2PDF_MODULE "tiff2pdf"

typedef uint32_t tstrip_t;
typedef int32_t tmsize_t;
typedef uint32_t tsize_t;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint64_t uint64;

typedef enum {
    T2P_ERR_ERROR = 1
} T2P_ERR;

typedef struct {
    int pdf_transcode;
    int pdf_compression;
    int tiff_compression;
    int tiff_photometric;
    int tiff_planar;
    uint16 tiff_samplesperpixel;
    uint32 tiff_length;
    tsize_t tiff_datasize;
    uint64 tiff_dataoffset;
    int pdf_ojpegiflength;
    T2P_ERR t2p_error;
} T2P;

typedef struct {
    char* name;
} TIFF;

uint64 checkAdd64(uint64 a, uint64 b, T2P* t2p);
uint64 checkMultiply64(uint64 a, uint64 b, T2P* t2p);

#define TIFFGetField(tif, tag, ...) 0
#define TIFFNumberOfStrips(tif) 0
#define TIFFStripSize(tif) 0
#define TIFFScanlineSize(tif) 0
#define TIFFFileName(tif) ""
#define TIFFError(module, ...) fprintf(stderr, "Error: " __VA_ARGS__)
#define TIFFWarning(module, ...) fprintf(stderr, "Warning: " __VA_ARGS__)

#define TIFFTAG_STRIPBYTECOUNTS 0
#define TIFFTAG_JPEGIFOFFSET 0
#define TIFFTAG_JPEGIFBYTECOUNT 0
#define TIFFTAG_JPEGTABLES 0