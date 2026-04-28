#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOFT_SIZE 0
#define RECORD_HEADER_SIZE 0

struct file_header {
    int rec_size;
    int rec_types_nr;
};

struct record_header;

extern int rec_types_nr;
extern int sa_fread(int, void*, size_t, int, int);
extern void remap_struct(int, int, void*, size_t, size_t, ...);
extern void swap_struct(int, struct record_header*, int);