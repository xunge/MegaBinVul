#include <stdbool.h>
#include <stddef.h>

#define OPJ_TRUE true
#define OPJ_FALSE false

typedef bool opj_bool;

typedef struct {
    int compno0;
    int compno1;
    int layno0;
    int layno1;
    int resno0;
    int resno1;
    int tx0;
    int tx1;
    int ty0;
    int ty1;
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
    int compno;
    int resno;
    int layno;
    int precno;
    int x;
    int y;
    int dx;
    int dy;
    int tx0;
    int tx1;
    int ty0;
    int ty1;
    opj_poc_t poc;
    opj_pi_comp_t *comps;
    int step_c;
    int step_r;
    int step_l;
    int step_p;
    opj_bool *include;
    opj_bool first;
    opj_bool tp_on;
} opj_pi_iterator_t;

static int int_min(int a, int b) { return a < b ? a : b; }
static int int_ceildiv(int a, int b) { return (a + b - 1) / b; }
static int int_floordivpow2(int a, int b) { return a >> b; }