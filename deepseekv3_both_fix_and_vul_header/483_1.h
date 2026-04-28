#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct FileStorage {
    char* (*bufferStart)(void);
    char* (*gets)(void);
    void (*setEof)(void);
    bool (*eof)(void);
} FileStorage;

extern FileStorage* fs;

#define cv_isprint(c) isprint(c)
#define CV_PARSE_ERROR_CPP(msg)