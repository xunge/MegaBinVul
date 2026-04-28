#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define kMAXPATHLEN 1024
#define kErrFatal 1
#define ErrFatal 1
#define ErrSys 2

extern const char *shellMeta;
extern const char *shellStuff;
extern const char *shellEscape;

extern int RootdExpandFileName(const char *name, char *xname, int size);
extern void Error(int errType, int errCode, const char *fmt, ...);
extern const char *HomeDirectory(const char *uname);
extern void EscChar(const char *src, char *dst, int size, const char *stuff, const char *escape);

static inline size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t len = strlen(src);
    if (size) {
        size_t n = len < size-1 ? len : size-1;
        memcpy(dst, src, n);
        dst[n] = '\0';
    }
    return len;
}