#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned int FX_DWORD;
typedef int FX_BOOL;
typedef unsigned char FX_BYTE;
typedef float FX_FLOAT;

enum FXDIB_Format {
    FXDIB_Rgb32
};

enum {
    FXDIB_NOSMOOTH,
    FXDIB_INTERPOL,
    FXDIB_BICUBIC_INTERPOL,
    FXDIB_DOWNSAMPLE
};

struct FX_RECT {
    int left;
    int top;
    int right;
    int bottom;
    
    FX_RECT() : left(0), top(0), right(0), bottom(0) {}
    FX_RECT(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
    
    int Width() const { return right - left; }
    int Height() const { return bottom - top; }
    void Intersect(const FX_RECT& rect) {
        left = (left > rect.left) ? left : rect.left;
        top = (top > rect.top) ? top : rect.top;
        right = (right < rect.right) ? right : rect.right;
        bottom = (bottom < rect.bottom) ? bottom : rect.bottom;
        if (left > right) left = right;
        if (top > bottom) top = bottom;
    }
};

class IFX_ScanlineComposer;

class CFX_DIBSource {
public:
    virtual int GetFormat() const = 0;
    virtual const void* GetPalette() const = 0;
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual ~CFX_DIBSource() {}
};

class CStretchEngine {
public:
    CStretchEngine(IFX_ScanlineComposer* pDestBitmap, FXDIB_Format dest_format,
                  int dest_width, int dest_height, const FX_RECT& clip_rect,
                  const CFX_DIBSource* pSrcBitmap, int flags);
private:
    int m_State;
    FXDIB_Format m_DestFormat;
    int m_DestBpp;
    int m_SrcBpp;
    bool m_bHasAlpha;
    const void* m_pSrcPalette;
    IFX_ScanlineComposer* m_pDestBitmap;
    int m_DestWidth;
    int m_DestHeight;
    void* m_pInterBuf;
    void* m_pExtraAlphaBuf;
    void* m_pDestMaskScanline;
    FX_RECT m_DestClip;
    unsigned char* m_pDestScanline;
    int m_InterPitch;
    int m_ExtraMaskPitch;
    const CFX_DIBSource* m_pSource;
    int m_SrcWidth;
    int m_SrcHeight;
    int m_SrcPitch;
    int m_Flags;
    FX_RECT m_SrcClip;
    int m_TransMethod;
};

#define FX_AllocNL(type, size) (type*)malloc(size)
#define FX_TryAlloc(type, size) (type*)malloc(size)
#define FXSYS_memset8 memset
#define FXSYS_abs abs
#define FXSYS_Div(a, b) ((double)(a) / (double)(b))
#define FXSYS_Mul(a, b) ((double)(a) * (double)(b))
#define FXSYS_floor floor
#define FXSYS_ceil ceil