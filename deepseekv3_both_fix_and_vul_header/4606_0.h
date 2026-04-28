#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PHPAPI
#define safe_emalloc(nmemb, size, offset) malloc((nmemb) * (size) + (offset))
#define CHARSET_EBCDIC 0
static const char hexchars[] = "0123456789ABCDEF";
#ifdef CHARSET_EBCDIC
static const unsigned char os_toascii[256];
#endif