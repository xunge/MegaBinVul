#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define cv_isprint isprint

struct FileStorage {
    char* bufferStart();
};

extern FileStorage* fs;
extern char* skipSpaces(char* ptr, int a, int b);
extern void CV_PARSE_ERROR_CPP(const char* msg);