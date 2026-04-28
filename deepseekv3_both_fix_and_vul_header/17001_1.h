#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int jsval;

extern int _debug();
extern void print_error(const char *format, ...);
extern char* str_replace(const char *str, const char *old, const char *new);
extern void* cx;
extern void* global;
extern int JS_EvaluateScript(void *cx, void *obj, const char *bytes, size_t length, const char *filename, unsigned lineno, jsval *rval);
extern void* JS_ValueToString(void *cx, jsval v);
extern char* JS_GetStringBytes(void *string);