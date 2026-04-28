#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;

#define GF_ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))
#define GF_LOG_DEBUG 0
#define GF_LOG_PARSER 0
#define GF_UTF8_FAIL (-1)

void GF_LOG(int level, int category, const char *fmt, ...);
char *gf_fgets(char *s, int size, FILE *stream);
int gf_fgetc(FILE *stream);
size_t gf_utf8_wcstombs(char *dest, size_t destSize, const unsigned short **src);