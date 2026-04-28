#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <stdexcept>
#include <climits>

class FileNode {
public:
    enum {
        NONE,
        INT,
        REAL,
        STRING,
        SEQ,
        MAP,
        USER
    };

    void setValue(int type, const void* value);
    void setValue(int type, const char* str, int len);
};

class FileStorage {
public:
    char* bufferStart();
    char* parseBase64(char* ptr, int indent, FileNode& node);
    double strtod(const char* str, char** endptr);
    void convertToCollection(int type, FileNode& node);
    FileNode addNode(FileNode& parent, const std::string& name, int type);
    void finalizeCollection(FileNode& node);
};

extern FileStorage* fs;

#define CV_FS_MAX_LEN 1024
#define CV_PARSE_ERROR_CPP(msg) throw std::runtime_error(msg)
#define CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP()

char buf[CV_FS_MAX_LEN];

inline bool cv_isprint(char c) { return isprint(c); }
inline bool cv_isdigit(char c) { return isdigit(c); }
inline bool cv_isalnum(char c) { return isalnum(c); }

char* skipSpaces(char* ptr, int min_indent, int max_indent);
char* parseKey(char* ptr, FileNode& node, FileNode& elem);