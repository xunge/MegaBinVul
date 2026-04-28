#include <assert.h>
#include <math.h>

typedef struct {
    int kind;
    int flags;
    union {
        double number;
        void* dec_number;
    } u;
} jv;

typedef struct {
    unsigned char bytes[16];
} decNumber;

#define JVP_HAS_KIND(a, k) ((a).kind == (k))
#define JVP_HAS_FLAGS(a, f) ((a).flags & (f))
#define JV_KIND_NUMBER 1
#define JVP_FLAGS_NUMBER_LITERAL 1

static inline double jv_number_value(jv a) { return a.u.number; }
static inline decNumber* jvp_dec_number_ptr(jv a) { return a.u.dec_number; }

extern int decNumberCompare(decNumber*, const decNumber*, const decNumber*, void*);
extern int decNumberIsZero(const decNumber*);
extern int decNumberIsNegative(const decNumber*);
#define DEC_CONTEXT() ((void*)0)