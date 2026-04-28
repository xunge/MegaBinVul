#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TAB '\t'

typedef struct erow {
    char *chars;
    char *render;
    int size;
    int rsize;
} erow;

void editorUpdateSyntax(erow *row);