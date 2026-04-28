#include <stddef.h>

typedef struct typval_S typval_T;
extern int p_pyx;
extern void init_pyxversion(void);
extern void f_pyeval(typval_T *argvars, typval_T *rettv);
extern void f_py3eval(typval_T *argvars, typval_T *rettv);