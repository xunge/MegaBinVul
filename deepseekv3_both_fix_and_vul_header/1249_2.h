#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char char_u;
typedef struct typval_S typval_T;
typedef struct evalarg_S evalarg_T;
typedef struct garray_S garray_T;
typedef struct ufunc_S ufunc_T;
typedef struct partial_S partial_T;
typedef struct script_ctx_S script_ctx_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NOTDONE 2

#define EVAL_EVALUATE 1
#define FC_LAMBDA 1
#define FC_NOARGS 2
#define FC_CLOSURE 4
#define FC_SANDBOX 8
#define UF_NOT_COMPILED 0
#define VAR_PARTIAL 1

#define _(x) x
#define e_cannot_use_default_values_in_lambda "Cannot use default values in lambda"
#define e_expected_right_curly_str "Expected right curly: %s"

struct typval_S {
    int v_type;
    union {
        struct partial_S *v_partial;
    } vval;
};

struct evalarg_S {
    int eval_flags;
    char_u *eval_tofree;
    void *eval_cstack;
};

struct garray_S {
    int ga_len;
    void *ga_data;
};

struct script_ctx_S {
    int sc_lnum;
};

struct ufunc_S {
    int uf_def_status;
    int uf_refcount;
    char_u uf_name[1];
    garray_T uf_args;
    garray_T uf_def_args;
    void *uf_ret_type;
    void *uf_type_list;
    garray_T uf_lines;
    int uf_flags;
    int uf_varargs;
    int uf_calls;
    script_ctx_T uf_script_ctx;
    void *uf_arg_types;
};

struct partial_S {
    ufunc_T *pt_func;
    int pt_refcount;
};

static int called_emsg = 0;
static int *eval_lavars_used = NULL;
static long SOURCING_LNUM = 0;
static void *t_unknown = NULL;
static void *func_hashtab = NULL;
static int sandbox = 0;
static void *current_funccal = NULL;
static script_ctx_T current_sctx = {0};

#define UF2HIKEY(fp) ((int)((fp)->uf_name))

static int in_vim9script(void) { return 0; }
static char_u *vim_strsave(char_u *s) { return (char_u*)strdup((char*)s); }
static char_u *vim_strchr(char_u *s, int c) { return (char_u*)strchr((char*)s, c); }
static char_u *vim_strncpy(char_u *dest, char_u *src, size_t n) { return (char_u*)strncpy((char*)dest, (char*)src, n); }
static char_u *vim_strnsave(char_u *src, size_t n) { char_u *dest = malloc(n+1); strncpy((char*)dest, (char*)src, n); dest[n] = '\0'; return dest; }
static void ga_init(garray_T *gap) { gap->ga_len = 0; gap->ga_data = NULL; }
static void ga_init2(garray_T *gap, int size, int growsize) { gap->ga_len = 0; gap->ga_data = NULL; }
static int ga_grow(garray_T *gap, int n) { return OK; }
static void ga_clear_strings(garray_T *gap) { free(gap->ga_data); gap->ga_len = 0; }
static char_u *skipwhite_and_linebreak(char_u *s, evalarg_T *evalarg) { return s; }
static int skip_expr_concatenate(char_u **arg, char_u **start, char_u **end, evalarg_T *evalarg) { return OK; }
static char_u *get_lambda_name(void) { return (char_u*)""; }
static void set_ufunc_name(ufunc_T *fp, char_u *name) { strcpy((char*)fp->uf_name, (char*)name); }
static int parse_argument_types(ufunc_T *fp, garray_T *argtypes, int varargs) { return OK; }
static void *parse_type(char_u **ret_type, void **type_list, int flag) { return NULL; }
static int register_closure(ufunc_T *fp) { return OK; }
static void func_do_profile(ufunc_T *fp) {}
static void function_using_block_scopes(ufunc_T *fp, void *cstack) {}
static void hash_add(void *hashtab, int key) {}
static char_u *alloc(int size) { return malloc(size); }
static void *alloc_clear(size_t size) { return calloc(1, size); }
#define ALLOC_CLEAR_ONE(type) (type *)alloc_clear(sizeof(type))
static void vim_free(void *p) { free(p); }
static void emsg(const char *s) {}
static void semsg(const char *s, char_u *arg) {}
#define STRLEN(s) strlen((char*)s)
#define STRCPY(d, s) strcpy((char*)d, s)

static int get_function_args(
    char_u **arg,
    int delim,
    garray_T *newargs,
    garray_T *argtypes,
    int types_optional,
    evalarg_T *evalarg,
    int *varargs,
    garray_T *default_args,
    int first_only,
    void *arg_type_list,
    void *arg_default_arg_types) { return OK; }

static char_u *skip_arrow(
    char_u *s,
    int equal_arrow,
    char_u **ret_type,
    int *white_error) { return NULL; }

static int lambda_function_body(
    char_u **arg,
    typval_T *rettv,
    evalarg_T *evalarg,
    garray_T *newargs,
    garray_T *argtypes,
    int varargs,
    garray_T *default_args,
    char_u *ret_type) { return OK; }