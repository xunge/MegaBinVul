#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned short Unicode;

struct GooString {
    GooString(const char*);
    ~GooString();
    bool hasUnicodeMarker() const;
    int getLength() const;
    char getChar(int) const;
};

struct UnicodeMap {
    int mapUnicode(Unicode u, char *buf, int bufSize);
    void decRefCnt();
};

struct GlobalParams {
    GlobalParams();
    ~GlobalParams();
    void setTextEncoding(const char*);
    UnicodeMap* getTextEncoding();
};

struct PDFDoc {
    ~PDFDoc();
    bool isOk();
    struct Catalog* getCatalog();
};

struct Catalog {
    int numEmbeddedFiles();
    struct FileSpec* embeddedFile(int);
    int getNumPages();
    struct Page* getPage(int);
};

struct Page {
    struct Annots* getAnnots();
};

struct Annots {
    int getNumAnnots();
    struct Annot* getAnnot(int);
};

struct Annot {
    enum AnnotType { typeFileAttachment };
    AnnotType getType();
    struct FileSpec* getFile();
};

struct AnnotFileAttachment : public Annot {
    struct FileSpec* getFile();
};

struct FileSpec {
    FileSpec(struct FileSpec*);
    ~FileSpec();
    const GooString* getFileName();
    struct EmbeddedFile* getEmbeddedFile();
};

struct EmbeddedFile {
    bool isOk();
    bool save(const char*);
};

struct GooList {
    GooList();
    ~GooList();
    void push_back(void*);
    int getLength();
    void* get(int);
};

struct PDFDocFactory {
    PDFDoc* createPDFDoc(const GooString&, GooString*, GooString*);
};

struct Win32Console {
    Win32Console(int*, char***);
};

extern GlobalParams* globalParams;
extern const char* PACKAGE_VERSION;
extern const char* popplerCopyright;
extern const char* xpdfCopyright;
extern const char* textEncName;
extern char ownerPassword[128];
extern char userPassword[128];
extern char savePath[1024];
extern bool doList;
extern bool saveAll;
extern int saveNum;
extern bool printVersion;
extern bool printHelp;
extern const char* argDesc[];
extern Unicode pdfDocEncoding[256];
extern int errConfig;
extern int errIO;
extern int errCommandLine;

bool parseArgs(const char* argDesc[], int* argc, char* argv[]);
void printUsage(const char* programName, const char* defaultArg, const char* argDesc[]);
void error(int category, int pos, const char* msg, ...);
template <class T> void deleteGooList(GooList* list);