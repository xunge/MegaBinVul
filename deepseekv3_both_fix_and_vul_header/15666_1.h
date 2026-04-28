#include <stddef.h>

typedef struct optset_T {
    void *os_varp;
    char *os_errbuf;
    size_t os_errbuflen;
} optset_T;

typedef char char_u;

#define SHM_ALL 0

char *did_set_option_listflag(char_u *varp, char_u *flag, char *errbuf, ...);