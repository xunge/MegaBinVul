#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef uint64_t ut64;
#define PFMT64x PRIx64

typedef struct RAnalFunction {
    char *name;
} RAnalFunction;

typedef struct RAnal {
    // dummy structure
} RAnal;

typedef struct RCore {
    RAnal *anal;
} RCore;

RAnalFunction *r_anal_get_function_at(RAnal *anal, ut64 addr);
int r_cons_printf(const char *fmt, ...);