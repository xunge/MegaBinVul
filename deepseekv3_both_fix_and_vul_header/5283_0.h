#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned int u32;

typedef struct {
    char *svg_data;
    u32 svg_data_size;
    int print_frame_header;
    u32 frame_header_offset;
} SWFReader;

void *gf_realloc(void *ptr, size_t size);