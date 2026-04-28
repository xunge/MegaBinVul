#include <stddef.h>

typedef unsigned int guint;

typedef struct tvbparse_wanted_t tvbparse_wanted_t;
typedef struct tvbparse_elem_t tvbparse_elem_t;
typedef struct tvbparse_t tvbparse_t;

struct tvbparse_elem_t {
    int id;
    int offset;
    int len;
    tvbparse_wanted_t* wanted;
    tvbparse_elem_t* sub;
    tvbparse_elem_t* last;
    tvbparse_elem_t* next;
};

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};

struct tvbparse_wanted_t {
    int id;
    guint min;
    guint max;
    union {
        tvbparse_wanted_t* subelem;
    } control;
    int (*condition)(tvbparse_t* tt, int offset, const tvbparse_wanted_t* wanted, tvbparse_elem_t** tok);
};

#define TVBPARSE_MAX_RECURSION_DEPTH 100

static tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted);