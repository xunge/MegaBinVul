#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char char_u;
typedef int compiletype_T;
typedef int garray_T;

#define FAIL 1
#define OK 0
#define TRUE 1
#define FALSE 0
#define CT_NONE 0
#define CT_PROFILE 1
#define COMPILE_TYPE(x) CT_NONE
#define FEAT_PROFILE 1
#define CMD_def 0
#define ISN_STORE 0

#define e_cannot_use_bang_with_nested_def "E127"
#define e_invalid_command_str "E182"
#define e_namespace_not_supported_str "E128"
#define e_text_found_after_str_str "E129"

typedef struct {
    char_u *arg;
    int forceit;
    char_u *cmd;
    char_u *nextcmd;
    int skip;
    int cmdidx;
} exarg_T;

typedef struct {
    int uf_block_depth;
    int *uf_block_ids;
    int uf_func_type;
} ufunc_T;

typedef struct {
    ufunc_T *ctx_ufunc;
    int ctx_compile_type;
} cctx_T;

typedef struct {
    int lv_idx;
} lvar_T;

#define ALLOC_MULT(type, count) ((type *)calloc((count), sizeof(type)))

static char_u *skip_regexp(char_u *p, int delim, int magic) { return p; }
static char_u *skipwhite(char_u *p) { return p; }
static int ends_excmd2(char_u *p, char_u *end) { return 1; }
static int generate_DEF(cctx_T *cctx, char_u *name, int len) { return OK; }
static int check_defined(char_u *name, int len, cctx_T *cctx, int is_global) { return OK; }
static void fill_exarg_from_cctx(exarg_T *eap, cctx_T *cctx) {}
static char_u *get_lambda_name(void) { return (char_u *)""; }
static char_u *vim_strsave(char_u *str) { return str ? strdup(str) : NULL; }
static char_u *vim_strnsave(char_u *str, int len) { return str ? strndup(str, len) : NULL; }
static ufunc_T *define_function(exarg_T *eap, char_u *name, garray_T *lines) { return NULL; }
static void func_ptr_unref(ufunc_T *ufunc) {}
static int generate_NEWFUNC(cctx_T *cctx, char_u *lambda, char_u *name) { return OK; }
static lvar_T *reserve_local(cctx_T *cctx, char_u *name, int len, int is_func, int type) { return NULL; }
static int generate_FUNCREF(cctx_T *cctx, ufunc_T *ufunc) { return OK; }
static int generate_STORE(cctx_T *cctx, int isn, int idx, void *ptr) { return OK; }
static void vim_free(void *ptr) { free(ptr); }
static char_u *to_name_end(char_u *p, int is_func) { return p; }
static void set_nextcmd(exarg_T *eap, char_u *p) {}
static int func_needs_compiling(ufunc_T *ufunc, compiletype_T type) { return 0; }
static int compile_def_function(ufunc_T *ufunc, int is_lambda, compiletype_T type, cctx_T *cctx) { return OK; }
static void mch_memmove(void *dest, void *src, size_t n) { memmove(dest, src, n); }
static char_u *_(const char *msg) { return (char_u *)msg; }
static void emsg(char_u *msg) {}
static void semsg(char_u *msg, ...) {}