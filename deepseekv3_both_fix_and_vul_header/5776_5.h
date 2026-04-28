#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define FALSE 0
#define TRUE 1

typedef int FX_BOOL;
typedef uint8_t FX_BYTE;
typedef uint8_t* FX_LPBYTE;

enum FXDIB_Format {
    FXDIB_Argb
};

#define _MAX_OOM_LIMIT_ (-1)

struct CFX_DIBitmap {
    FX_LPBYTE m_pBuffer;
    FX_BYTE m_bpp;
    FX_BYTE m_AlphaFlag;
    int m_Width;
    int m_Height;
    int m_Pitch;
    FX_BOOL m_bExtBuf;
    
    FX_BOOL HasAlpha();
    FX_BOOL BuildAlphaMask();
    FX_BOOL Create(int width, int height, FXDIB_Format format, FX_LPBYTE pBuffer, int pitch);
};

void* FX_Alloc(size_t size);
void* FX_AllocNL(size_t size);
void* FX_TryAlloc(size_t size);
void FX_Free(void* ptr);

#define FX_Alloc(type, size) ((type*)FX_Alloc((size)*sizeof(type)))
#define FX_AllocNL(type, size) ((type*)FX_AllocNL((size)*sizeof(type)))
#define FX_TryAlloc(type, size) ((type*)FX_TryAlloc((size)*sizeof(type)))