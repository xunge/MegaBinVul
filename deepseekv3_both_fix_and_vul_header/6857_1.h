#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int l_int32;
typedef float l_float32;

#define ERROR_PTR(msg, proc, ret) NULL
#define PROCNAME(name)
#define PTA_VERSION_NUMBER 0

typedef struct PTA PTA;

PTA *ptaCreate(int n);
void ptaDestroy(PTA **pta);
int ptaAddPt(PTA *pta, l_float32 x, l_float32 y);
int ptaAddPtInt(PTA *pta, l_int32 x, l_int32 y);