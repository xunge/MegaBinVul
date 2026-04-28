#include <stdlib.h>

typedef unsigned int guint;
#define TVBPARSE_MAX_RECURSION_DEPTH 100

typedef struct tvbparse_wanted_t tvbparse_wanted_t;
typedef struct tvbparse_elem_t tvbparse_elem_t;

typedef struct tvbparse_t {
    int end_offset;
    int recursion_depth;
} tvbparse_t;

struct tvbparse_wanted_t {
    int id;
    int len;
    struct {
        struct {
            tvbparse_wanted_t** pdata;
            unsigned int len;
        } *elems;
    } control;
    int (*condition)(tvbparse_t*, int, const tvbparse_wanted_t*, tvbparse_elem_t**);
};

struct tvbparse_elem_t {
    int offset;
    int len;
    tvbparse_elem_t* sub;
    tvbparse_elem_t* last;
    tvbparse_elem_t* next;
};

static tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted) {
    tvbparse_elem_t* tok = malloc(sizeof(tvbparse_elem_t));
    if (!tok) return NULL;
    tok->offset = offset;
    tok->len = len;
    tok->sub = NULL;
    tok->last = NULL;
    tok->next = NULL;
    return tok;
}

static int ignore_fcn(tvbparse_t* tt, int offset) {
    return 0;
}