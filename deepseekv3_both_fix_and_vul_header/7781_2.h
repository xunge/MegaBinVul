#include <stdio.h>
#include <stdlib.h>

typedef unsigned char UBYTE;
typedef long LONG;
typedef unsigned long ULONG;

struct Line {
    LONG *m_pData;
    struct Line *m_pNext;
};

class HuffmanDecoder {
public:
    UBYTE Get(void*);
};

class PredictorBase {
public:
    LONG DecodeSample(LONG, LONG*, LONG*);
    PredictorBase* MoveRight();
    PredictorBase* MoveDown();
};

class LosslessScan {
public:
    void ParseMCU(struct Line **prev, struct Line **top);
private:
    UBYTE m_ucCount;
    HuffmanDecoder **m_pDCDecoder;
    UBYTE *m_ucMCUHeight;
    PredictorBase **m_pPredict;
    ULONG *m_ulX;
    UBYTE *m_ucMCUWidth;
    class Stream {
    public:
        LONG Get(UBYTE);
    } m_Stream;
};

#define ACCUSOFT_CODE 1
#define JPG_THROW(a,b,c)
#define NOREF(a) (void)(a)