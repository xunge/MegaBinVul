#include <string.h>
#include <stddef.h>

typedef unsigned char char_u;
typedef int typval_T;
typedef struct cctx_S cctx_T;
typedef struct exarg_S {
    char_u *arg;
} exarg_T;
typedef struct lhs_S lhs_T;

enum {
    SKIP_YES,
    FAIL
};

enum {
    CMD_redir
};

enum {
    ISN_REDIRSTART,
    ISN_REDIREND
};

#define TRUE 1
#define FALSE 0

struct lhs_S {
    char_u *lhs_name;
    char_u *lhs_whole;
    typval_T *lhs_member_type;
    int lhs_append;
    int lhs_has_index;
    int lhs_varlen_total;
};

struct cctx_S {
    lhs_T ctx_redir_lhs;
    int ctx_skip;
};

extern char_u e_cannot_nest_redir[];
extern typval_T t_string;

char_u *skipwhite(char_u *p);
char_u *vim_strnsave(const char_u *str, size_t len);
void VIM_CLEAR(void *p);
char_u *_(char_u *str);
void emsg(char_u *str);
int STRNCMP(const char_u *s1, const char_u *s2, size_t n);
int compile_assign_lhs(char_u *arg, lhs_T *lhs, int cmd, int skip, int forceit, int dec, int want_range, cctx_T *cctx);
int compile_load_lhs_with_index(lhs_T *lhs, char_u *name, cctx_T *cctx);
int compile_assign_unlet(char_u *name, lhs_T *lhs, int skip, typval_T *type, cctx_T *cctx);
int generate_store_lhs(cctx_T *cctx, lhs_T *lhs, int idx, int void_ok);
void generate_instr(cctx_T *cctx, int isn);
void generate_instr_type(cctx_T *cctx, int isn, typval_T *type);
void generate_CONCAT(cctx_T *cctx, int count);
int need_type(typval_T *expected, typval_T *actual, int argidx, int is_optional, cctx_T *cctx, int is_compare, int is_type_mismatch);
char_u *compile_exec(char_u *line, exarg_T *eap, cctx_T *cctx);