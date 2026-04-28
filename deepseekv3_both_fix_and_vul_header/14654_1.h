#include <stddef.h>

#define MagickExport
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

extern MagickBooleanType CheckMemoryOverflow(size_t, size_t);
extern void *AcquireMagickMemory(size_t);