#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
    char ty;
} spiro_cp;

typedef struct {
    spiro_cp *spiros;
    int spiro_cnt;
    int spiro_max;
} SplineSet;

#define SPIRO_END 0x7f

int nlgetc(FILE *sfd);