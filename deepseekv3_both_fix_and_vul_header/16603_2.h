#include <stdint.h>
#include <stdio.h>

#define T2P_TRANSCODE_RAW 0
#define T2P_COMPRESS_G4 0
#define T2P_COMPRESS_ZIP 0
#define T2P_COMPRESS_JPEG 0
#define T2P_ERR_ERROR 0
#define COMPRESSION_OJPEG 0
#define COMPRESSION_JPEG 0
#define PHOTOMETRIC_YCBCR 0
#define PLANARCONFIG_SEPARATE 0
#define TIFF2PDF_MODULE ""
#define JPEG_SUPPORT 0
#define OJPEG_SUPPORT 0
#define CCITT_SUPPORT 0
#define ZIP_SUPPORT 0

#define TIFFTAG_STRIPBYTECOUNTS 0
#define TIFFTAG_JPEGIFOFFSET 0
#define TIFFTAG_JPEGIFBYTECOUNT 0
#define TIFFTAG_JPEGTABLES 0

typedef uint32_t tstrip_t;
typedef uint32_t tsize_t;
typedef int64_t tmsize_t;
typedef uint64_t uint64;
typedef uint32_t uint32;

typedef struct {
    int pdf_transcode;
    int pdf_compression;
    int tiff_compression;
    int tiff_photometric;
    int tiff_planar;
    uint16_t tiff_samplesperpixel;
    uint32_t tiff_length;
    tsize_t tiff_datasize;
    uint64_t tiff_dataoffset;
    int t2p_error;
    int pdf_ojpegiflength;
} T2P;

typedef struct {
    char* filename;
} TIFF;

uint64_t checkAdd64(uint64_t a, uint64_t b, T2P* t2p);
uint64_t checkMultiply64(uint64_t a, uint64_t b, T2P* t2p);
void TIFFError(const char* module, const char* fmt, ...);
void TIFFWarning(const char* module, const char* fmt, ...);
char* TIFFFileName(TIFF* tif);
int TIFFGetField(TIFF* tif, int tag, ...);
tstrip_t TIFFNumberOfStrips(TIFF* tif);
tsize_t TIFFStripSize(TIFF* tif);
tsize_t TIFFScanlineSize(TIFF* tif);