#include <stdlib.h>
#include <string.h>

typedef char char_u;
typedef long colnr_T;

typedef struct {
    int rm_ic;
    void *regprog;
    char_u *startp[1];
    char_u *endp[1];
} regmatch_T;

typedef struct {
    int ga_len;
    char *ga_data;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
} garray_T;

typedef struct {
    int v_type;
} typval_T;

#define NUL '\0'
#define FAIL 0
#define RE_MAGIC 1
#define RE_STRING 2
#define REGSUB_MAGIC 4
#define REGSUB_COPY 8

extern char_u *p_cpo;
extern char_u *empty_option;
extern int p_ic;

void *vim_regcomp(char_u *pat, int flags);
int vim_regexec_nl(regmatch_T *rmp, char_u *str, colnr_T col);
int vim_regsub(regmatch_T *rmp, char_u *sub, typval_T *expr, char_u *dest, int destlen, int flags);
void vim_regfree(void *prog);
char_u *vim_strsave(char_u *str);
void ga_init2(garray_T *gap, int itemsize, int growsize);
int ga_grow(garray_T *gap, int len);
void ga_clear(garray_T *gap);
void mch_memmove(char_u *dest, char_u *src, size_t len);
int mb_ptr2len(char_u *p);
void set_option_value_give_err(char_u *name, long number, char_u *string, int opt_flags);
void free_string_option(char_u *p);
#define STRLEN strlen