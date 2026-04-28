#include <stdio.h>

typedef int boolean;
#define FALSE 0
#define TRUE 1

struct jpeg_source_mgr {
    unsigned char *next_input_byte;
    size_t bytes_in_buffer;
};

struct str_stream {
    int (*getChar)(void);
};

struct str_src_mgr {
    struct jpeg_source_mgr pub;
    boolean abort;
    int index;
    struct str_stream *str;
    unsigned char buffer;
};

struct jpeg_decompress_struct {
    struct str_src_mgr *src;
};

typedef struct jpeg_decompress_struct *j_decompress_ptr;