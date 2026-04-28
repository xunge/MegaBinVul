#include <stddef.h>

#define char_u unsigned char
#define NUL '\0'
#define MB_BYTE2LEN(c) ((c) < 0x80 ? 1 : 2)