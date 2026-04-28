#include <stddef.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned char char_u;

#define TRUE 1
#define FALSE 0

typedef enum {
    FAIL,
    OK
} status_T;

typedef enum {
    SKIP_YES,
    SKIP_NO
} skip_T;

typedef enum {
    CT_NONE,
    CT_PROFILE
} compiletype_T;

typedef enum {
    CMD_def,
    CMD_other
} cmdidx_T;

typedef enum {
    UF_COMPILED,
    UF_NOT_COMPILED
} defstatus_T;

typedef enum {
    ISN_STORE
} isn_type_T;

typedef struct exarg {
    char_u *arg;
    char_u *nextcmd;
    char_u *cmd;
    int forceit;
    int skip;
    cmdidx_T cmdidx;
} exarg_T;

typedef struct cctx {
    skip_T ctx_skip;
    compiletype_T ctx_compile_type;
    struct ufunc *ctx_ufunc;
} cctx_T;

typedef struct ufunc {
    int uf_block_depth;
    int *uf_block_ids;
    defstatus_T uf_def_status;
    int uf_dfunc_idx;
    void *uf_func_type;
} ufunc_T;

typedef struct lvar {
    int lv_idx;
    char_u *lv_name;
} lvar_T;

typedef struct isn {
    isn_type_T isn_type;
    union {
        struct {
            int fr_dfunc_idx;
        } funcref;
    } isn_arg;
} isn_T;

typedef struct garray garray_T;

#define _(x) x
#define e_cannot_use_bang_with_nested_def "Cannot use ! with nested def"
#define e_cannot_define_dict_func_in_vim9_script_str "Cannot define dict function in Vim9 script: %s"
#define e_invalid_command_str "Invalid command: %s"
#define e_namespace_not_supported_str "Namespace not supported: %s"
#define e_function_name_must_start_with_capital_str "Function name must start with capital: %s"
#define e_text_found_after_str_str "Text found after %s: %s"

#define ASCII_ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define ALLOC_MULT(type, count) ((type *)malloc(sizeof(type) * (count)))
#define mch_memmove memmove

static char_u *skipwhite(char_u *p);
static char_u *to_name_end(char_u *p, int);
static char_u *skip_regexp(char_u *p, int delim, int);
static void set_nextcmd(exarg_T *eap, char_u *p);
static int ends_excmd2(char_u *start, char_u *end);
static int generate_DEF(cctx_T *cctx, char_u *name, int len);
static int check_defined(char_u *name, int len, cctx_T *cctx, void *arg, int);
static void fill_exarg_from_cctx(exarg_T *eap, cctx_T *cctx);
static char_u *get_lambda_name(void);
static char_u *vim_strsave(char_u *str);
static char_u *vim_strnsave(char_u *str, size_t len);
static ufunc_T *define_function(exarg_T *eap, char_u *name, garray_T *lines);
static void func_ptr_unref(ufunc_T *ufunc);
static lvar_T *reserve_local(cctx_T *cctx, char_u *name, int len, int, void *type);
static int generate_FUNCREF(cctx_T *cctx, ufunc_T *ufunc, isn_T **isn);
static int generate_STORE(cctx_T *cctx, isn_type_T type, int idx, void *arg);
static int generate_NEWFUNC(cctx_T *cctx, char_u *lambda, char_u *name);
static compiletype_T get_compile_type(ufunc_T *ufunc);
static int func_needs_compiling(ufunc_T *ufunc, compiletype_T type);
static int compile_def_function(ufunc_T *ufunc, int, compiletype_T, cctx_T *cctx);
static void vim_free(void *ptr);
static void semsg(const char *msg, ...);
static void emsg(const char *msg);