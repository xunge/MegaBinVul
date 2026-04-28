#include <stdint.h>
#include <stdio.h>

typedef unsigned int tstrip_t;
typedef int tmsize_t;
typedef unsigned int tsize_t;
typedef unsigned int uint32;
typedef uint64_t uint64;

typedef struct {
    int pdf_transcode;
    int pdf_compression;
    int tiff_compression;
    int tiff_planar;
    int tiff_samplesperpixel;
    uint64 tiff_length;
    tsize_t tiff_datasize;
    uint64 tiff_dataoffset;
    int t2p_error;
    int pdf_ojpegiflength;
} T2P;

typedef struct {
    char* filename;
} TIFF;

#define T2P_TRANSCODE_RAW 0
#define T2P_COMPRESS_G4 0
#define T2P_COMPRESS_ZIP 0
#define COMPRESSION_OJPEG 0
#define COMPRESSION_JPEG 0
#define PLANARCONFIG_SEPARATE 0
#define T2P_ERR_ERROR 0
#define TIFF2PDF_MODULE ""
#define TIFFTAG_STRIPBYTECOUNTS 0
#define TIFFTAG_JPEGIFOFFSET 0
#define TIFFTAG_JPEGIFBYTECOUNT 0
#define TIFFTAG_JPEGTABLES 0

uint64 checkAdd64(uint64 a, uint64 b, T2P* t2p);
uint64 checkMultiply64(uint64 a, uint64 b, T2P* t2p);

int TIFFGetField(TIFF* tif, int tag, ...);
tstrip_t TIFFNumberOfStrips(TIFF* tif);
tmsize_t TIFFScanlineSize(TIFF* tif);
char* TIFFFileName(TIFF* tif);
void TIFFError(const char* module, const char* fmt, ...);
void TIFFWarning(const char* module, const char* fmt, ...);