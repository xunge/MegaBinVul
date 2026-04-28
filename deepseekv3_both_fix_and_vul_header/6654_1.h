#include <stddef.h>
#include <stdio.h>

typedef struct tvbparse_wanted_t tvbparse_wanted_t;
typedef struct tvbparse_elem_t tvbparse_elem_t;
typedef struct tvbparse_t tvbparse_t;

#define TVBPARSE_DEBUG 1
#define TVBPARSE_DEBUG_UNTIL 1
#define TVBPARSE_MAX_RECURSION_DEPTH 100

enum {
    TP_UNTIL_INCLUDE,
    TP_UNTIL_SPEND, 
    TP_UNTIL_LEAVE
};

struct tvbparse_wanted_t {
    int id;
    int len;
    int (*condition)(tvbparse_t*, int, const tvbparse_wanted_t*, tvbparse_elem_t**);
    union {
        struct {
            tvbparse_wanted_t *subelem;
            int mode;
        } until;
    } control;
};

struct tvbparse_elem_t {
    int id;
    int len;
    int offset;
    const tvbparse_wanted_t *wanted;
    tvbparse_elem_t *next;
    tvbparse_elem_t *last;
};

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};

#define DISSECTOR_ASSERT_NOT_REACHED() abort()
#define g_warning printf