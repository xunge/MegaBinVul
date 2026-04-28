#include <ctype.h>
#include <stddef.h>

struct QuotedString {
    char *extractFrom(char *input, char **endPtr);
};

static int isQuote(char c) {
    return c == '\'' || c == '\"';
}

static char unescapeChar(char c) {
    switch (c) {
        case 'n': return '\n';
        case 't': return '\t';
        case 'r': return '\r';
        case '0': return '\0';
        default: return c;
    }
}