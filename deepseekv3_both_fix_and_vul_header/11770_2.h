#include <stdint.h>
#include <stdlib.h>

#define BOOL int
#define BYTE uint8_t
#define UINT32 uint32_t
#define TRUE 1
#define FALSE 0
#define FREERDP_FLIP_VERTICAL 1

typedef struct rdpPalette {
    BYTE entries[256][4];
} rdpPalette;

typedef struct rdpGdi {
    UINT32 dstFormat;
    rdpPalette palette;
} rdpGdi;

typedef struct rdpBitmap {
    BOOL compressed;
    UINT32 format;
    UINT32 length;
    BYTE* data;
} rdpBitmap;

typedef struct rdpCodecs {
    void* interleaved;
    void* planar;
} rdpCodecs;

typedef struct rdpContext {
    rdpGdi* gdi;
    rdpCodecs* codecs;
} rdpContext;

UINT32 GetBytesPerPixel(UINT32 format);
UINT32 gdi_get_pixel_format(UINT32 bpp);
BOOL interleaved_decompress(void* interleaved, const BYTE* pSrcData, UINT32 SrcSize,
                           UINT32 DstWidth, UINT32 DstHeight, UINT32 bpp,
                           BYTE* pDstData, UINT32 DstFormat,
                           UINT32 nXDst, UINT32 nYDst, UINT32 nDstStep,
                           UINT32 nWidth, UINT32 nHeight, rdpPalette* palette);
BOOL planar_decompress(void* planar, const BYTE* pSrcData, UINT32 SrcSize,
                       UINT32 DstWidth, UINT32 DstHeight,
                       BYTE* pDstData, UINT32 DstFormat,
                       UINT32 nXDst, UINT32 nYDst, UINT32 nDstStep,
                       UINT32 nWidth, UINT32 nHeight, BOOL vFlip);
BOOL freerdp_image_copy(BYTE* pDstData, UINT32 DstFormat, UINT32 nXDst, UINT32 nYDst, UINT32 nDstStep,
                        UINT32 nWidth, UINT32 nHeight,
                        const BYTE* pSrcData, UINT32 SrcFormat,
                        UINT32 nXSrc, UINT32 nYSrc, UINT32 nSrcStep,
                        rdpPalette* palette, UINT32 flags);
void* _aligned_malloc(size_t size, size_t alignment);