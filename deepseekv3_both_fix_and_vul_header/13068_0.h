#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

typedef unsigned char u_char;

char *safe_strdup(const char *s);
void safe_free(void *ptr);
void dbgx(int level, const char *fmt, ...);