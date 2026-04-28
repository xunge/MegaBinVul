#include <stddef.h>

#define NUMBUFLEN 100

typedef struct typval_S typval_T;
struct typval_S {
    /* structure members would go here */
};

typedef unsigned char char_u;

extern int p_pyx;
extern char_u *tv_get_string_buf(typval_T *var, char_u *buf);
extern void do_pyeval(char_u *str, typval_T *rettv);