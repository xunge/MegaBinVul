#include <stdint.h>

typedef int32_t tmsize_t;
typedef uint32_t uint32;
typedef uint16_t uint16;

typedef struct TIFF TIFF;
typedef struct TIFFDirectory TIFFDirectory;

struct TIFFDirectory {
    uint32 td_nstrips;
    uint32 td_rowsperstrip;
    uint32 td_imagelength;
    uint16 td_compression;
    uint16 td_fillorder;
};

struct TIFF {
    TIFFDirectory tif_dir;
    void* tif_clientdata;
    uint32 tif_flags;
    int (*tif_decodestrip)(TIFF*, void*, tmsize_t, uint16);
    void (*tif_postdecode)(TIFF*, void*, tmsize_t);
};

#define COMPRESSION_NONE 1
#define TIFF_NOREADRAW 0x0001
#define TIFF_NOBITREV 0x0002

int TIFFCheckRead(TIFF*, int);
void TIFFErrorExt(void*, const char*, const char*, ...);
tmsize_t TIFFVStripSize(TIFF*, uint32);
int isMapped(TIFF*);
tmsize_t TIFFReadRawStrip1(TIFF*, uint32, void*, tmsize_t, const char*);
int isFillOrder(TIFF*, uint16);
void TIFFReverseBits(void*, tmsize_t);
int TIFFFillStrip(TIFF*, uint32);