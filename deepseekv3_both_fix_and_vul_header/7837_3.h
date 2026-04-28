#include <assert.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t UBYTE;
typedef uint32_t ULONG;
typedef int32_t LONG;

template<typename T>
struct RectAngle {
    T ra_MinX;
    T ra_MaxX;
    T ra_MinY;
    T ra_MaxY;
};

struct RectangleRequest {
    bool rr_bColorTrafo;
    bool rr_bUpsampling;
    UBYTE rr_usFirstComponent;
    UBYTE rr_usLastComponent;
};

class ColorTrafo {
public:
    void YCbCr2RGB(const RectAngle<LONG>&, void**, LONG**, void*);
};

class Component {
public:
    UBYTE SubXOf();
    UBYTE SubYOf();
};

class UpsamplerBase {
public:
    void SetBufferedRegion(const RectAngle<LONG>&);
    void DefineRegion(LONG, LONG, LONG*);
    void UpsampleRegion(const RectAngle<LONG>&, LONG*);
};

class Frame {
public:
    Component* ComponentOf(UBYTE);
};

class LineBitmapRequester {
public:
    bool m_bSubsampling;
    ULONG m_ulPixelWidth;
    ULONG m_ulPixelHeight;
    ULONG m_ulMaxMCU;
    UBYTE m_ucCount;
    UpsamplerBase** m_ppUpsampler;
    LONG*** m_pppImage;
    LONG** m_ppCTemp;
    void** m_ppTempIBM;
    Frame* m_pFrame;
    
    void ReconstructRegion(const RectAngle<LONG>&, const RectangleRequest*);
    ColorTrafo* ColorTrafoOf(bool, bool);
    void Next8Lines(UBYTE);
    void ExtractBitmap(void*, const RectAngle<LONG>&, UBYTE);
    void FetchRegion(LONG, LONG*, LONG*);
    void SubsampledRegion(RectAngle<LONG>&, const RectangleRequest*);
};