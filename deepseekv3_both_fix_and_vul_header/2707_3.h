#include <stdlib.h>
#include <string.h>

typedef int GBool;
#define gTrue 1
#define gFalse 0

#define errSyntaxError 1

typedef int (*FoFiOutputFunc)(void *stream, const char *data, int len);

typedef struct {
    int pos;
    int len;
} Type1CIndexVal;

typedef struct {
    int pos;
    int len;
    Type1CIndexVal *data;
} Type1CIndex;

typedef struct {
    void *outputStream;
    FoFiOutputFunc outputFunc;
    GBool ascii;
    int r1;
    int line;
} Type1CEexecBuf;

typedef struct {
    int firstOp;
    GBool hasFontMatrix;
    double fontMatrix[6];
    double fontBBox[4];
    int paintType;
    double strokeWidth;
} Type1CTopDict;

typedef struct {
    GBool hasFontMatrix;
    double fontMatrix[6];
    int nBlueValues;
    int *blueValues;
    int nOtherBlues;
    int *otherBlues;
    int nFamilyBlues;
    int *familyBlues;
    int nFamilyOtherBlues;
    int *familyOtherBlues;
    double blueScale;
    int blueShift;
    int blueFuzz;
    GBool hasStdHW;
    double stdHW;
    GBool hasStdVW;
    double stdVW;
    int nStemSnapH;
    double *stemSnapH;
    int nStemSnapV;
    double *stemSnapV;
    GBool hasForceBold;
    GBool forceBold;
    double forceBoldThreshold;
    int languageGroup;
    double expansionFactor;
    int subrsOffset;
} Type1CPrivateDict;

class GooString {
public:
    GooString(const char *s);
    ~GooString();
    const char *getCString();
    int getLength();
    static GooString *format(const char *fmt, ...);
};

class FoFiType1C {
public:
    void convertToType0(char *psName, int *codeMap, int nCodes,
                      FoFiOutputFunc outputFunc, void *outputStream);
private:
    Type1CTopDict topDict;
    Type1CPrivateDict *privateDicts;
    int nGlyphs;
    int charsetLength;
    int *charset;
    int *fdSelect;
    int nFDs;
    Type1CIndex charStringsIdx;
};

void *gmallocn(int n, int size);
void gfree(void *p);
void error(int errCode, int pos, const char *msg);
void eexecWrite(Type1CEexecBuf *eb, const char *s);
void eexecCvtGlyph(Type1CEexecBuf *eb, const char *glyphName, int offset, int length,
                  Type1CIndex *subrIdx, Type1CPrivateDict *pDict);
void getIndex(int offset, Type1CIndex *idx, GBool *ok);
void getIndexVal(Type1CIndex *idx, int i, Type1CIndexVal *val, GBool *ok);