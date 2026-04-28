#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char ut8;

typedef struct RBuffer RBuffer;
typedef struct RList RList;
typedef struct RListIter {
    void *data;
    struct RListIter *n;
    struct RListIter *p;
} RListIter;

typedef struct pyc_object {
    int type;
    void *data;
} pyc_object;

extern RList *refs;

#define FLAG_REF 0x80
#define R_NEW0(x) calloc(1, sizeof(x))

enum {
    TYPE_NULL = 1,
    TYPE_TRUE,
    TYPE_FALSE,
    TYPE_NONE,
    TYPE_REF,
    TYPE_SMALL_TUPLE,
    TYPE_TUPLE,
    TYPE_STRING,
    TYPE_CODE_v0,
    TYPE_CODE_v1,
    TYPE_INT,
    TYPE_ASCII_INTERNED,
    TYPE_SHORT_ASCII,
    TYPE_ASCII,
    TYPE_SHORT_ASCII_INTERNED,
    TYPE_INT64,
    TYPE_INTERNED,
    TYPE_STRINGREF,
    TYPE_FLOAT,
    TYPE_BINARY_FLOAT,
    TYPE_COMPLEX,
    TYPE_BINARY_COMPLEX,
    TYPE_LIST,
    TYPE_LONG,
    TYPE_UNICODE,
    TYPE_DICT,
    TYPE_FROZENSET,
    TYPE_SET,
    TYPE_STOPITER,
    TYPE_ELLIPSIS,
    TYPE_UNKNOWN
};