#include <stdlib.h>

typedef unsigned int guint;

typedef struct tvbparse_wanted_t tvbparse_wanted_t;
typedef struct tvbparse_elem_t tvbparse_elem_t;
typedef struct tvbparse_t tvbparse_t;

struct tvbparse_wanted_t {
    int id;
    int len;
    union {
        struct {
            void** pdata;
            guint len;
        }* elems;
    } control;
    int (*condition)(tvbparse_t*, const int, const tvbparse_wanted_t*, tvbparse_elem_t**);
};

struct tvbparse_elem_t {
    int offset;
    int len;
    tvbparse_elem_t* sub;
};

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};

#define TVBPARSE_DEBUG 1
#define TVBPARSE_DEBUG_ONEOF 1
#define TVBPARSE_MAX_RECURSION_DEPTH 100

static void* g_ptr_array_index(void* array, guint index) {
    return ((void**)array)[index];
}

static void g_warning(const char *format, ...) {}

static tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted) {
    return NULL;
}