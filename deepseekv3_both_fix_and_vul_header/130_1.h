#include <stddef.h>
#include <stdlib.h>

typedef unsigned char char_u;

#define NUL '\0'
#define FALSE 0
#define TRUE 1

#define CP_CONT_S_IPOS (1 << 0)
#define CP_ICASE (1 << 1)

extern int p_ic;
extern int has_mbyte;
extern char_u *compl_orig_text;
extern int compl_length;
extern struct buf *curbuf;

struct buf {
    int b_p_inf;
};

#define MB_PTR_ADV(p) ((p)++)
#define vim_free(ptr) free(ptr)

int ins_compl_add(char_u *str, int len, char_u *fname, void *arg1, void *arg2, int dir, int flags, int bool_arg);
char_u *ins_compl_infercase_gettext(char_u *str, int len1, int len2, int min_len, ...);