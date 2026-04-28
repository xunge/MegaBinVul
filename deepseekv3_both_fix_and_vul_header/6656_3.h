#include <stdlib.h>

typedef unsigned int guint;

typedef struct tvbparse_wanted_t tvbparse_wanted_t;
typedef struct tvbparse_elem_t tvbparse_elem_t;
typedef struct tvbparse_t tvbparse_t;

typedef struct {
    tvbparse_wanted_t** pdata;
    unsigned int len;
} elems_t;

typedef struct {
    elems_t* elems;
} control_t;

struct tvbparse_wanted_t {
    int id;
    int len;
    control_t control;
    int (*condition)(tvbparse_t*, int, const tvbparse_wanted_t*, tvbparse_elem_t**);
};

struct tvbparse_elem_t {
    int id;
    int offset;
    int len;
    tvbparse_elem_t* sub;
    tvbparse_elem_t* last;
    tvbparse_elem_t* next;
    const tvbparse_wanted_t* wanted;
};

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};

#define TVBPARSE_MAX_RECURSION_DEPTH 100
#define g_ptr_array_index(array, index) ((array)->pdata[(index)])

extern int ignore_fcn(tvbparse_t* tt, int offset);
extern tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted);