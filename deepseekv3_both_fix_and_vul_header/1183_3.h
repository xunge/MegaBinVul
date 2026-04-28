#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef int XML_Bool;
typedef unsigned short XML_Char;

typedef struct {
    XML_Char *str;
    XML_Char *localPart;
    int strLen;
} TAG_NAME;

typedef struct TAG {
    TAG_NAME name;
    char *buf;
    char *bufEnd;
    char *rawName;
    size_t rawNameLength;
    struct TAG *parent;
} TAG;

typedef struct XML_Parser {
    TAG *m_tagStack;
} *XML_Parser;

#define XML_FALSE 0
#define XML_TRUE 1
#define ROUND_UP(n, size) (((n) + (size) - 1) & ~((size) - 1))
#define REALLOC(parser, ptr, size) realloc(ptr, size)