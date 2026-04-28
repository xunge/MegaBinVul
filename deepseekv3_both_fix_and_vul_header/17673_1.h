#include <stddef.h>

#define NUMBUFLEN 30

typedef unsigned char char_u;

typedef struct typval_S typval_T;
struct typval_S {
    int v_type;
    union {
        char_u *vval_string;
        long vval_number;
    } vval;
};

extern int p_pyx;

char_u *tv_get_string_buf(typval_T *var, char_u *buf);
void do_py3eval(char_u *str, typval_T *rettv);