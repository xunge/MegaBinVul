#include <stdlib.h>
#include <stddef.h>

#define CACHE_LINE_SIZE 64
#define MagickFalse 0
#define MagickExport
#define MAGICKCORE_HAVE_POSIX_MEMALIGN 1

int CheckMemoryOverflow(const size_t count, const size_t quantum);