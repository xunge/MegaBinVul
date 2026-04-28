#include <stddef.h>

typedef unsigned char char_u;
#define NUL '\0'

extern int has_mbyte;
extern int (*mb_ptr2len)(char_u *);
extern char_u *vim_strchr(const char_u *str, int c);