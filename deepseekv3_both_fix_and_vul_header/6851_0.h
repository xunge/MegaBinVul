#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define L_COPY 1
#define L_NOCOPY 0
#define ERROR_INT(msg, procName, val) val
#define PROCNAME(name)
#define LEPT_FREE(ptr) free(ptr)

typedef int l_int32;

enum {
    GPLOT_PNG,
    GPLOT_PS,
    GPLOT_EPS,
    GPLOT_LATEX
};

enum {
    GPLOT_LOG_SCALE_X,
    GPLOT_LOG_SCALE_Y,
    GPLOT_LOG_SCALE_X_Y
};

typedef struct {
    char *title;
    char *xlabel;
    char *ylabel;
    char *outname;
    char *cmdname;
    l_int32 outformat;
    l_int32 scaling;
    void *cmddata;
    void *datanames;
    void *plottitles;
    void *plotstyles;
} GPLOT;

extern const char *gplotstylenames[];

void *sarrayGetString(void *array, l_int32 index, l_int32 flag);
l_int32 sarrayGetCount(void *array);
void sarrayAddString(void *array, const char *str, l_int32 copy);
void sarrayClear(void *array);
char *sarrayToString(void *array, l_int32 addnewlines);
FILE *fopenWriteStream(const char *filename, const char *mode);
l_int32 numaGetIValue(void *numa, l_int32 index, l_int32 *pval);