#include <stdio.h>
#include <stdlib.h>

#define SAFE_E(expr, val, msg) if ((expr) != (val)) { fprintf(stderr, "%s", msg); exit(EXIT_FAILURE); }