#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;

#define GPAC_BIG_ENDIAN 0
#define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))

extern size_t gf_utf8_wcstombs(char *dest, size_t dest_size, const unsigned short **src);