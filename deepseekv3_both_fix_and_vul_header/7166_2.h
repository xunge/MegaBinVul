#include <stdio.h>

struct LibRaw_bigfile_datastream {
    FILE *f;
    char *gets(char *str, int sz);
};

#define LR_BF_CHK()