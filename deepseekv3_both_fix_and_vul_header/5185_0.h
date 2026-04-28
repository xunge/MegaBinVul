#include <stdio.h>
#include <stdlib.h>

typedef struct jpeg_compress_struct *j_compress_ptr;

#define LOCAL(type) static type
#define ERREXIT(cinfo,code) exit(1)
#define JERR_INPUT_EOF 1
#define JERR_PPM_NONNUMERIC 2
#define JERR_PPM_TOOLARGE 3

static int pbm_getc(FILE *infile) {
    return fgetc(infile);
}