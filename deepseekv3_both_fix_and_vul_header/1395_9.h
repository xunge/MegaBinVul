#include <vector>
#include <memory>

class Stream {
public:
    int getPos();
};

class JBIG2HuffmanTable {
public:
    int val;
    unsigned int prefixLen;
    unsigned int rangeLen;
};

class JBIG2HuffmanDecoder {
public:
    void reset();
    unsigned int readBits(unsigned int n);
    void decodeInt(int* x, JBIG2HuffmanTable* table);
    static bool buildTable(JBIG2HuffmanTable* table, unsigned int size);
};

class JBIG2CodeTable {
public:
    const JBIG2HuffmanTable* getHuffTable();
};

class JBIG2Bitmap {
public:
    void expand(unsigned int newHeight, int pixel);
    bool isOk();
    void combine(JBIG2Bitmap* src, unsigned int x, unsigned int y, unsigned int op);
    void setSegNum(unsigned int segNum);
};

class JBIG2Stream {
public:
    void readTextRegionSeg(unsigned int segNum, bool imm, bool lossless, unsigned int length, unsigned int *refSegs, unsigned int nRefSegs);
    bool readULong(unsigned int*);
    bool readUByte(unsigned int*);
    bool readUWord(unsigned int*);
    bool readByte(int*);
    int getPos();
    std::unique_ptr<JBIG2Bitmap> readTextRegion(bool huff, bool refine, unsigned int w, unsigned int h, 
        unsigned int numInstances, unsigned int logStrips, unsigned int numSyms, 
        JBIG2HuffmanTable* symCodeTab, unsigned int symCodeLen, JBIG2Bitmap** syms, 
        unsigned int defPixel, unsigned int combOp, bool transposed, 
        unsigned int refCorner, int sOffset, const JBIG2HuffmanTable* huffFSTable, 
        const JBIG2HuffmanTable* huffDSTable, const JBIG2HuffmanTable* huffDTTable, 
        const JBIG2HuffmanTable* huffRDWTable, const JBIG2HuffmanTable* huffRDHTable,
        const JBIG2HuffmanTable* huffRDXTable, const JBIG2HuffmanTable* huffRDYTable, 
        const JBIG2HuffmanTable* huffRSizeTable, unsigned int templ, int atx[2], int aty[2]);
};

class JBIG2Segment {
public:
    int getType();
};

class JBIG2SymbolDict {
public:
    unsigned int getSize();
    JBIG2Bitmap* getBitmap(unsigned int k);
};

class JBIG2ArithDecoder {
public:
    void start();
};

enum {
    jbig2SegSymbolDict,
    jbig2SegCodeTable
};

enum {
    jbig2HuffmanEOT
};

extern const JBIG2HuffmanTable* huffTableF;
extern const JBIG2HuffmanTable* huffTableG;
extern const JBIG2HuffmanTable* huffTableH;
extern const JBIG2HuffmanTable* huffTableI;
extern const JBIG2HuffmanTable* huffTableJ;
extern const JBIG2HuffmanTable* huffTableK;
extern const JBIG2HuffmanTable* huffTableL;
extern const JBIG2HuffmanTable* huffTableM;
extern const JBIG2HuffmanTable* huffTableN;
extern const JBIG2HuffmanTable* huffTableO;
extern const JBIG2HuffmanTable* huffTableA;

extern unsigned int pageH;
extern unsigned int curPageH;
extern int pageDefPixel;
extern JBIG2Bitmap *pageBitmap;
extern JBIG2HuffmanDecoder *huffDecoder;
extern JBIG2ArithDecoder *arithDecoder;
extern Stream *curStr;
extern std::vector<std::unique_ptr<JBIG2Bitmap>> segments;

const int errSyntaxError = 1;

JBIG2Segment* findSegment(unsigned int);
void error(int, int, const char*);
bool checkedAdd(unsigned int, unsigned int, unsigned int*);
bool unlikely(bool);
bool resetIntStats(unsigned int);
bool resetRefinementStats(unsigned int templ, void*);
void gfree(void*);
void* gmallocn_checkoverflow(size_t, size_t);