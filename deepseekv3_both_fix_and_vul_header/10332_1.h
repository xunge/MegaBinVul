#include <stdlib.h>
#include <errno.h>

#define CACHE_LINE_SIZE 64
#define MagickFalse 0

typedef int MagickBooleanType;

MagickBooleanType CheckMemoryOverflow(const size_t count, const size_t quantum);

#define MagickExport