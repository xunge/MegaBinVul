#include <stddef.h>

typedef struct {} typval_T;
typedef unsigned char char_u;

#define NUMBUFLEN 64

char_u *tv_get_string_buf(typval_T *var, char_u *buf);
void do_mzeval(char_u *str, typval_T *rettv);