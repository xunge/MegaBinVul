#include <string.h>
#include <stdlib.h>

typedef struct _StringInfo StringInfo;

typedef signed long ssize_t;

#define PSDQuantum(count) (count)

#define MSBEndian 1

static void *CopyMagickMemory(void *dest, const void *src, size_t n);
static int LocaleNCompare(const char *s1, const char *s2, size_t n);
static const unsigned char *PushLongPixel(unsigned int endian, const unsigned char *p, unsigned int *quantum);
static const unsigned char *PushShortPixel(unsigned int endian, const unsigned char *p, unsigned short *quantum);
static unsigned char *GetStringInfoDatum(StringInfo *string_info);
static size_t GetStringInfoLength(const StringInfo *string_info);
static void SetStringInfoLength(StringInfo *string_info, size_t length);