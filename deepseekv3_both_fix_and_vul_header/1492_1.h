#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef unsigned int ut32;
typedef unsigned char ut8;

#define TYPE_COMPLEX 1

typedef struct pyc_object {
    int type;
    char *data;
} pyc_object;

typedef struct RzBinPycObj {
    ut32 magic_int;
} RzBinPycObj;

typedef struct RzBuffer RzBuffer;

#define RZ_NEW0(x) calloc(1, sizeof(x))
#define RZ_FREE(x) free(x)

static ut8 get_ut8(RzBuffer *buffer, bool *error) { return 0; }
static ut32 get_st32(RzBuffer *buffer, bool *error) { return 0; }
static ut32 rz_buf_read(RzBuffer *buffer, ut8 *buf, ut32 size) { return 0; }
static char *rz_str_newf(const char *fmt, ...) { return NULL; }