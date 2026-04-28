#include <stdbool.h>
#include <stddef.h>

typedef bool opj_bool;
#define OPJ_TRUE true
#define OPJ_FALSE false

typedef struct {
    int ty0;
    int tx0;
    int ty1;
    int tx1;
    int compno0;
    int compno1;
    int resno0;
    int resno1;
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
    int x;
    int y;
    int compno;
    int resno;
    int precno;
    int layno;
    int dx;
    int dy;
    int tx0;
    int ty0;
    int tx1;
    int ty1;
    int step_p;
    int step_c;
    int step_r;
    int step_l;
    opj_bool first;
    opj_bool tp_on;
    opj_poc_t poc;
    int numcomps;
    opj_pi_comp_t *comps;
    opj_bool *include;
} opj_pi_iterator_t;

static int int_min(int a, int b) { return a < b ? a : b; }
static int int_ceildiv(int a, int b) { return (a + b - 1) / b; }
static int int_floordivpow2(int a, int b) { return a >> b; }