#include <cstdio>
#include <vector>
#include <memory>
#include <cstring>

typedef long long Goffset;

class GooString {
public:
    GooString(const char* str);
    const char* c_str() const;
    int cmp(const GooString* other) const;
};

class Ref {
public:
    int num;
    int gen;
};

class XRef {
public:
    void add(int num, int gen, Goffset pos, bool used);
    int getNumObjects();
    Goffset getPos();
    class Object getCatalog();
    class Object fetch(const Ref& ref);
};

class OutStream {
public:
    Goffset getPos();
    void printf(const char* format, ...);
    void close();
};

class FileOutStream : public OutStream {
public:
    FileOutStream(FILE* f, int);
};

class Dict {
public:
    Dict(XRef* xref);
    class Object lookup(const char* key);
    class Object lookupNF(const char* key);
    void set(const char* key, const class Object& value);
    const char* getKey(int i);
    class Object getValNF(int i);
    int getLength();
};

class PDFRectangle {
public:
    const PDFRectangle* getCropBox() const;
    const PDFRectangle* getMediaBox() const;
    int getRotate() const;
    bool isCropped() const;
};

class Page {
public:
    bool isCropped() const;
    const PDFRectangle* getCropBox() const;
    const PDFRectangle* getMediaBox() const;
    int getRotate() const;
    class Object* getResourceDictObject();
};

class Catalog {
public:
    class Page* getPage(int i);
    class Ref* getPageRef(int i);
};

class Object {
public:
    Object();
    Object(Dict* dict);
    bool isOk();
    bool isEncrypted();
    XRef* getXRef();
    int getPDFMajorVersion();
    int getPDFMinorVersion();
    const char* getFileName();
    Dict* getDict();
    bool isDict();
    bool isArray();
    int arrayGetLength();
    Object arrayGet(int i, int);
    void arrayRemove(int i);
    bool isNull();
    bool isString();
    const GooString* getString();
    Object copy();
    Object dictLookup(const char* key);
    Catalog* getCatalog();
};

class GlobalParams {
public:
    GlobalParams();
    ~GlobalParams();
};

class PDFDoc {
public:
    PDFDoc(std::unique_ptr<GooString> fileName);
    bool isOk();
    bool isEncrypted();
    XRef* getXRef();
    int getPDFMajorVersion();
    int getPDFMinorVersion();
    const GooString* getFileName() const;
    Catalog* getCatalog();
    int getNumPages();
    void replacePageDict(int i, int rotate, const PDFRectangle* mediaBox, const PDFRectangle* cropBox);
    void markAcroForm(Object* obj, XRef* yRef, XRef* countRef, int offset, int oldRefNum, int newRefNum);
    void markPageObjects(Dict* dict, XRef* yRef, XRef* countRef, int offset, int oldRefNum, int newRefNum);
    void markAnnotations(Object* obj, XRef* yRef, XRef* countRef, int offset, int oldRefNum, int newRefNum);
    int writePageObjects(OutStream* outStr, XRef* yRef, unsigned int numOffset, bool combine);
    static void writeHeader(OutStream* outStr, int majorVersion, int minorVersion);
    static void writeObject(Object* obj, OutStream* outStr, XRef* yRef, unsigned int numOffset, XRef* srcXRef, int encAlgorithm, int keyLength, int objNum, int objGen);
    static Object createTrailerDict(int objectsCount, bool incUpdate, Goffset startxRef, Ref* root, XRef* xRef, const char* fileName, Goffset fileSize);
    static void writeXRefTableTrailer(Object&& trailerDict, XRef* xRef, bool writeAllEntries, Goffset uxrefOffset, OutStream* outStr, XRef* xRefTable);
};

extern std::unique_ptr<GlobalParams> globalParams;
extern const char *PACKAGE_VERSION;
extern const char *popplerCopyright;
extern const char *xpdfCopyright;
extern bool printVersion;
extern bool printHelp;
extern const char *argDesc[];
extern bool parseArgs(const char *desc[], int *argc, char *argv[]);
extern void printUsage(const char *programName, const char *defaultCmdLine, const char *desc[]);
extern void error(int category, int pos, const char *msg, ...);
extern void doMergeNameDict(PDFDoc *doc, XRef *yRef, XRef *countRef, int oldRefNum, int newRefNum, Dict *names, Dict *oldNames, unsigned int numOffset);
extern void doMergeFormDict(Dict *dest, Dict *src, unsigned int numOffset);

enum {
    errUnimplemented = -2,
    errSyntaxError = -1,
    errIO = 1,
    errSyntaxWarning = 2
};

enum {
    cryptRC4
};