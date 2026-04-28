#include <stddef.h>
#include <sys/types.h>

#define TAG_FMT_SBYTE 1
#define TAG_FMT_BYTE 2
#define TAG_FMT_USHORT 3
#define TAG_FMT_ULONG 4
#define TAG_FMT_URATIONAL 5
#define TAG_FMT_SRATIONAL 6
#define TAG_FMT_SSHORT 7
#define TAG_FMT_SLONG 8
#define TAG_FMT_SINGLE 9
#define TAG_FMT_DOUBLE 10

typedef unsigned char uchar;

#define TSRMLS_DC
#define TSRMLS_CC
#define EXIF_DEBUG
#define E_NOTICE 8

unsigned short php_ifd_get16u(void *value, int motorola_intel);
unsigned php_ifd_get32u(void *value, int motorola_intel);
int php_ifd_get32s(void *value, int motorola_intel);
void php_error_docref(const char *docref, int type, const char *format, ...);