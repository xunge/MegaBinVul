#include <stdio.h>
#include <setjmp.h>

struct DCTStream {
    struct {
        jmp_buf setjmp_buffer;
        int abort;
    } src;

    struct {
        int output_scanline;
        int output_height;
        int output_width;
        int output_components;
    } cinfo;

    unsigned char row_buffer[1][1];
    unsigned char *current;
    unsigned char *limit;

    int getChar();
};

int jpeg_read_scanlines(void *cinfo, unsigned char buffer[1][1], int lines);