#include <stdlib.h>
#include <stdint.h>

typedef struct CrxSubband CrxSubband;
typedef struct CrxPlaneComp CrxPlaneComp;
typedef struct CrxTile CrxTile;
typedef struct CrxImage CrxImage;

struct CrxSubband {
    // subband data fields
};

struct CrxPlaneComp {
    CrxSubband *subBands;
    // other component fields
};

struct CrxTile {
    CrxPlaneComp *comps;
    // other tile fields
};

struct CrxImage {
    CrxTile *tiles;
    void *planeBuf;
    int32_t tileRows;
    int32_t tileCols;
    int32_t nPlanes;
    // other image fields
};

void crxFreeSubbandData(CrxImage *img, CrxPlaneComp *comp);