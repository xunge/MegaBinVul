#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;

char *gf_fgets(char *str, int num, FILE *stream);
size_t gf_utf8_wcstombs(char *mbstr, size_t mbstr_size, const unsigned short **wcstr);

#define GPAC_BIG_ENDIAN