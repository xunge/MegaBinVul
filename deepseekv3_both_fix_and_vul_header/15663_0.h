#include <stddef.h>

typedef struct optset {
    void *os_varp;
    char *os_errbuf;
    size_t os_errbuflen;
} optset_T;

typedef char char_u;

#define MOUSE_ALL ""