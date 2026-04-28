#include <stdio.h>

typedef unsigned char uchar;

extern int gif_get_code(FILE *fp, int code_size, int first_time);
extern int gif_get_block(FILE *fp, uchar buf[260]);
extern int gif_eof;