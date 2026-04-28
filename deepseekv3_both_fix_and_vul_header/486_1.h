#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cassert>

#define CV_XML_DIRECTIVE_TAG 0
#define CV_XML_EMPTY_TAG 1
#define CV_XML_OPENING_TAG 2
#define CV_XML_CLOSING_TAG 3
#define CV_FS_MAX_LEN 1024

#define CV_Assert(expr) assert(expr)

class FileNode {
public:
    enum {
        NONE,
        INT,
        REAL,
        STRING,
        MAP,
        SEQ
    };
    
    int type() const { return 0; }
    void setValue(int, void*) {}
    void setValue(int, const char*, int) {}
};

char* skipSpaces(char*, int);
char* parseTag(char*, std::string&, std::string&, int&);
void CV_PARSE_ERROR_CPP(const char*);
void CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP();

#define cv_isspace(c) isspace((unsigned char)c)
#define cv_isdigit(c) isdigit((unsigned char)c)
#define cv_isalnum(c) isalnum((unsigned char)c)
#define cv_isprint(c) isprint((unsigned char)c)

char strbuf[CV_FS_MAX_LEN];

struct FileStorage {
    FileNode addNode(FileNode&, const std::string&, int, int) { return FileNode(); }
    void convertToCollection(int, FileNode&) {}
    char* parseBase64(char*, int, FileNode&) { return nullptr; }
    double strtod(const char*, char**) { return 0.0; }
    void finalizeCollection(FileNode&) {}
};

FileStorage* fs;