#include <stddef.h>

typedef unsigned char char_u;
typedef int colnr_T;

typedef struct {
    int rm_ic;
    void *regprog;
} regmatch_T;

extern int p_fic;

int vim_regexec(regmatch_T *rmp, char_u *name, colnr_T col);
char_u *home_replace_save(void *unused, char_u *name);
void vim_free(void *ptr);