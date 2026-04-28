#include <stdint.h>
#include <stdlib.h>

typedef unsigned short uint16;
typedef unsigned int uint32;
typedef int tsize_t;
typedef unsigned int ttile_t;
typedef void* tdata_t;
typedef unsigned int tstrip_t;

#define T2P_ERR_OK 0
#define T2P_ERR_ERROR 1
#define T2P_TRANSCODE_RAW 0
#define T2P_COMPRESS_JPEG 1
#define T2P_COMPRESS_G4 2
#define T2P_COMPRESS_ZIP 3
#define T2P_SAMPLE_NOTHING 0
#define T2P_SAMPLE_PLANAR_SEPARATE_TO_CONTIG 1
#define T2P_SAMPLE_RGBA_TO_RGB 2
#define T2P_SAMPLE_RGBAA_TO_RGB 4
#define T2P_SAMPLE_YCBCR_TO_RGB 8
#define T2P_SAMPLE_LAB_SIGNED_TO_UNSIGNED 16
#define T2P_COMPRESS_NONE 0
#define FILLORDER_LSB2MSB 0
#define FILLORDER_MSB2LSB 1
#define PLANARCONFIG_CONTIG 1
#define PHOTOMETRIC_YCBCR 6
#define COMPRESSION_NONE 1
#define COMPRESSION_JPEG 7
#define COMPRESSION_CCITTFAX4 4
#define COMPRESSION_DEFLATE 8
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
#define TIFFTAG_JPEGTABLESMODE 512
#define TIFFTAG_JPEGQUALITY 65537
#define TIFFTAG_PREDICTOR 317
#define TIFFTAG_ZIPQUALITY 65538
#define TIFFTAG_YCBCRSUBSAMPLING 530
#define TIFFTAG_REFERENCEBLACKWHITE 532
#define JPEGCOLORMODE_RGB 1
#define JPEGCOLORMODE_RAW 2

typedef struct {
    ttile_t tiles_tilewidth;
    ttile_t tiles_tilelength;
    ttile_t tiles_edgetilewidth;
    ttile_t tiles_edgetilelength;
} T2P_TileInfo;

typedef struct {
    uint16 t2p_error;
    ttile_t pdf_page;
    tsize_t tiff_datasize;
    uint16 tiff_fillorder;
    uint16 pdf_transcode;
    uint16 pdf_compression;
    uint16 tiff_compression;
    unsigned char* pdf_ojpegdata;
    tsize_t pdf_ojpegdatalength;
    uint16 pdf_sample;
    uint16 tiff_samplesperpixel;
    uint16 tiff_photometric;
    uint16 tiff_bitspersample;
    uint16 pdf_defaultcompressionquality;
    uint32 pdf_colorspace;
    tsize_t outputwritten;
    T2P_TileInfo tiff_tiles[];
} T2P;

typedef struct {
    char* filename;
} TIFF;

void* _TIFFmalloc(size_t size);
void _TIFFfree(void* ptr);
void _TIFFmemcpy(void* dest, const void* src, size_t n);
void TIFFError(const char* module, const char* fmt, ...);
char* TIFFFileName(TIFF* tif);
tsize_t TIFFReadEncodedTile(TIFF* tif, ttile_t tile, tdata_t buf, tsize_t size);
tsize_t TIFFTileSize(TIFF* tif);
ttile_t TIFFNumberOfTiles(TIFF* tif);
tsize_t TIFFTileRowSize(TIFF* tif);
void TIFFSetField(TIFF* tif, int tag, ...);
tsize_t TIFFWriteEncodedStrip(TIFF* tif, tstrip_t strip, tdata_t buf, tsize_t size);
tsize_t TIFFStripSize(TIFF* tif);
void t2p_disable(TIFF* tif);
void t2p_enable(TIFF* tif);
int t2p_tile_is_right_edge(T2P_TileInfo tileinfo, ttile_t tile);
int t2p_tile_is_bottom_edge(T2P_TileInfo tileinfo, ttile_t tile);
void t2p_tile_collapse_left(unsigned char* buffer, tsize_t rowsize, ttile_t tilewidth, ttile_t edgetilewidth, ttile_t tilelength);
tsize_t t2p_sample_planar_separate_to_contig(T2P* t2p, unsigned char* buffer, unsigned char* samplebuffer, tsize_t samplebufferoffset);
tsize_t t2p_sample_rgba_to_rgb(tdata_t buffer, tsize_t pixels);
tsize_t t2p_sample_rgbaa_to_rgb(tdata_t buffer, tsize_t pixels);
tsize_t t2p_sample_lab_signed_to_unsigned(tdata_t buffer, tsize_t pixels);