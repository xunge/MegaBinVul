#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;

#define TRUE 1
#define FALSE 0
#define NUL '\0'

#define VAR_UNKNOWN 0
#define VAR_BOOL 1
#define VAR_SPECIAL 2
#define VAR_STRING 3
#define VAR_BLOB 4
#define VAR_VOID 5

#define OK 1
#define FAIL 0
#define NOTDONE -1

#define EVAL_EVALUATE 1
#define EVAL_CONSTANT 2
#define EVAL_VAR_VERBOSE 4
#define EVAL_VAR_IMPORT 8

#define VVAL_TRUE 1
#define VVAL_FALSE 0
#define VVAL_NULL -1

#define GREG_EXPR_SRC 1

#define IS_WHITE_OR_NUL(c) (isspace(c) || (c) == NUL)
#define STRNCMP strncmp

typedef struct {
    int v_type;
    union {
        int v_number;
        char_u *v_string;
        struct partial *v_partial;
    } vval;
} typval_T;

typedef struct {
    int eval_flags;
} evalarg_T;

typedef struct ufunc {
    struct type *uf_ret_type;
} ufunc_T;

typedef struct type {
    int tt_type;
} type_T;

typedef struct partial {
    ufunc_T *pt_func;
} partial_T;

static type_T t_unknown = {VAR_UNKNOWN};

static const char *e_invalid_expression_str = "E1";
static const char *e_expression_too_recursive_str = "E2";
static const char *e_syntax_error_at_str = "E3";
static const char *e_missing_closing_paren = "E4";
static const char *e_cannot_use_underscore_here = "E5";

#define _(x) x

static void semsg(const char *msg, char_u *arg) {}
static void emsg(const char *msg) {}
static void emsg_invreg(int regname) {}
static void vim_free(void *p) {}

static int eval_leader(char_u **arg, int in_vim9script) { return 0; }
static int eval_number(char_u **arg, typval_T *rettv, int evaluate, int want_string) { return 0; }
static int eval_string(char_u **arg, typval_T *rettv, int evaluate) { return 0; }
static int eval_lit_string(char_u **arg, typval_T *rettv, int evaluate) { return 0; }
static int eval_list(char_u **arg, typval_T *rettv, evalarg_T *evalarg, int evaluate) { return 0; }
static int eval_dict(char_u **arg, typval_T *rettv, evalarg_T *evalarg, int evaluate) { return 0; }
static int get_lambda_tv(char_u **arg, typval_T *rettv, int in_vim9script, evalarg_T *evalarg) { return 0; }
static int eval_option(char_u **arg, typval_T *rettv, int evaluate) { return 0; }
static int eval_env_var(char_u **arg, typval_T *rettv, int evaluate) { return 0; }
static char_u *get_reg_contents(int regname, int flags) { return NULL; }
static int eval1(char_u **arg, typval_T *rettv, evalarg_T *evalarg) { return 0; }
static int eval_func(char_u **arg, evalarg_T *evalarg, char_u *name, int len, typval_T *rettv, int flags, void *arglist) { return 0; }
static int eval_variable(char_u *name, int len, int flags, typval_T *rettv, void *fp, int options) { return 0; }
static int handle_subscript(char_u **arg, char_u *name_start, typval_T *rettv, evalarg_T *evalarg, int evaluate) { return 0; }
static int eval7_leader(typval_T *rettv, int is_number, char_u *start_leader, char_u **end_leader) { return 0; }
static void clear_tv(typval_T *tv) {}
static int valid_yank_reg(int regname, int writing) { return 0; }
static int in_vim9script(void) { return 0; }
static int in_old_script(int version) { return 0; }
static char_u *skipwhite(char_u *p) { return p; }
static char_u *skipwhite_and_linebreak(char_u *p, evalarg_T *evalarg) { return p; }
static int get_name_len(char_u **arg, char_u **alias, int evaluate, int verbose) { return 0; }
static void check_vars(char_u *name, int len) {}
static int vim9_bad_comment(char_u *arg) { return 0; }
static int compile_def_function(ufunc_T *ufunc, int nested, int flags, char_u **errormsg) { return 0; }
#define COMPILE_TYPE(x) 0