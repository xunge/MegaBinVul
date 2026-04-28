#include <assert.h>
#include <stddef.h>
#include <new>

typedef unsigned char UBYTE;

enum ScanType {
    Baseline,
    Sequential,
    DifferentialSequential,
    Lossless,
    DifferentialLossless,
    ACLossless,
    ACDifferentialLossless,
    ACSequential,
    ACDifferentialSequential,
    Progressive,
    ResidualProgressive,
    DifferentialProgressive,
    ACProgressive,
    ACDifferentialProgressive,
    ACResidualProgressive,
    Residual,
    ACResidual,
    ResidualDCT,
    ACResidualDCT,
    JPEG_LS
};

class Frame {
public:
    ScanType ScanTypeOf();
};

class Scan {
public:
    void CreateParser();
    void* ComponentOf(UBYTE i);
    Frame* m_pFrame;
    void* m_pParser;
    void* m_pEnviron;
    UBYTE m_ucCount;
    UBYTE m_ucScanStart;
    UBYTE m_ucScanStop;
    UBYTE m_ucLowBit;
    UBYTE m_ucHighBit;
    UBYTE m_ucHiddenBits;
    UBYTE m_ucMappingTable;
};

class SequentialScan {
public:
    SequentialScan(Frame* frame, Scan* scan, UBYTE start, UBYTE stop, UBYTE low, UBYTE high, bool diff = false, bool residual = false, bool dct = false, bool baseline = false);
};

class LosslessScan {
public:
    LosslessScan(Frame* frame, Scan* scan, UBYTE start, UBYTE low, bool diff = false);
};

class ACLosslessScan {
public:
    ACLosslessScan(Frame* frame, Scan* scan, UBYTE start, UBYTE low, bool diff = false);
};

class ACSequentialScan {
public:
    ACSequentialScan(Frame* frame, Scan* scan, UBYTE start, UBYTE stop, UBYTE low, UBYTE high, bool diff = false, bool residual = false, bool dct = false);
};

class RefinementScan {
public:
    RefinementScan(Frame* frame, Scan* scan, UBYTE start, UBYTE stop, UBYTE low, UBYTE high, bool diff = false, bool residual = false);
};

class ACRefinementScan {
public:
    ACRefinementScan(Frame* frame, Scan* scan, UBYTE start, UBYTE stop, UBYTE low, UBYTE high, bool diff = false, bool residual = false);
};

class SingleComponentLSScan {
public:
    SingleComponentLSScan(Frame* frame, Scan* scan, UBYTE near, UBYTE mapping, UBYTE low);
};

class LineInterleavedLSScan {
public:
    LineInterleavedLSScan(Frame* frame, Scan* scan, UBYTE near, UBYTE mapping, UBYTE low);
};

class SampleInterleavedLSScan {
public:
    SampleInterleavedLSScan(Frame* frame, Scan* scan, UBYTE near, UBYTE mapping, UBYTE low);
};

#define JPG_THROW(code, location, message)