#include <stdlib.h>

typedef struct exarg exarg_T;
typedef unsigned char char_u;

void *vim_free(void *ptr);
int define_function(exarg_T *eap, void *arg1, ...);