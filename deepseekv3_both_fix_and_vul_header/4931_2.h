#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdbool.h>

struct DCTStream {
    void reset();
};

struct Stream {
    void reset();
    int getChar();
};

struct jpeg_error_mgr {
    jmp_buf setjmp_buffer;
    bool abort;
};

struct jpeg_decompress_struct {
    int output_width;
    int output_components;
    struct {
        unsigned char** (*alloc_sarray)(void*, int, int, int);
    } *mem;
};

#define TRUE 1
#define FALSE 0
#define JPOOL_IMAGE 0

typedef void* j_common_ptr;

extern void jpeg_destroy_decompress(struct jpeg_decompress_struct*);
extern void jpeg_read_header(struct jpeg_decompress_struct*, bool);
extern bool jpeg_start_decompress(struct jpeg_decompress_struct*);
extern void error(int, const char*);
extern void init();

Stream* str;
struct jpeg_error_mgr src;
struct jpeg_decompress_struct cinfo;
unsigned char **row_buffer;