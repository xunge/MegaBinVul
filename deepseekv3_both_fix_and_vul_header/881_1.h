#include <stdlib.h>
#include <stddef.h>

#define nullptr NULL

static int CanAlloc(size_t size) { return size > 0; }