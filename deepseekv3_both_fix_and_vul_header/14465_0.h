#include <stddef.h>

typedef unsigned char char_u;

typedef struct exarg_S exarg_T;
typedef struct garray_S garray_T;
typedef int getline_opt_T;

struct garray_S {
    int ga_len;
    void *ga_data;
};

struct exarg_S {
    char_u *(*getline)(int, void *, int, getline_opt_T);
    void *cookie;
    char_u **cmdlinep;
};

char_u *getcmdline(int, long, int, int);
void ga_add_string(garray_T *, char_u *);