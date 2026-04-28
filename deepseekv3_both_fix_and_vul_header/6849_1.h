#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define SEL_VERSION_NUMBER 1

typedef int l_int32;

typedef struct Sel {
    l_int32 sy;
    l_int32 sx;
    l_int32 cy;
    l_int32 cx;
    char *name;
    l_int32 **data;
} SEL;

#define ERROR_PTR(msg, proc, ret) NULL
#define PROCNAME(name)
#define LEPT_FREE(ptr) free(ptr)

static char *stringNew(const char *str) {
    char *newstr = malloc(strlen(str) + 1);
    if (newstr) strcpy(newstr, str);
    return newstr;
}

SEL *selCreate(l_int32 sy, l_int32 sx, char *name) {
    SEL *sel = malloc(sizeof(SEL));
    if (!sel) return NULL;
    
    sel->sy = sy;
    sel->sx = sx;
    sel->name = name ? stringNew(name) : NULL;
    
    sel->data = malloc(sy * sizeof(l_int32 *));
    for (l_int32 i = 0; i < sy; i++) {
        sel->data[i] = calloc(sx, sizeof(l_int32));
    }
    
    return sel;
}

void selSetOrigin(SEL *sel, l_int32 cy, l_int32 cx) {
    if (sel) {
        sel->cy = cy;
        sel->cx = cx;
    }
}