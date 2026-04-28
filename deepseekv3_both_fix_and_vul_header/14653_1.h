#include <stddef.h>

#define MagickFalse 0
#define MagickExport

void *RelinquishMagickMemory(void *);
void *ResizeMagickMemory(void *, size_t);
int CheckMemoryOverflow(size_t, size_t);