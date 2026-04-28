#include <stddef.h>
#include <string.h>

#define NUMBUFLEN 50
#define FAIL 1
#define OK 0
#define NUL '\0'
#define VAR_FUNC 1
#define VAR_PARTIAL 2
#define VAR_INSTR 3
#define UF_NOT_COMPILED 0
#define DEF_USE_PT_ARGV 0
#define TRUE 1
#define e_invalid_expression_str "E15: Invalid expression: %s"

typedef struct typval_S typval_T;
typedef struct funcexe_S funcexe_T;
typedef struct partial_S partial_T;
typedef struct ufunc_S ufunc_T;
typedef struct funccall_S funccall_T;

typedef unsigned char char_u;

struct typval_S {
    int v_type;
    union {
        char_u *v_string;
        partial_T *v_partial;
    } vval;
};

struct funcexe_S {
    int fe_evaluate;
    partial_T *fe_partial;
};

struct partial_S {
    ufunc_T *pt_func;
};

struct ufunc_S {
    int uf_def_status;
};

struct funccall_S {
    // Placeholder for actual implementation
};

int call_func(char_u *name, int argcount, typval_T *rettv, int argc, typval_T *argv, funcexe_T *funcexe);
char_u *partial_name(partial_T *partial);
int exe_typval_instr(typval_T *expr, typval_T *rettv);
char_u *tv_get_string_buf_chk_strict(typval_T *tv, char_u *buf, int strict);
char_u *skipwhite(char_u *s);
int eval1_emsg(char_u **arg, typval_T *rettv, int *evaluate);
void clear_tv(typval_T *varp);
void semsg(const char *msg, char_u *s);
funccall_T *create_funccal(ufunc_T *fp, typval_T *rettv);
int call_def_function(ufunc_T *fp, int argc, typval_T *argv, int flags, partial_T *partial, funccall_T *fc, typval_T *rettv);
void remove_funccal(void);
int in_vim9script(void);

#define CLEAR_FIELD(field) memset(&(field), 0, sizeof(field))
#define _(x) x