#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef size_t tsize_t;
typedef uint32_t tstrip_t;
typedef uint64_t toff_t;
typedef void* tdata_t;

#define T2P_TRANSCODE_RAW 1
#define T2P_COMPRESS_G4 1
#define T2P_COMPRESS_ZIP 2
#define T2P_COMPRESS_JPEG 3
#define T2P_COMPRESS_NONE 0
#define T2P_ERR_OK 0
#define T2P_ERR_ERROR 1
#define FILLORDER_LSB2MSB 1
#define FILLORDER_MSB2LSB 2
#define COMPRESSION_OJPEG 6
#define COMPRESSION_JPEG 7
#define COMPRESSION_CCITTFAX4 4
#define COMPRESSION_DEFLATE 8
#define COMPRESSION_NONE 1
#define PHOTOMETRIC_YCBCR 6
#define PHOTOMETRIC_RGB 2
#define PHOTOMETRIC_GRAY 1
#define PHOTOMETRIC_CMYK 5
#define PHOTOMETRIC_LAB 8
#define PLANARCONFIG_CONTIG 1
#define ORIENTATION_TOPLEFT 1
#define T2P_SAMPLE_NOTHING 0
#define T2P_SAMPLE_PLANAR_SEPARATE_TO_CONTIG 1
#define T2P_SAMPLE_REALIZE_PALETTE 2
#define T2P_SAMPLE_RGBA_TO_RGB 4
#define T2P_SAMPLE_RGBAA_TO_RGB 8
#define T2P_SAMPLE_YCBCR_TO_RGB 16
#define T2P_SAMPLE_LAB_SIGNED_TO_UNSIGNED 32
#define T2P_CS_RGB 1
#define T2P_CS_GRAY 2
#define T2P_CS_CMYK 4
#define T2P_CS_LAB 8
#define TIFF2PDF_MODULE "tiff2pdf"

#define TIFFTAG_PHOTOMETRIC 262
#define TIFFTAG_BITSPERSAMPLE 258
#define TIFFTAG_SAMPLESPERPIXEL 277
#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_ROWSPERSTRIP 278
#define TIFFTAG_PLANARCONFIG 284
#define TIFFTAG_FILLORDER 266
#define TIFFTAG_COMPRESSION 259
#define TIFFTAG_YCBCRSUBSAMPLING 530
#define TIFFTAG_REFERENCEBLACKWHITE 532
#define TIFFTAG_JPEGTABLESMODE 512
#define TIFFTAG_JPEGQUALITY 512
#define TIFFTAG_PREDICTOR 317
#define TIFFTAG_ZIPQUALITY 512
#define TIFFTAG_JPEGTABLES 347
#define TIFFTAG_STRIPBYTECOUNTS 279

typedef struct {
    int t2p_error;
    size_t tiff_datasize;
    int pdf_transcode;
    int pdf_compression;
    int tiff_fillorder;
    int tiff_compression;
    toff_t tiff_dataoffset;
    size_t pdf_ojpegiflength;
    unsigned char* pdf_ojpegdata;
    size_t pdf_ojpegdatalength;
    int pdf_sample;
    int tiff_samplesperpixel;
    uint32_t tiff_width;
    uint32_t tiff_length;
    int tiff_photometric;
    int tiff_bitspersample;
    int pdf_colorspace;
    int pdf_defaultcompressionquality;
    size_t outputwritten;
} T2P;

typedef struct {
    char* name;
} TIFF;

typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint64_t uint64;

void* _TIFFmalloc(size_t size);
void _TIFFfree(void* ptr);
void* _TIFFrealloc(void* ptr, size_t size);
void _TIFFmemcpy(void* dest, const void* src, size_t n);

void TIFFError(const char* module, const char* fmt, ...);
const char* TIFFFileName(TIFF* tif);
tsize_t TIFFStripSize(TIFF* tif);
tstrip_t TIFFNumberOfStrips(TIFF* tif);
tsize_t TIFFReadEncodedStrip(TIFF* tif, tstrip_t strip, tdata_t buf, tsize_t size);
tsize_t TIFFmin(tsize_t a, tsize_t b);
void t2p_sample_planar_separate_to_contig(T2P* t2p, unsigned char* buffer, unsigned char* samplebuffer, tsize_t samplebufferoffset);
void t2p_sample_realize_palette(T2P* t2p, unsigned char* buffer);
tsize_t t2p_sample_rgba_to_rgb(tdata_t buffer, uint32_t count);
tsize_t t2p_sample_rgbaa_to_rgb(tdata_t buffer, uint32_t count);
int TIFFReadRGBAImageOriented(TIFF* tif, uint32_t width, uint32_t length, uint32_t* raster, int orientation, int stop);
tsize_t t2p_sample_abgr_to_rgb(tdata_t buffer, uint32_t count);
tsize_t t2p_sample_lab_signed_to_unsigned(tdata_t buffer, uint32_t count);
void t2p_disable(TIFF* tif);
int TIFFSetField(TIFF* tif, uint32_t tag, ...);
void t2p_enable(TIFF* tif);
tsize_t TIFFWriteEncodedStrip(TIFF* tif, tstrip_t strip, tdata_t data, tsize_t cc);