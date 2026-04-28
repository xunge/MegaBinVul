#include <stddef.h>

typedef unsigned char char_u;
#define CPO_ALL 0

typedef struct optset_T {
    void *os_varp;
    char *os_errbuf;
    size_t os_errbuflen;
} optset_T;

char *did_set_option_listflag(char_u *varp, char_u *cpo_all, char *errbuf, ...);