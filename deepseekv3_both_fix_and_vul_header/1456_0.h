#include <stdint.h>
#include <stdlib.h>

typedef struct CrxImage CrxImage;
typedef struct CrxPlaneComp CrxPlaneComp;
typedef struct CrxTile CrxTile;
typedef struct CrxSubband CrxSubband;
typedef struct CrxWaveletTransform CrxWaveletTransform;

struct CrxSubband {
    int32_t width;
    int32_t height;
    uint32_t dataSize;
    uint32_t dataOffset;
    uint32_t bandSize;
    uint8_t *bandBuf;
    uint64_t mdatOffset;
    void *bandParam;
};

struct CrxWaveletTransform {
    int32_t width;
    int32_t height;
    int32_t *lineBuf[8];
    int32_t *subband0Buf;
    int32_t *subband1Buf;
    int32_t *subband2Buf;
    int32_t *subband3Buf;
    int32_t curLine;
    int32_t curH;
    int32_t fltTapH;
};

struct CrxPlaneComp {
    CrxSubband *subBands;
    uint8_t *compBuf;
    CrxWaveletTransform *waveletTransform;
    int supportsPartial;
    uint32_t roundedBitsMask;
};

struct CrxTile {
    int32_t width;
    int32_t height;
};

struct CrxImage {
    uint64_t mdatOffset;
    int levels;
    void *input;
};

int crxParamInit(void *bandParam, uint64_t mdatOffset, uint32_t dataSize, int32_t width, int32_t height, int supportsPartial, uint32_t roundedBitsMask, void *input);