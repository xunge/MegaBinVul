#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pnm_header {
    int format;
    int width;
    int height;
    int depth;
    int maxval;
    int bw;
    int gray;
    int graya;
    int rgb;
    int rgba;
    int ok;
};

char *skip_idf(char *s, char *idf);
char *skip_int(char *s, int *x);