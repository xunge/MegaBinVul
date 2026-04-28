#include <cctype>
#include <cstring>
#include <cstdlib>

#define CV_PARSE_ERROR_CPP(msg) 
#define CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP() 
#define CV_FS_MAX_LEN 1024

struct FileNode {
    enum {
        NONE = 0,
        INT = 1,
        REAL = 2,
        STRING = 3,
        SEQ = 4,
        MAP = 5,
        FLOW = 6
    };
    
    void setValue(int type, const void* value, size_t len = 0) {}
};

struct FileStorage {
    char* gets();
    double strtod(const char* beg, char** end);
};

inline bool cv_isalnum(char c) { return std::isalnum(c); }
inline bool cv_isdigit(char c) { return std::isdigit(c); }
inline bool cv_isalpha(char c) { return std::isalpha(c); }
inline char* skipSpaces(char* ptr) { return ptr; }

char buf[CV_FS_MAX_LEN];
FileStorage* fs;