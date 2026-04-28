#include <stddef.h>

typedef unsigned char char_u;
typedef int typval_T;

typedef struct {
    void *ga_data;
    int ga_len;
} garray_T;

typedef struct {
    char *getline;
} exarg_T;

typedef struct {
    // context fields
} evalarg_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NUL '\0'

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define IS_WHITE_OR_NUL(c) (VIM_ISWHITE(c) || (c) == NUL)

#define GETLINE_CONCAT_CONT 0

static char_u *skipwhite(char_u *p);
static char_u *one_function_arg(char_u *p, garray_T *newargs, garray_T *argtypes, int types_optional, evalarg_T *evalarg, int varargs, int skip);
static int eval1(char_u **p, typval_T *rettv, void *arg);
static char_u *vim_strsave(char_u *str);
static void ga_init2(garray_T *gap, int size, int len);
static int ga_grow(garray_T *gap, int n);
static void ga_clear_strings(garray_T *gap);
static char_u *get_function_line(exarg_T *eap, char_u **line_to_free, int indent, int flags);
static int eval_isnamec1(int c);
static void emsg(char *msg);
static void semsg(char *msg, ...);

#define _(msg) msg
#define e_invalid_argument_str "E475: Invalid argument: %s"
#define e_missing_name_after_dots "E1068: Missing name after ..."
#define e_cannot_use_default_for_variable_arguments "E1070: Cannot use default for variable arguments"
#define e_non_default_argument_follows_default_argument "E1071: Non-default argument follows default argument"
#define e_no_white_space_allowed_before_str_str "E1072: No white space allowed before %s: %s"
#define e_white_space_required_after_str_str "E1073: White space required after %s: %s"