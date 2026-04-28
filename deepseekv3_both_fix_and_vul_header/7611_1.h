#include <stddef.h>

typedef unsigned char char_u;

typedef struct {
    int v_type;
} typval_T;

typedef struct {
    int eval_flags;
} evalarg_T;

#define VAR_UNKNOWN 0
#define VAR_STRING 1
#define VAR_FUNC 2
#define VAR_PARTIAL 3
#define EVAL_EVALUATE 1
#define FAIL 1
#define OK 0
#define FALSE 0
#define TRUE 1

static int get_lambda_tv(char_u **arg, typval_T *rettv, int b, evalarg_T *evalarg);
static int eval1(char_u **arg, typval_T *rettv, evalarg_T *evalarg);
static char_u *skipwhite_and_linebreak(char_u *arg, evalarg_T *evalarg);
static char_u *skipwhite(char_u *arg);
static void emsg(const char *msg);
static void semsg(const char *msg, const char *s);
static void clear_tv(typval_T *tv);
static int call_func_rettv(char_u **arg, evalarg_T *evalarg, typval_T *rettv, int evaluate, void *p, typval_T *base);

#define _(x) x
#define e_missing_closing_paren "missing closing parenthesis"
#define e_string_or_function_required_for_arrow_parens_expr "string or function required for arrow/parens expression"
#define e_no_white_space_allowed_before_parenthesis "no white space allowed before parenthesis"
#define e_missing_parenthesis_str "missing parenthesis: %s"