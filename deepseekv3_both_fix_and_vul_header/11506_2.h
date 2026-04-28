#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char ut8;
typedef unsigned int ut32;

#define R_FLIRT_NAME_MAX 256
#define DEBUG 0

typedef struct RFlirtFunction {
    ut32 offset;
    char name[R_FLIRT_NAME_MAX];
    bool negative_offset;
} RFlirtFunction;

typedef struct RFlirtModule {
    void *referenced_functions;
} RFlirtModule;

typedef struct RBuffer {
    // dummy structure for compilation
} RBuffer;

extern int version;
extern bool buf_eof;
extern bool buf_err;

static ut8 read_byte(RBuffer *b) { return 0; }
static ut32 read_multiple_bytes(RBuffer *b) { return 0; }
static ut32 read_max_2_bytes(RBuffer *b) { return 0; }

static void *r_list_new(void) { return NULL; }
static void *R_NEW0(size_t size) { return calloc(1, size); }
#define R_NEW0(type) ((type*)calloc(1, sizeof(type)))
static void r_list_append(void *list, void *data) { }