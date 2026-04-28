#include <stdbool.h>

typedef unsigned char UBYTE;
typedef unsigned long ULONG;
typedef long LONG;

struct Line {
    LONG *m_pData;
    struct Line *m_pNext;
};

struct QMContextSet {
    struct ContextZeroSet {
        int S0;
        int SS;
        int SN;
        int SP;
    };
    struct MagnitudeSet {
        int X[16];
        int M[16];
    };
    ContextZeroSet ClassifySignZero(LONG, LONG, UBYTE, UBYTE);
    MagnitudeSet ClassifyMagnitude(LONG, UBYTE);
};

class PredictorBase {
public:
    LONG DecodeSample(LONG, LONG*, LONG*);
    PredictorBase* MoveRight();
    PredictorBase* MoveDown();
};

class Coder {
public:
    bool Get(int);
};

class ACLosslessScan {
    UBYTE m_ucCount;
    QMContextSet *m_Context;
    UBYTE *m_ucContext;
    UBYTE *m_ucMCUHeight;
    ULONG *m_ulX;
    PredictorBase **m_pPredict;
    LONG **m_plDa;
    LONG **m_plDb;
    UBYTE *m_ucSmall;
    UBYTE *m_ucLarge;
    UBYTE *m_ucMCUWidth;
    Coder m_Coder;
public:
    void ParseMCU(struct Line **prev, struct Line **top);
};

#define NOREF(x) (void)(x)