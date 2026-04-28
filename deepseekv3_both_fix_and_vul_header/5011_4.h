#include <stdbool.h>

class GooString;

class BaseStream {
public:
    int getLength();
    void setPos(int pos, int dir);
    int getPos();
    void reset();
};

class XRef {
public:
    XRef(BaseStream* str, long startXRef, long mainXRefEntriesOffset, bool* wasReconstructed);
    XRef(BaseStream* str, long startXRef, long mainXRefEntriesOffset, void* unused, bool forceReconstructed);
    bool isOk();
    int getErrorCode();
};

class PDFDoc;

class Catalog {
public:
    Catalog(PDFDoc* doc);
    bool isOk();
};

class PDFDoc {
public:
    bool setup(const GooString* ownerPassword, const GooString* userPassword);
};

enum ErrorCode {
    errSyntaxError,
    errEncrypted,
    errBadCatalog
};

extern void pdfdocLocker();
extern void error(int errorCode, int pos, const char* msg);
extern bool checkHeader();
extern bool checkEncryption(const GooString* ownerPassword, const GooString* userPassword);
extern void extractPDFSubtype();
extern long getStartXRef(bool reconstructed = false);
extern long getMainXRefEntriesOffset(bool reconstructed = false);

extern BaseStream* str;
extern XRef* xref;
extern Catalog* catalog;
extern int errCode;
extern long startXRefPos;