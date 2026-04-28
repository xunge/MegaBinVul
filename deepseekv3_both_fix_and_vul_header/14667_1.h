#include <stdlib.h>
#include <stddef.h>

#define MagickExport
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

extern MagickBooleanType CheckMemoryOverflow(size_t, size_t);
extern void *RelinquishMagickMemory(void *);
extern void *ResizeMagickMemory(void *, size_t);