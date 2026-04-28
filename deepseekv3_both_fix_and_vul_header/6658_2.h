#include <stdlib.h>
#include <stdio.h>

typedef struct tvbparse_wanted_t tvbparse_wanted_t;
typedef struct tvbparse_elem_t tvbparse_elem_t;
typedef struct tvbparse_t tvbparse_t;

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};

struct tvbparse_wanted_t {
    int id;
    int len;
    struct {
        struct {
            unsigned int len;
            tvbparse_wanted_t** pdata;
        } *elems;
    } control;
    int (*condition)(tvbparse_t*, const int, const tvbparse_wanted_t*, tvbparse_elem_t**);
};

struct tvbparse_elem_t {
    int offset;
    int len;
    tvbparse_elem_t* sub;
};

#define TVBPARSE_MAX_RECURSION_DEPTH 100
#define TVBPARSE_DEBUG 0
#define TVBPARSE_DEBUG_ONEOF 0

typedef unsigned int guint;

static void g_warning(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

static tvbparse_wanted_t* g_ptr_array_index(void* array, guint index) {
    return ((tvbparse_wanted_t**)array)[index];
}

static tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted) {
    tvbparse_elem_t* elem = malloc(sizeof(tvbparse_elem_t));
    if (elem) {
        elem->offset = offset;
        elem->len = len;
        elem->sub = NULL;
    }
    return elem;
}