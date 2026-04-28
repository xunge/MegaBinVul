#include <stddef.h>

typedef unsigned char char_u;
typedef int bool;

#define TRUE 1
#define FALSE 0

typedef struct regmatch_T {
    void *regprog;
} regmatch_T;

typedef struct buf_T {
    char_u *b_sfname;
    char_u *b_ffname;
} buf_T;

char_u *fname_match(regmatch_T *rmp, char_u *name, int ignore_case);