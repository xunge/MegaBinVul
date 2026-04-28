#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned short height;
    unsigned short width;
} s_fli_header;

unsigned char fli_read_char(FILE *f);