#include <stdio.h>
#include <stdarg.h>

typedef unsigned int JSONFlags;
#define JSON_INDENT 1

typedef int (*vcbprintf_callback)(void *, const char *, ...);
int cbprintf(vcbprintf_callback callback, void *data, const char *format, ...);