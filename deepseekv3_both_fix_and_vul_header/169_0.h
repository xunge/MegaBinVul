#include <stdio.h>
#include <ctype.h>

#define NSVG_RGB(r, g, b) (((unsigned int)(r) << 16) | ((unsigned int)(g) << 8) | (unsigned int)(b))

static int nsvg__isspace(char c) { return isspace(c); }