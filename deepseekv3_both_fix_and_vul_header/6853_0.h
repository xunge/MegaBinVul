#include <stdio.h>
#include <stdlib.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define ERROR_INT(msg, proc, val) (val)
#define LEPT_FREE(p) free(p)
#define _WIN32
#define OS_IOS

typedef int l_int32;

typedef struct GPLOT {
    char *cmdname;
} GPLOT;

#define PROCNAME(name)
#define genPathname(a, b) strdup(a)
#define gplotGenCommandFile(gplot)
#define gplotGenDataFiles(gplot)