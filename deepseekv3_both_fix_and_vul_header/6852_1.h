#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define GPLOT_VERSION_NUMBER 1

typedef int l_int32;

typedef struct GPLOT {
    char *cmdname;
    char *outname;
    void *cmddata;
    void *datanames;
    void *plotdata;
    void *plottitles;
    void *plotstyles;
    l_int32 nplots;
    l_int32 scaling;
} GPLOT;

#define PROCNAME(name)
#define ERROR_PTR(msg, proc, ret) NULL
#define LEPT_FREE(ptr) free(ptr)

char *stringNew(const char *src);
void stringReplace(char **pdest, const char *src);
GPLOT *gplotCreate(char *rootname, l_int32 outformat, char *title, char *xlabel, char *ylabel);
void sarrayDestroy(void **parray);
void numaDestroy(void **pnuma);
void *sarrayReadStream(FILE *fp);
void *numaReadStream(FILE *fp);
FILE *fopenReadStream(const char *filename);