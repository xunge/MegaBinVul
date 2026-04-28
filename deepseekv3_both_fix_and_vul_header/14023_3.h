#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define UL_CLOEXECSTR "e"

extern int xmkstemp(char **tmpname, const char *dir, ...);