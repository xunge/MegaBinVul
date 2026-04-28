#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define STRIP_SIZE_DEFAULT 8192
#define PLANARCONFIG_CONTIG 1
#define PHOTOMETRIC_YCBCR 6
#define TIFFTAG_ROWSPERSTRIP 278

typedef struct {
    uint32_t td_planarconfig;
    uint32_t td_photometric;
    uint32_t td_ycbcrsubsampling[2];
    uint32_t td_rowsperstrip;
    uint32_t td_imagelength;
    uint32_t td_nstrips;
    uint32_t td_stripsperimage;
    uint64_t* td_stripbytecount;
    uint64_t* td_stripoffset;
    int td_stripbytecountsorted;
} TIFFDirectory;

typedef struct {
    TIFFDirectory tif_dir;
} TIFF;

extern int isUpSampled(TIFF*);
extern uint64_t TIFFVTileSize64(TIFF*, uint32_t);
extern uint32_t TIFFhowmany_32(uint32_t, uint32_t);
extern void* _TIFFCheckMalloc(TIFF*, uint32_t, size_t, const char*);
extern void _TIFFfree(void*);
extern void TIFFSetField(TIFF*, int, uint32_t);

#define uint32 uint32_t
#define uint64 uint64_t