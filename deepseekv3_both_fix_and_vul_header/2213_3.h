#include <cstddef>
#include <cstdint>

#define FALSE 0
#define TRUE 1

typedef unsigned char BYTE;

enum GIFAction {
    GLOBAL_HEADER_READING
};

class SvStream {
public:
    long Tell();
};

class UniString {
public:
    static UniString CreateFromAscii(const char*, size_t);
};

class Palette {
public:
    Palette(int);
};

class GIFReader {
private:
    Palette aGPalette;
    Palette aLPalette;
    SvStream& rIStm;
    void* pAcc8;
    void* pAcc1;
    long nLastPos;
    unsigned long nLogWidth100;
    unsigned long nLogHeight100;
    int nGlobalWidth;
    int nGlobalHeight;
    int nImageWidth;
    int nImageHeight;
    int nLoops;
    GIFAction eActAction;
    bool bGCTransparent;
    bool bImGraphicReady;
    UniString maUpperName;
    BYTE* pSrcBuf;
public:
    GIFReader(SvStream& rStm);
    void ClearImageExtensions();
};