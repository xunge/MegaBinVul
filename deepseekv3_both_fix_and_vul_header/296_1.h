#include <stdbool.h>
#include <stddef.h>

typedef bool opj_bool;
#define OPJ_TRUE true
#define OPJ_FALSE false

typedef struct {
    int layno0;
    int layno1;
    int resno0;
    int resno1;
    int compno0;
    int compno1;
    int precno0;
    int precno1;
} opj_poc_t;

typedef struct {
    int pw;
    int ph;
} opj_pi_resolution_t;

typedef struct {
    int numresolutions;
    opj_pi_resolution_t *resolutions;
} opj_pi_comp_t;

typedef struct {
    int first;
    int layno;
    int resno;
    int compno;
    int precno;
    int step_l;
    int step_r;
    int step_c;
    int step_p;
    opj_poc_t poc;
    opj_pi_comp_t *comps;
    int *include;
    int include_size;
    int tp_on;
    void (*opj_pi_emit_error)(struct opj_pi_iterator_t*, const char*);
} opj_pi_iterator_t;

void opj_pi_emit_error(opj_pi_iterator_t *pi, const char *msg);