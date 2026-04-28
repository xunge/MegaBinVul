#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int pdf_major_version;
    int pdf_minor_version;
} pdf_t;

char *get_header(FILE *fp);