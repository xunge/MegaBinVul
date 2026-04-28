#include <stddef.h>
#include <stdint.h>
#include <ctype.h>

typedef ptrdiff_t OFF;
typedef size_t SZ;

#define FALSE 0
#define TRUE 1

#define _T(c) c
#define CH(off) ctx->text[off]
#define ISNEWLINE(off) (CH(off) == '\n' || CH(off) == '\r')
#define ISPUNCT(off) ispunct(CH(off))
#define ISUNICODEWHITESPACE_(c) (c == 0x20 || c == 0x09 || c == 0x0A || c == 0x0D || c == 0x0C || c == 0x0B)

typedef struct {
    OFF beg;
    OFF end;
} MD_LINE;

typedef struct {
    const char* text;
    SZ size;
} MD_CTX;

static int md_decode_unicode(const char* text, OFF off, SZ size, SZ* char_size);