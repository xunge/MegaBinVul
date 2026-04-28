#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define CV_PARSE_ERROR_CPP(msg) 
#define CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP() 

struct FileNode {
    enum {
        STRING,
        REAL,
        INT,
        FLOW,
        SEQ
    };
    void setValue(int type, const void* value, size_t len = 0) {}
    struct {
        void* seq;
    }* data;
};

struct FileStorage {
    char* gets();
    double strtod(const char* nptr, char** endptr);
};

#define cv_isalnum(c) isalnum((unsigned char)c)
#define cv_isdigit(c) isdigit((unsigned char)c)
#define cv_isalpha(c) isalpha((unsigned char)c)

char* skipSpaces(char* ptr) {
    return ptr;
}

char buf[1024];
FileStorage* fs;