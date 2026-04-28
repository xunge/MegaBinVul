#include <stddef.h>

#define MagickFalse 0
#define MagickExport

typedef size_t MagickBooleanType;

MagickBooleanType CheckMemoryOverflow(const size_t, const size_t);
void *AcquireMagickMemory(const size_t);