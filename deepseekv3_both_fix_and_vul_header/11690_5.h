#include <stdio.h>
#include <string.h>

typedef unsigned int Unicode;

class GooString {
public:
    GooString(const char *str);
    ~GooString();
    char getChar(int pos) const;
    int getLength() const;
};

class UnicodeMap {
public:
    int mapUnicode(Unicode u, char *buf, int bufSize);
    void decRefCnt();
};

class GlobalParams {
public:
    GlobalParams();
    ~GlobalParams();
    void setTextEncoding(const char *encoding);
    UnicodeMap *getTextEncoding();
};

class Win32Console {
public:
    Win32Console(int *argc, char ***argv);
};

class GooList {
public:
    GooList();
    ~GooList();
    void push_back(void *item);
    void *get(int index);
    int getLength();
};

class PDFDoc {
public:
    bool isOk();
    class Catalog* getCatalog();
};

class Catalog {
public:
    int numEmbeddedFiles();
    void* embeddedFile(int i);
    int getNumPages();
    class Page* getPage(int pageNum);
};

class FileSpec {
public:
    FileSpec(void *file);
    const GooString* getFileName();
    class EmbeddedFile* getEmbeddedFile();
};

class EmbeddedFile {
public:
    bool isOk();
    bool save(const char *path);
};

class Page {
public:
    class Annots* getAnnots();
};

class Annots {
public:
    int getNumAnnots();
    class Annot* getAnnot(int index);
};

class Annot {
public:
    enum Type { typeFileAttachment };
    Type getType();
};

class AnnotFileAttachment : public Annot {
public:
    void* getFile();
};

class PDFDocFactory {
public:
    PDFDoc* createPDFDoc(const GooString &fileName, GooString *ownerPW, GooString *userPW);
};

struct ArgDesc {
    const char *arg;
    const char *desc;
    int type;
    void *val;
};

extern ArgDesc *argDesc;
extern bool doList;
extern int saveNum;
extern bool saveAll;
extern bool printVersion;
extern bool printHelp;
extern char textEncName[128];
extern char ownerPassword[128];
extern char userPassword[128];
extern char savePath[1024];
extern const char *PACKAGE_VERSION;
extern const char *popplerCopyright;
extern const char *xpdfCopyright;
extern const Unicode pdfDocEncoding[256];
extern GlobalParams *globalParams;

enum ErrorType {
    errConfig,
    errCommandLine,
    errIO
};

bool parseArgs(ArgDesc *argDesc, int *argc, char **argv);
void error(ErrorType errCode, int pos, const char *msg, ...);
void printUsage(const char *programName, const char *defaultName, ArgDesc *argDesc);
template <class T> void deleteGooList(GooList *list);