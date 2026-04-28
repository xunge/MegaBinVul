#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define ERROR_INT(msg, procName, val) val
#define L_INFO(msg, procName)
#define NUM_GPLOT_STYLES 10
#define GPLOT_LINES 0
#define GPLOT_POINTS 1
#define L_INSERT 1
#define L_COPY 2

typedef int l_int32;
typedef float l_float32;

typedef struct {
    l_int32 nplots;
    char *rootname;
    void *plotstyles;
    void *plottitles;
    void *datanames;
    void *plotdata;
} GPLOT;

typedef struct {
    int dummy;
} NUMA;

typedef struct {
    int dummy;
} SARRAY;

#define PROCNAME(name) static const char *procName = name

char *stringNew(const char *str);
void numaGetParameters(NUMA *n, l_float32 *startx, l_float32 *delx);
l_int32 numaGetCount(NUMA *n);
void numaGetFValue(NUMA *n, l_int32 index, l_float32 *val);
void numaAddNumber(void *n, l_int32 val);
SARRAY *sarrayCreate(l_int32 n);
void sarrayAddString(void *sa, char *str, l_int32 copyflag);
char *sarrayToString(SARRAY *sa, l_int32 addnewline);
void sarrayDestroy(SARRAY **psa);