#include <stddef.h>

typedef unsigned char char_u;
typedef int typval_T;

typedef struct {
    void *ga_data;
    int ga_len;
} garray_T;

typedef struct {
    char_u *(*getline)(int, void *, int, int);
    void *cookie;
    char_u **cmdlinep;
} exarg_T;

typedef struct {
    // context fields if needed
} evalarg_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NUL '\0'

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define IS_WHITE_OR_NUL(c) (VIM_ISWHITE(c) || (c) == NUL)

static char_u *skipwhite(char_u *p);
static char_u *one_function_arg(char_u *p, garray_T *newargs, garray_T *argtypes, int types_optional, evalarg_T *evalarg, int varargs, int skip);
static int eval1(char_u **arg, typval_T *rettv, evalarg_T *evalarg);
static void ga_init2(garray_T *gap, int size, int len);
static int ga_grow(garray_T *gap, int n);
static void ga_clear_strings(garray_T *gap);
static char_u *vim_strsave(char_u *string);
static void vim_free(void *ptr);
static void emsg(char *msg);
static void semsg(char *msg, ...);
#define _(msg) msg
#define e_invarg2 "E475: Invalid argument: %s"
#define e_missing_name_after_dots "E1068: Missing name after ..."
#define e_cannot_use_default_for_variable_arguments "E1070: Cannot use default for variable arguments"
#define e_no_white_space_allowed_before_str_str "E1069: No white space allowed before %s: %s"
#define e_white_space_required_after_str_str "E1071: White space required after %s: %s"