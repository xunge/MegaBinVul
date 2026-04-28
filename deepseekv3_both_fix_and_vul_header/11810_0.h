#include <ctype.h>
#include <stddef.h>

typedef enum {
    TT_EOF,
    TT_WORD,
    TT_NUMBER,
    TT_SPECIAL
} x86newTokenType;

typedef unsigned char ut8;