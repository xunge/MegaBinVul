#include <ctype.h>
#include <stddef.h>

#define PHPAPI

#ifndef CHARSET_EBCDIC
static unsigned char php_htoi(char *s)
{
    unsigned char value = 0;
    int c = tolower((unsigned char)*s++);
    if (c >= '0' && c <= '9')
        value = (c - '0');
    else if (c >= 'a' && c <= 'f')
        value = (c - 'a' + 10);
    c = tolower((unsigned char)*s);
    value *= 16;
    if (c >= '0' && c <= '9')
        value += (c - '0');
    else if (c >= 'a' && c <= 'f')
        value += (c - 'a' + 10);
    return value;
}
#else
extern unsigned char os_toebcdic[];
#endif