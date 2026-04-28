#include <stdint.h>
#include <string.h>

#define BOOL int
#define FALSE 0
#define TRUE 1

#define PLANAR_ALIGN(_val, _align) (((_val) + ((_align) - 1)) & ~((_align) - 1))

typedef uint32_t UINT32;
typedef uint8_t BYTE;

typedef struct
{
    BOOL bgr;
    UINT32 maxWidth;
    UINT32 maxHeight;
    UINT32 maxPlaneSize;
    UINT32 nTempStep;
    BYTE* planes[4];
    BYTE* rlePlanes[4];
    BYTE* deltaPlanes[4];
    BYTE* planesBuffer;
    BYTE* pTempData;
    BYTE* deltaPlanesBuffer;
    BYTE* rlePlanesBuffer;
} BITMAP_PLANAR_CONTEXT;

void* winpr_aligned_recalloc(void* ptr, size_t size, size_t count, size_t alignment);