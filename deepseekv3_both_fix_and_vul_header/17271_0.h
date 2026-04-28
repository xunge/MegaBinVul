#include <stdint.h>

#define MAXSTRING 256
#define MAXBYTES 4
#define CHARSIZE 2
#define ENDSEGMENT 0xffff
#define QUOTESUB 0x0022

typedef uint16_t widechar;

typedef struct {
    widechar chars[MAXSTRING];
    int length;
} CharsString;

typedef struct {
    int dummy;
} FileInfo;

extern int hexValue(FileInfo *nested, widechar *chars, int length);
extern void compileError(FileInfo *nested, const char *format, ...);
extern void compileWarning(FileInfo *nested, const char *format, ...);

static const unsigned char first0Bit[] = {0x80, 0x20, 0x10, 0x08};