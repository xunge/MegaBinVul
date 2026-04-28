#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int FX_BOOL;
typedef uint8_t FX_BYTE;
typedef uint32_t FX_DWORD;
typedef FX_BYTE* FX_LPBYTE;
typedef const FX_BYTE* FX_LPCBYTE;

enum FXDIB_Format {
    FXDIB_8bppMask,
    FXDIB_8bppRgb,
    FXDIB_Rgb32,
    FXDIB_Argb
};

#define TRUE 1
#define FALSE 0

#define FX_TryAlloc(type, size) (type*)malloc(size)
#define FX_AllocNL(type, size) (type*)malloc(size)
#define FX_Free(ptr) free(ptr)
#define FXSYS_memset8(dest, val, size) memset(dest, val, size)

class CFX_DIBitmap {
public:
    FXDIB_Format GetFormat();
    FX_BOOL BuildAlphaMask();
    CFX_DIBitmap* GetAlphaMask();
    FX_LPCBYTE GetScanline(int row);
    FX_BOOL ConvertBuffer(FXDIB_Format dest_format, FX_LPBYTE dest_buf, int dest_pitch, int width, int height, CFX_DIBitmap* src, int src_x, int src_y, FX_DWORD*& pal_8bpp, void* pIccTransform);
    FX_BOOL ConvertFormat(FXDIB_Format dest_format, void* pIccTransform);

    FX_LPBYTE m_pBuffer;
    FX_DWORD* m_pPalette;
    CFX_DIBitmap* m_pAlphaMask;
    int m_Width;
    int m_Height;
    int m_Pitch;
    FX_BYTE m_bpp;
    FX_BYTE m_AlphaFlag;
    FX_BOOL m_bExtBuf;
};