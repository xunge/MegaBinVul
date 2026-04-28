#include <stdint.h>

typedef struct {
    int tif_rawcc;
    int tif_flags;
    struct {
        int td_fillorder;
    } tif_dir;
    uint8_t* tif_rawdata;
    uint8_t* tif_rawcp;
    int tif_curtile;
    int tif_curstrip;
} TIFF;

#define TIFF_BUF4WRITE 1
#define TIFF_NOBITREV 2

int isFillOrder(TIFF* tif, int order);
int isTiled(TIFF* tif);
void TIFFReverseBits(uint8_t* data, int count);
int TIFFAppendToStrip(TIFF* tif, int strip, uint8_t* data, int count);

typedef uint8_t uint8;