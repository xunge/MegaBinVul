#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern void *limitMalloc(uint32_t size);
extern void _TIFFfree(void *ptr);
extern void *_TIFFrealloc(void *ptr, uint32_t size);
extern void _TIFFmemset(void *ptr, int val, uint32_t size);
extern void TIFFError(const char *module, const char *fmt, ...);