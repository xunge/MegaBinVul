#include <stdbool.h>
#include <stdlib.h>

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

extern ut8 version;
extern bool buf_eof;
extern bool buf_err;

static ut8 read_byte(RBuffer *b);
static ut32 read_multiple_bytes(RBuffer *b);
static ut32 read_max_2_bytes(RBuffer *b);

#define R_NEW0(x) calloc(1, sizeof(x))
#define r_list_new() malloc(sizeof(void*))
#define r_list_append(x, y) (void)0
#define eprintf(...) (void)0