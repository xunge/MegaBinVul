#include <stdbool.h>
#include <stddef.h>

#define OPJ_FALSE false
#define OPJ_TRUE true

typedef bool opj_bool;
typedef struct opj_pi_iterator_t opj_pi_iterator_t;
typedef struct opj_pi_comp_t opj_pi_comp_t;
typedef struct opj_pi_resolution_t opj_pi_resolution_t;
typedef struct opj_poc_t opj_poc_t;

struct opj_pi_resolution_t {
    int pdx;
    int pdy;
    int pw;
    int ph;
};

struct opj_pi_comp_t {
    int dx;
    int dy;
    int numresolutions;
    opj_pi_resolution_t *resolutions;
};

struct opj_poc_t {
    int compno0;
    int compno1;
    int layno0;
    int layno1;
    int resno0;
    int resno1;
    int tx0;
    int ty0;
    int tx1;
    int ty1;
};

struct opj_pi_iterator_t {
    int compno;
    int resno;
    int layno;
    int precno;
    int x;
    int y;
    int dx;
    int dy;
    int tx0;
    int ty0;
    int tx1;
    int ty1;
    opj_poc_t poc;
    opj_pi_comp_t *comps;
    int step_c;
    int step_r;
    int step_l;
    int step_p;
    int include_size;
    int *include;
    opj_bool tp_on;
    opj_bool first;
};

static int int_min(int a, int b) { return a < b ? a : b; }
static int int_ceildiv(int a, int b) { return (a + b - 1) / b; }
static int int_floordivpow2(int a, int b) { return a >> b; }
static void opj_pi_emit_error(opj_pi_iterator_t *pi, const char *msg) {}