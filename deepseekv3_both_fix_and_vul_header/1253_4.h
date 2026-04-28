#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef uint64_t ut64;
typedef uint32_t ut32;

typedef struct RList RList;
typedef struct RListIter RListIter;
typedef struct RAnalBlock RAnalBlock;

typedef struct RAnalFunction {
    ut64 addr;
    RList *bbs;
} RAnalFunction;

typedef struct RAnalBlock {
    ut64 addr;
    ut32 size;
} RAnalBlock;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
    struct RListIter *p;
} RListIter;

typedef struct RList {
    RListIter *head;
    RListIter *tail;
} RList;

typedef struct RAnal {
    // dummy structure
} RAnal;

typedef struct RCore {
    RAnal *anal;
    ut64 offset;
} RCore;

#define UT64_MAX UINT64_MAX
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))
#define PFMT64x PRIx64
#define R_ANAL_FCN_TYPE_ANY 0

RAnalFunction *r_anal_get_fcn_in(RAnal *anal, ut64 offset, int type);
ut32 r_anal_function_size_from_entry(RAnalFunction *fcn);
#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)
int r_cons_printf(const char *fmt, ...);