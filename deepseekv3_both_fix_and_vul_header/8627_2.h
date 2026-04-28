#include <stdint.h>
#include <string.h>

#define _TIFFmemcpy memcpy

typedef uint16_t uint16;
typedef uint32_t uint32; 
typedef uint8_t uint8;

void TIFFError(const char* module, const char* fmt, ...);