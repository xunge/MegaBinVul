#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef double real;

struct ttfinfo {
    bool bad_cff;
};

extern char *addnibble(char *pt, int nibble);
extern void LogError(const char *fmt, ...);