#include <stddef.h>

typedef struct Proto {
    int *lineinfo;
} Proto;

int luaG_getfuncline(const Proto *p, int pc);