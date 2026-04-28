#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define PLANAR_ALIGN(_val, _align) (((_val) + ((_align) - 1)) & ~((_align) - 1))
#define FALSE false
#define TRUE true

typedef bool BOOL;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef uint8_t BYTE;

typedef struct
{
    BOOL bgr;
    UINT32 maxWidth;
    UINT32 maxHeight;
    UINT32 maxPlaneSize;
    UINT32 nTempStep;
    BYTE* planesBuffer;
    BYTE* pTempData;
    BYTE* deltaPlanesBuffer;
    BYTE* rlePlanesBuffer;
    BYTE* planes[4];
    BYTE* deltaPlanes[4];
} BITMAP_PLANAR_CONTEXT;