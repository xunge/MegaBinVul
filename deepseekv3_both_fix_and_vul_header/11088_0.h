#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>

#define CV_PARSE_ERROR_CPP(msg) 
#define CV_Assert(expr) 
#define CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP() 
#define CV_XML_DIRECTIVE_TAG 0
#define CV_XML_EMPTY_TAG 1
#define CV_XML_OPENING_TAG 2
#define CV_XML_CLOSING_TAG 3
#define CV_FS_MAX_LEN 1024

class FileNode {
public:
    enum {
        NONE,
        INT,
        REAL,
        STRING,
        SEQ,
        MAP
    };
    
    int type() const { return 0; }
    void setValue(int type, const void* value) {}
    void setValue(int type, const char* str, int len) {}
};

class FileStorage {
public:
    FileNode addNode(FileNode& node, const std::string& key, int type, int flags) { return FileNode(); }
    void convertToCollection(int type, FileNode& node) {}
    char* parseBase64(char* ptr, int flags, FileNode& node) { return ptr; }
    double strtod(const char* str, char** endptr) { return 0.0; }
    void finalizeCollection(FileNode& node) {}
};

extern FileStorage* fs;
extern char strbuf[CV_FS_MAX_LEN];

inline bool cv_isspace(char c) { return std::isspace(c); }
inline bool cv_isdigit(char c) { return std::isdigit(c); }
inline bool cv_isalnum(char c) { return std::isalnum(c); }
inline bool cv_isprint(char c) { return std::isprint(c); }

char* skipSpaces(char* ptr, int flags) { return ptr; }
char* parseTag(char* ptr, std::string& key, std::string& type_name, int& tag_type) { return ptr; }