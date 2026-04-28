#include <stdbool.h>
#include <stddef.h>

typedef bool opj_bool;
#define OPJ_TRUE true
#define OPJ_FALSE false

typedef struct {
    int resno0;
    int resno1;
    int layno0;
    int layno1;
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
    opj_pi_comp_t *comps;
    opj_poc_t poc;
    int resno;
    int layno;
    int compno;
    int precno;
    int step_l;
    int step_r;
    int step_c;
    int step_p;
    int include_size;
    int *include;
    opj_bool first;
    opj_bool tp_on;
    void (*opj_pi_emit_error)(void*, const char*);
} opj_pi_iterator_t;