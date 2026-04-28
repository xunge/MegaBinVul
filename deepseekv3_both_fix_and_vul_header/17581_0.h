#include <ctype.h>
#include <stddef.h>

#ifndef CHARSET_EBCDIC
static unsigned char php_htoi(char *s);
#else
extern unsigned char os_toebcdic[256];
static unsigned char php_htoi(char *s);
#endif

#define PHPAPI