#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512

#define GPLOT_PNG 1
#define GPLOT_PS 2
#define GPLOT_EPS 3
#define GPLOT_LATEX 4

#define ERROR_PTR(msg, proc, ret) NULL
#define LEPT_CALLOC(n, size) calloc(n, size)
#define PROCNAME(name)

typedef int l_int32;

typedef struct Sarray SARRAY;
typedef struct Numa NUMA;

typedef struct {
    char *rootname;
    l_int32 outformat;
    char *cmdname;
    char *outname;
    char *title;
    char *xlabel;
    char *ylabel;
    SARRAY *cmddata;
    SARRAY *datanames;
    SARRAY *plotdata;
    SARRAY *plottitles;
    NUMA *plotstyles;
} GPLOT;

SARRAY *sarrayCreate(int size);
NUMA *numaCreate(int size);
char *genPathname(const char *path, const char *root);
char *stringNew(const char *str);
void stringCheckForChars(const char *str, const char *chars, l_int32 *pbadchar);