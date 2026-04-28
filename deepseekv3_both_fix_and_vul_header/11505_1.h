#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define R_FLIRT_NAME_MAX 256
#define DEBUG 0

typedef uint8_t ut8;
typedef uint32_t ut32;

typedef struct RFlirtFunction {
    ut32 offset;
    char name[R_FLIRT_NAME_MAX];
    bool negative_offset;
} RFlirtFunction;

typedef struct RFlirtModule {
    void *referenced_functions;
} RFlirtModule;

typedef struct RBuffer {
    // dummy structure
} RBuffer;

extern int version;
extern bool buf_eof;
extern bool buf_err;

static ut8 read_byte(RBuffer *b);
static ut32 read_multiple_bytes(RBuffer *b);
static ut32 read_max_2_bytes(RBuffer *b);

#define R_NEW0(x) calloc(1, sizeof(x))
#define r_list_new() NULL
#define r_list_append(x, y) 
#define eprintf(...) fprintf(stderr, __VA_ARGS__)