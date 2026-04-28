#include <stdio.h>
#include <string.h>

typedef struct s_fli_header {
    unsigned short width;
    unsigned short height;
} s_fli_header;

unsigned short fli_read_short(FILE *f);
unsigned char fli_read_char(FILE *f);