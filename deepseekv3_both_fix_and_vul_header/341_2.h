#include <stddef.h>

#define DEFAULT_TOKEN 0
#define DEFAULT_SEPARATOR "."
#define MAX_TOKENS 10

#define IS_LETTER(val) (0)
#define IS_DIGIT(val) (0)
#define IS_DIGIT_ONE(val) (0)
#define IS_DIGIT_ZERO(val) (0)

typedef unsigned char xmlChar;

typedef struct {
    int token;
    int width;
    xmlChar *separator;
} xsltFormatToken;

typedef struct {
    xmlChar *start;
    xsltFormatToken tokens[MAX_TOKENS];
    int nTokens;
    xmlChar *end;
} xsltFormat;

typedef xsltFormat* xsltFormatPtr;

static xsltFormatToken default_token;

static int xmlStringCurrentChar(void *context, const xmlChar *str, int *len) {
    return 0;
}

static xmlChar *xmlStrndup(const xmlChar *str, int len) {
    return NULL;
}

#define BAD_CAST (xmlChar *)