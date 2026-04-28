#include <stdio.h>
#include <stdlib.h>

typedef int code_int;
typedef char char_type;
typedef char BufChar;

#define BUFFILESIZE 1024
#define STACK_SIZE 10000
#define CLEAR 256
#define FIRST 257
#define BUFFILEEOF (-1)

typedef struct BufFile {
    BufChar *buffer;
    BufChar *bufp;
    int left;
    void *private;
} *BufFilePtr;

typedef struct CompressedFile {
    char_type *stackp;
    char_type *de_stack;
    char_type finchar;
    code_int oldcode;
    unsigned short *tab_prefix;
    char_type *tab_suffix;
    int block_compress;
    int clear_flg;
    code_int free_ent;
    code_int maxmaxcode;
} CompressedFile;

code_int getcode(CompressedFile *file);