#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define VAR_UNKNOWN 0
#define FAIL 1
#define OK 0

typedef struct {
    int v_type;
} typval_T;

typedef struct {
    int eval_flags;
} evalarg_T;

#define EVAL_EVALUATE 0

typedef unsigned char char_u;

static int get_lambda_tv(char_u **arg, typval_T *rettv, int flag, evalarg_T *evalarg);
static int eval1(char_u **arg, typval_T *rettv, evalarg_T *evalarg);
static char_u *skipwhite_and_linebreak(char_u *arg, evalarg_T *evalarg);
static char_u *skipwhite(char_u *arg);
static void emsg(const char *msg);
static void semsg(const char *msg, const char *str);
static void clear_tv(typval_T *tv);
static int call_func_rettv(char_u **arg, evalarg_T *evalarg, typval_T *rettv, int evaluate, void *arg1, typval_T *arg2);

#define _(x) x
#define e_missing_closing_paren ""
#define e_nowhitespace ""
#define e_missing_parenthesis_str ""