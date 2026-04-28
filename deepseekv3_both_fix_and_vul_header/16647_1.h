#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SEL_VERSION_NUMBER 1
#define ERROR_PTR(msg, proc, ret) NULL
#define PROCNAME(name)
#define LEPT_FREE(ptr) free(ptr)

typedef int32_t l_int32;

typedef struct {
    int **data;
    char *name;
    l_int32 sy;
    l_int32 sx;
    l_int32 cy;
    l_int32 cx;
} SEL;

SEL *selCreate(l_int32 sy, l_int32 sx, char *name);
void selSetOrigin(SEL *sel, l_int32 cy, l_int32 cx);
char *stringNew(const char *str);