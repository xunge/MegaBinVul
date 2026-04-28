#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;

#define GF_ARRAY_LENGTH(arr) (sizeof(arr)/sizeof((arr)[0]))
#define GF_LOG_DEBUG 0
#define GF_LOG_PARSER 0
#define GF_UTF8_FAIL (-1)
#define GPAC_BIG_ENDIAN 0

extern char *gf_fgets(char *s, int size, FILE *stream);
extern int gf_fgetc(FILE *stream);
extern int gf_utf8_wcstombs(char *dest, int dest_size, const unsigned short **src);
extern void GF_LOG(int level, int category, const char *format, ...);