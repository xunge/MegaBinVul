#include <stddef.h>
#include <errno.h>

#define MagickExport
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

extern MagickBooleanType CheckMemoryOverflow(const size_t, const size_t);
extern void *AcquireMagickMemory(size_t);