#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define ALLOC_MOD_SIZE 16
#define MAX_ARRAY_LIST 1024

typedef struct Jsi_Value Jsi_Value;

typedef struct Jsi_Interp {
    uint maxArrayList;
} Jsi_Interp;

typedef struct Jsi_Obj {
    int isarrlist;
    uint arrMaxSize;
    uint arrCnt;
    Jsi_Value **arr;
} Jsi_Obj;

void Jsi_LogError(const char *fmt, ...);