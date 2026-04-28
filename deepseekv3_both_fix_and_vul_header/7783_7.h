#include <climits>
#include <stdexcept>

typedef unsigned char UBYTE;
typedef long LONG;

#define MALFORMED_STREAM 1
#define JPG_THROW(code, func, msg) throw std::runtime_error(msg)

class QMContextSet {
public:
    struct DCContextZeroSet {
        bool S0;
        bool SS;
        bool SP;
        bool SN;
    };
    
    struct DCContextMagnitudeSet {
        static const int MagnitudeContexts = 16;
        bool X[MagnitudeContexts];
        bool M[MagnitudeContexts];
    };
    
    struct ACContextMagnitudeSet {
        static const int MagnitudeContexts = 16;
        bool X[MagnitudeContexts];
        bool M[MagnitudeContexts];
    };
    
    struct ACZeroContext {
        bool SE;
        bool S0;
        bool SP;
    };
    
    struct Context {
        DCContextZeroSet DCZero;
        DCContextMagnitudeSet DCMagnitude;
        ACZeroContext ACZero[64];
        bool Uniform;
        ACContextMagnitudeSet ACMagnitudeHigh;
        ACContextMagnitudeSet ACMagnitudeLow;
        
        DCContextZeroSet& Classify(LONG, UBYTE, UBYTE) { return DCZero; }
    };
    
    Context& operator[](UBYTE index) { return m_Contexts[index]; }
    
private:
    Context m_Contexts[4];
};

class DCT {
public:
    static int ScanOrder[64];
};

class QMCoder {
public:
    bool Get(bool &context) { return false; }
};

class ACSequentialScan {
public:
    void DecodeBlock(LONG *block, LONG &prevdc, LONG &prevdiff,
                    UBYTE small, UBYTE large, UBYTE kx, UBYTE dc, UBYTE ac);
private:
    UBYTE m_ucScanStart;
    UBYTE m_ucScanStop;
    UBYTE m_ucLowBit;
    bool m_bResidual;
    bool m_bDifferential;
    QMContextSet m_Context;
    QMCoder m_Coder;
};