#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define WINPR_ASSERT(expr) ((void)0)

typedef uint8_t BYTE;
typedef uint32_t UINT32;

#define FillMemory(dest, size, val) memset(dest, val, size)
#define CopyMemory(dest, src, size) memcpy(dest, src, size)

typedef struct
{
    BYTE* Planes;
    size_t PlanesSize;
    UINT32 OrgByteCount[4];
    UINT32 PlaneByteCount[4];
    struct
    {
        BYTE* PlaneBuffers[4];
        size_t PlaneBuffersLength;
    }* priv;
} NSC_CONTEXT;

static BOOL nsc_rle_decode_full(const BYTE* rle, size_t rleSize, BYTE* output, size_t outputSize, UINT32 originalSize)
{
    return TRUE;
}

static BOOL nsc_rle_decode_simple(BYTE* rle, BYTE* output, size_t outputSize, UINT32 originalSize)
{
    return TRUE;
}