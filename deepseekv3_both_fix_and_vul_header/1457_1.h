#include <stdint.h>
#include <stdlib.h>

struct crx_data_header_t {
    int tileWidth;
    int tileHeight;
};

typedef struct CrxImage CrxImage;
typedef struct CrxTile CrxTile;
typedef struct CrxPlaneComp CrxPlaneComp;
typedef struct CrxSubband CrxSubband;

enum {
    E_HAS_TILES_ON_THE_RIGHT = 1,
    E_HAS_TILES_ON_THE_LEFT = 2,
    E_HAS_TILES_ON_THE_BOTTOM = 4,
    E_HAS_TILES_ON_THE_TOP = 8
};

struct CrxSubband {
    int supportsPartial;
    int quantValue;
    void *bandParam;
    uint32_t dataSize;
};

struct CrxPlaneComp {
    int compNumber;
    int supportsPartial;
    int tileFlag;
    CrxSubband *subBands;
    void *compBuf;
    void *waveletTransform;
    uint32_t compSize;
    uint32_t dataOffset;
    int roundedBitsMask;
};

struct CrxTile {
    int tileFlag;
    int tileNumber;
    uint32_t tileSize;
    uint32_t dataOffset;
    CrxPlaneComp *comps;
    int width;
    int height;
};

struct CrxImage {
    int tileRows;
    int tileCols;
    int nPlanes;
    int subbandCount;
    int planeWidth;
    int planeHeight;
    int levels;
    CrxTile *tiles;
#ifdef LIBRAW_CR3_MEMPOOL
    struct {
        void *calloc(size_t, size_t);
    } memmgr;
#endif
};

class LibRaw {
public:
    static uint32_t sgetn(int n, void *p);
};

int crxReadSubbandHeaders(crx_data_header_t *hdr, CrxImage *img, CrxTile *tile, CrxPlaneComp *comp, uint8_t **dataPtr, uint32_t *dataSize);