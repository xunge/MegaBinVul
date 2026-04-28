#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    void *ga_data;
} garray_T;

typedef struct {
    int v_type;
    union {
        void *v_partial;
    } vval;
} typval_T;

typedef struct {
    int eval_flags;
    garray_T eval_ga;
    garray_T eval_freega;
    void *eval_cctx;
    int (*eval_getline)(void);
    void *eval_cookie;
    int eval_break_count;
    garray_T eval_tofree_ga;
    int eval_using_cmdline;
    void *eval_cstack;
} evalarg_T;

typedef struct {
    int cmdidx;
    int forceit;
    char_u **cmdlinep;
    int skip;
    void *getline;
    void *cookie;
    char_u *nextcmd;
} exarg_T;

typedef struct {
    int uf_flags;
    int uf_refcount;
    garray_T uf_args;
    garray_T uf_def_args;
    void *uf_func_type;
    char_u *uf_name;
    garray_T uf_lines;
    struct script_ctx {
        int sc_version;
        int sc_lnum;
    } uf_script_ctx;
    int uf_script_ctx_version;
} ufunc_T;

typedef struct {
    void *pt_func;
    int pt_refcount;
} partial_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define EVAL_EVALUATE 1
#define CMD_block 0
#define NUL '\0'
#define FC_LAMBDA (1 << 0)
#define FC_SANDBOX (1 << 1)
#define FC_VIM9 (1 << 2)
#define VAR_PARTIAL 0

static struct script_ctx current_sctx;
static int sandbox;
static int SOURCING_LNUM;
static void *func_hashtab;
static void *t_func_any;
static const char *e_trailing_characters_str = "";

#define _(x) x
#define STRLEN(s) strlen((const char *)(s))
#define UF2HIKEY(uf) ((void *)(uf))
#define ASCII_ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define ALLOC_CLEAR_ONE(type) calloc(1, sizeof(type))
#define CLEAR_FIELD(var) memset(&var, 0, sizeof(var))

static int ends_excmd2(char_u *arg, char_u *skip);
static char_u *skipwhite(char_u *p);
static void semsg(const char *msg, char_u *arg);
static void ga_init2(garray_T *gap, int itemsize, int growsize);
static int get_function_body(exarg_T *eap, garray_T *newlines, void *unused, char_u **line_to_free);
static void vim_free(char_u *p);
static int ga_grow(garray_T *gap, int n);
static int vim9_comment_start(char_u *p);
static char_u *vim_strnsave(char_u *s, size_t len);
static void *mch_memmove(void *dest, const void *src, size_t n);
static char_u *get_lambda_name(void);
static void *alloc_clear(size_t size);
static void set_ufunc_name(ufunc_T *ufunc, char_u *name);
static int hash_add(void *ht, void *key);
static void fill_exarg_from_cctx(exarg_T *eap, void *cctx);
static int parse_argument_types(ufunc_T *ufunc, garray_T *argtypes, int varargs);
static int parse_return_type(ufunc_T *ufunc, char_u *ret_type);
static void set_function_type(ufunc_T *ufunc);
static void function_using_block_scopes(ufunc_T *ufunc, void *cstack);
static void ga_clear_strings(garray_T *gap);
static void func_clear(ufunc_T *ufunc, int free_name);
static void func_free(ufunc_T *ufunc, int free_name);