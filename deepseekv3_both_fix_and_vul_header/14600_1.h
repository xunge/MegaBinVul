#include <stdlib.h>

#define ALLOC_CLEAR_MULT(type, count) calloc((count), sizeof(type))
#define FAIL 0
#define OK 1

typedef struct wline_T {
    /* dummy structure since actual definition is not provided */
    int dummy;
} wline_T;

typedef struct win_T {
    int w_lines_valid;
    wline_T *w_lines;
} win_T;

extern int Rows;