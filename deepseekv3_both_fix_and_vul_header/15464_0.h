#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

typedef unsigned int UI32;

typedef struct SWF_GLYPHENTRY {
    UI32 *GlyphIndex;
    UI32 *GlyphAdvance;
} SWF_GLYPHENTRY;

extern UI32 readBits(FILE *f, int bits);
extern void SWF_error(const char *msg);