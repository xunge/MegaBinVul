#include <stddef.h>

typedef unsigned char char_u;

static char *illegal_char_with_len(char *errbuf, int errbuflen, char_u c);
static char *illegal_char_no_len(char *errbuf, char_u c);
static char_u *vim_strchr(char_u *str, int c);