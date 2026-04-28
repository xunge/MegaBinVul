#include <stdint.h>
#include <stdlib.h>

typedef struct crx_data_header_t {
    int f_width;
    int f_height;
    int tileWidth;
    int tileHeight;
    int imageLevels;
    int nPlanes;
    int nBits;
    int encType;
    uint64_t mdatHdrSize;
    int cfaLayout;
} crx_data_header_t;

typedef struct CrxImage {
    int planeWidth;
    int planeHeight;
    int tileCols;
    int tileRows;
    int tiles;
    int levels;
    int subbandCount;
    int nPlanes;
    int nBits;
    int encType;
    int samplePrecision;
    uint64_t mdatOffset;
    uint32_t mdatSize;
    int16_t *planeBuf;
    int16_t *outBufs[4];
} CrxImage;