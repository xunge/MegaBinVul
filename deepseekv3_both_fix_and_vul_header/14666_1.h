#include <stdlib.h>

#define CACHE_LINE_SIZE 64
#define MagickFalse 0

typedef int MagickBooleanType;

#define MagickExport

MagickBooleanType CheckMemoryOverflow(const size_t, const size_t);