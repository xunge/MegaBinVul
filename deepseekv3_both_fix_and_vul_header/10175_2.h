#include <stdint.h>

typedef struct TIFFDirectory {
    uint32_t td_nstrips;
    uint32_t td_rowsperstrip;
    uint32_t td_imagelength;
    uint16_t td_planarconfig;
    uint16_t td_samplesperpixel;
} TIFFDirectory;

typedef struct TIFF {
    TIFFDirectory tif_dir;
} TIFF;

#define PLANARCONFIG_SEPARATE 2

uint32_t TIFFhowmany_32(uint32_t a, uint32_t b);
uint32_t _TIFFMultiply32(TIFF* tif, uint32_t a, uint32_t b, const char* msg);

typedef uint32_t uint32;