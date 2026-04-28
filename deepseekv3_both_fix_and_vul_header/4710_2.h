#include <math.h>
#include <stddef.h>

#define DEFAULT_SEPARATOR "."
#define IS_DIGIT_ZERO(c) ((c) == '0')
#define TRUE 1
#define FALSE 0

typedef struct _xsltFormatToken {
    char token;
    char *separator;
    int width;
} xsltFormatToken;

typedef struct _xsltFormat {
    char *start;
    char *end;
    int nTokens;
    xsltFormatToken *tokens;
} xsltFormat;

typedef struct _xsltNumberData {
    int digitsPerGroup;
    char *groupingCharacter;
    int groupingCharacterLen;
} xsltNumberData;

typedef struct _xmlBuffer {
    char *content;
    unsigned int use;
    unsigned int size;
} xmlBuffer;

typedef xsltFormatToken *xsltFormatTokenPtr;
typedef xsltFormat *xsltFormatPtr;
typedef xsltNumberData *xsltNumberDataPtr;
typedef xmlBuffer *xmlBufferPtr;

static xsltFormatToken default_token = {0};