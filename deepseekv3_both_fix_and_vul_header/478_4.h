#include <stdbool.h>
#include <ctype.h>

typedef struct FileStorage FileStorage;

struct FileStorage {
    char* (*gets)(void);
    char* (*bufferStart)(void);
    void (*setEof)(void);
};

#define cv_isprint(c) isprint(c)
#define CV_PARSE_ERROR_CPP(msg) 

extern FileStorage* fs;