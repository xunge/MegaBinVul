#include <stdlib.h>
#include <string.h>

typedef unsigned char UBYTE;
typedef unsigned long ULONG;

struct Line;
class UpsamplerBase;
class Component;
class Frame;
class Environment;

struct FrameTables {
    bool isChromaCentered();
};

class Frame {
public:
    Component* ComponentOf(UBYTE);
    FrameTables* TablesOf();
};

class Environment {
public:
    void* AllocMem(size_t);
};

class UpsamplerBase {
public:
    static UpsamplerBase* CreateUpsampler(Environment*, UBYTE, UBYTE, ULONG, ULONG, bool);
};

class HierarchicalBitmapRequester {
private:
    Line** m_ppDecodingMCU;
    UpsamplerBase** m_ppUpsampler;
    UBYTE m_ucCount;
    ULONG m_ulPixelWidth;
    ULONG m_ulPixelHeight;
    bool m_bSubsampling;
    Environment* m_pEnviron;
    Frame* m_pFrame;
    void* m_pLargestScale;

    void BuildCommon();
public:
    void PrepareForDecoding(void);
};