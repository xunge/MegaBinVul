#include <stdio.h>
#include <string.h>

typedef unsigned char char_u;

#define NUL '\0'
#define _(x) x

typedef struct optset_T {
    char_u **os_varp;
    char_u *os_errbuf;
    size_t os_errbuflen;
} optset_T;

extern char *illegal_char(char_u *errbuf, ...);
extern char_u *vim_strchr(char_u *str, int c);
extern const char e_illegal_character_after_chr[];