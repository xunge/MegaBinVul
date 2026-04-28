#include <stddef.h>
#include <stdint.h>
#include <ctype.h>

typedef ptrdiff_t OFF;
typedef size_t SZ;

#define FALSE 0
#define TRUE 1

#define _T(c) c
#define CH(off) ctx->text[off]
#define ISPUNCT(off) ispunct(CH(off))
#define ISNEWLINE(off) (CH(off) == '\n' || CH(off) == '\r')
#define ISUNICODEWHITESPACE_(codepoint) (codepoint == ' ' || codepoint == '\t' || codepoint == '\n' || codepoint == '\r' || codepoint == '\f' || codepoint == '\v')

typedef struct {
    const char* text;
    SZ size;
} MD_CTX;

typedef struct {
    OFF beg;
    OFF end;
} MD_LINE;

int md_decode_unicode(const char* text, OFF off, SZ size, SZ* char_size);