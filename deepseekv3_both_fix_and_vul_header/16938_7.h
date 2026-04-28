#include <stdio.h>
#include <string.h>
#include <utility>

typedef long long Goffset;

struct GooString {
    const char* c_str() const;
};

struct Object;
struct Dict;
struct Ref;

struct OutStream {
    Goffset getPos();
    void printf(const char* fmt, ...);
    void close();
};

enum CryptAlgorithm {
    cryptRC4
};

enum ErrorCode {
    errNone,
    errFileChangedSinceOpen,
    errOpenFile,
    errInternal,
    errIO,
    errSyntaxError,
    errDamaged
};

enum XRefEntryType {
    xrefEntryCompressed
};

struct Ref {
    int num;
    int gen;
};

struct Object {
    bool isDict() const;
    bool isNull() const;
    bool isRef() const;
    Dict* getDict();
    Ref getRef() const;
    Object copy();
};

struct Dict {
    const char* getKey(int i);
    Object getValNF(int i);
    int getLength();
    bool hasKey(const char* key);
    Object lookup(const char* key);
    Object lookupNF(const char* key);
};

struct PDFRectangle {
};

struct Entry {
    int type;
};

struct XRef {
    XRef();
    XRef(Object* trailerDict);
    void scanSpecialFlags();
    void getEncryptionParameters(unsigned char** fileKey, CryptAlgorithm* encAlgorithm, int* keyLength);
    void setEncryption(int permFlags, bool ownerPasswordOk, unsigned char* fileKey, int keyLength, int encVersion, int encRevision, CryptAlgorithm encAlgorithm);
    void add(int num, int gen, Goffset offset, bool used);
    void add(Ref ref, int gen, bool used);
    void markUnencrypted();
    int getNumObjects();
    Object* getTrailerDict();
    Object getDocInfo();
    Object getCatalog();
    Object fetch(Ref ref);
    Entry* getEntry(int num);
};

class FileOutStream : public OutStream {
public:
    FileOutStream(FILE* f, int);
};

class BaseFile {
public:
    bool modificationTimeChangedSinceOpen();
};

class SecurityHandler {
public:
    bool isUnencrypted();
    int getPermissionFlags();
    bool getOwnerPasswordOk();
    int getEncVersion();
    int getEncRevision();
};

class Page {
public:
    bool isCropped();
    const PDFRectangle* getCropBox();
    int getRotate();
    const PDFRectangle* getMediaBox();
    Object* getResourceDictObject();
    Ref getPageRef(int pageNo);
};

class Catalog {
public:
    Page* getPage(int pageNo);
    Ref* getPageRef(int pageNo);
};

class PDFDoc {
public:
    int savePageAs(const GooString& name, int pageNo);
    XRef* getXRef();
    int getNumPages();
    Catalog* getCatalog();
    bool modificationTimeChangedSinceOpen();
    void replacePageDict(int pageNo, int rotate, const PDFRectangle* mediaBox, const PDFRectangle* cropBox);
    void writeHeader(OutStream* outStr, int major, int minor);
    bool markPageObjects(Dict* dict, XRef* yRef, XRef* countRef, int level, int pageNum, int rootNum);
    void markAcroForm(Object* afObj, XRef* yRef, XRef* countRef, int level, int pageNum, int rootNum);
    void markAnnotations(Object* annotsObj, XRef* yRef, XRef* countRef, int level, int pageNum, int rootNum);
    void writePageObjects(OutStream* outStr, XRef* yRef, int level);
    Object createTrailerDict(int rootNum, bool, int, Ref*, XRef*, const char*, Goffset);
    void writeXRefTableTrailer(Object&& trailerDict, XRef* yRef, bool, Goffset uxrefOffset, OutStream* outStr, XRef* xref);
    int getPDFMajorVersion();
    int getPDFMinorVersion();
    void error(int, int, const char*, ...);
    FILE* openFile(const char*, const char*);
    void writeObject(Object* obj, OutStream* outStr, XRef* xref, int level, unsigned char* fileKey, CryptAlgorithm encAlgorithm, int keyLength, int objNum, int objGen);
    XRef* xref;
    SecurityHandler* secHdlr;
    BaseFile* file;
};