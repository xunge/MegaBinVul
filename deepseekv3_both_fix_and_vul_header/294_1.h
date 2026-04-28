#include <stdbool.h>
#include <stddef.h>

#define OPJ_FALSE false
#define OPJ_TRUE true

typedef bool opj_bool;

typedef struct {
    int ty0;
    int tx0;
    int ty1;
    int tx1;
    int resno0;
    int resno1;
    int compno0;
    int compno1;
    int layno0;
    int layno1;
} opj_poc_t;

typedef struct {
    int pdx;
    int pdy;
    int pw;
    int ph;
} opj_pi_resolution_t;

typedef struct {
    int dx;
    int dy;
    int numresolutions;
    opj_pi_resolution_t *resolutions;
} opj_pi_comp_t;

typedef struct {
    int first;
    int dx;
    int dy;
    int numcomps;
    opj_pi_comp_t *comps;
    int tp_on;
    int ty0;
    int tx0;
    int ty1;
    int tx1;
    opj_poc_t poc;
    int resno;
    int y;
    int x;
    int compno;
    int precno;
    int layno;
    long step_l;
    long step_r;
    long step_c;
    long step_p;
    int include_size;
    int *include;
    void (*opj_pi_emit_error)(void*, const char*);
} opj_pi_iterator_t;

static int int_min(int a, int b) { return a < b ? a : b; }
static int int_ceildiv(int a, int b) { return (a + b - 1) / b; }
static int int_floordivpow2(int a, int b) { return a >> b; }