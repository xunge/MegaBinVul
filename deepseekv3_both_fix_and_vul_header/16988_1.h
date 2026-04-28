#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define WINPR_ASSERT(expr)
#define WINPR_UNUSED(x) (void)(x)
#define WLog_ERR(tag, fmt, ...)
#define TAG ""
#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)

typedef uint8_t BYTE;
typedef uint32_t UINT32;
typedef int32_t INT32;
typedef bool BOOL;

#define PLANAR_FORMAT_HEADER_CLL_MASK 0x03
#define PLANAR_FORMAT_HEADER_CS 0x04
#define PLANAR_FORMAT_HEADER_RLE 0x08
#define PLANAR_FORMAT_HEADER_NA 0x10

#define PIXEL_FORMAT_BGRA32 0
#define PIXEL_FORMAT_BGRX32 0
#define PRIMITIVES_SUCCESS 0
#define FREERDP_FLIP_NONE 0

typedef struct _BITMAP_PLANAR_CONTEXT {
    BYTE* pTempData;
    UINT32 nTempStep;
    UINT32 maxHeight;
    BYTE* rlePlanesBuffer;
    BYTE* deltaPlanes[2];
} BITMAP_PLANAR_CONTEXT;

typedef struct _primitives_t {
    int (*YCoCgToRGB_8u_AC4R)(const BYTE* pSrc, INT32 srcStep, BYTE* pDst, UINT32 dstFormat,
                              INT32 dstStep, UINT32 width, UINT32 height, UINT32 shift,
                              BOOL withAlpha);
} primitives_t;

UINT32 FreeRDPGetBytesPerPixel(UINT32 format);
BOOL FreeRDPColorHasAlpha(UINT32 format);
UINT32 planar_invert_format(BITMAP_PLANAR_CONTEXT* planar, BOOL alpha, UINT32 format);
INT32 planar_skip_plane_rle(const BYTE* pSrcData, UINT32 SrcSize, UINT32 nWidth, UINT32 nHeight);
BOOL planar_decompress_planes_raw(const BYTE** planes, BYTE* pDstData, UINT32 DstFormat,
                                 UINT32 nDstStep, UINT32 nXDst, UINT32 nYDst, UINT32 nWidth,
                                 UINT32 nHeight, BOOL vFlip, UINT32 nTotalHeight);
INT32 planar_decompress_plane_rle(const BYTE* pSrcData, INT32 SrcSize, BYTE* pDstData,
                                 UINT32 nDstStep, UINT32 nXDst, UINT32 nYDst, UINT32 nWidth,
                                 UINT32 nHeight, UINT32 plane, BOOL vFlip);
BOOL planar_set_plane(BYTE val, BYTE* pDstData, UINT32 nDstStep, UINT32 nXDst, UINT32 nYDst,
                      UINT32 nWidth, UINT32 nHeight, UINT32 plane, BOOL vFlip);
BOOL freerdp_image_copy(BYTE* pDstData, UINT32 DstFormat, UINT32 nDstStep, UINT32 nXDst,
                        UINT32 nYDst, UINT32 nWidth, UINT32 nHeight, const BYTE* pSrcData,
                        UINT32 SrcFormat, UINT32 nSrcStep, UINT32 nXSrc, UINT32 nYSrc,
                        const BYTE* palette, UINT32 flags);
BOOL planar_subsample_expand(const BYTE* pSrcData, UINT32 SrcSize, UINT32 nWidth, UINT32 nHeight,
                             UINT32 subWidth, UINT32 subHeight, BYTE* pDstData);
INT32 planar_decompress_plane_rle_only(const BYTE* pSrcData, INT32 SrcSize, BYTE* pDstData,
                                      UINT32 nWidth, UINT32 nHeight);
const primitives_t* primitives_get();