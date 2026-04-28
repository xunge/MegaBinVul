#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint;

#define TVBPARSE_DEBUG 0
#define TVBPARSE_DEBUG_SOME 0
#define TVBPARSE_MAX_RECURSION_DEPTH 100

typedef struct tvbparse_elem tvbparse_elem_t;
typedef struct tvbparse_wanted tvbparse_wanted_t;
typedef struct tvbparse_t tvbparse_t;

struct tvbparse_elem {
    int id;
    int offset;
    int len;
    tvbparse_elem_t* sub;
    tvbparse_elem_t* next;
    tvbparse_elem_t* last;
    const tvbparse_wanted_t* wanted;
};

struct tvbparse_wanted {
    int id;
    guint min;
    guint max;
    union {
        tvbparse_wanted_t* subelem;
    } control;
    int (*condition)(tvbparse_t* tt, int offset, const tvbparse_wanted_t* wanted, tvbparse_elem_t** tok);
};

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};

tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted);